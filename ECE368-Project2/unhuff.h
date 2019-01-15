#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ONE 1

// HuffTree Structure
typedef struct rootnode {
	char data;
	int frequency;
	struct rootnode * left;  // left sub-tree
	struct rootnode * right; // right sub-tree
} Tree;

Tree * CreateTree(char, int);;
void Decompress_Tree(char *);



int getBit(int number, int pos)
{
  int a = 0;
  int b = pos;
  a = ((number & ( ONE << b )) >> b);
  return a;
}

void Free_Tree(Tree* treeroot){
  free(treeroot);
}

void Destroy_Tree(Tree * treeroot)
{
	if (treeroot == NULL)
	{
		return;
	}
	Destroy_Tree(treeroot -> left);
	Destroy_Tree(treeroot -> right);
	Free_Tree(treeroot);
}

//Read HuffMan header from file
Tree * read_Header(FILE * fp, int *readFlag)
{	
  
	char data ;
	if (*readFlag == 1){
	  fread(&data, 1, 1, fp);
	}
	if (data == 0)
	{
		*readFlag = 0;
		return;
	}
	if (data == '1')
	{	
		char value;
		fread(&value, 1, 1, fp);
		Tree* new_tree = CreateTree(value,0);
		return new_tree;
	}
	else
	{
	        
		Tree *  left = read_Header(fp, readFlag);
		Tree *  right = read_Header(fp, readFlag);
		Tree * newnode = CreateTree(0, 0);
		newnode->right = right;
		newnode->left = left;
		return newnode;
	}
}
