#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unhuff.h"
#define LENGTH 256
#define ONE 1

//Create a new, properly intialized HuffNode
Tree * CreateTree(char data, int frequency)
{
	Tree * root = malloc(sizeof(root));
	root -> data = data;
	root -> frequency = frequency;
	root -> right = NULL;
	root -> left = NULL;
	return root ;
}

void Decompress_Tree(char * input)
{
        
	char a;
	int c = strlen(input);
	char newfilename[c+9];
	//printf("%d",c);
	strcpy(newfilename, input);
	strcat(newfilename,".unhuff");
	//char* b = ("%s.unhuff",input);
	FILE * fp = fopen(input, "rb");
	if(fp ==  NULL)
	{
	     return;
	}
	FILE * gp = fopen(newfilename, "wb");
	if(gp == NULL){
	  return;
	}
	int flags = 1;
	Tree * temptree = read_Header(fp, &flags);
	Tree * node = temptree;
	while(flags != 0)
	{
		fread(&a, ONE, ONE, fp);
		int b=0;
		b=a;
		if (b > 0){
		  return;
		}
		if(b<0){
		  b = b + LENGTH;
		}
		int counter1 = 0;
		while(counter1 <= 7)		 
		{
		  if(getBit(b, (7 - counter1)) == ONE){
		    node = node->right;
		  }
		  else if (node->left != NULL){
		    node = node->left;
		  }
		  if(node->left == NULL && node->right == NULL && node != NULL){
				char newn = (node->data);
				if (newn == (LENGTH-1) || (newn == -1)){
					flags = 0;
					break;
				}
				fwrite(&newn, ONE, ONE, gp);
				node = temptree;
		  }
		  counter1++;

		}
	}
	
	Destroy_Tree(temptree);
	fclose(gp);
	fclose(fp);
}


// Main function to call Decompress Function
int main(int argc, char**argv)
{
	if (argc != 2)	
	{
	  
	  return EXIT_FAILURE;
	}

	//char* a = ("%s.unhuff",argv[1]);
	Decompress_Tree(argv[1]);
	return 0;
	
}
