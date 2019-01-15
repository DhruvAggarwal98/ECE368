#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
long* Load_File(char *Filename, int *Size){
	FILE* fp= fopen(Filename, "r");
	int i = 0;
	if(fp == NULL)
	{
		return NULL;
	}
	fscanf(fp,"%d",Size);
	long* array=malloc(sizeof(long)*(*Size));

	for (i = 0;i<*Size; i++){
		fscanf(fp,"%li",&array[i]);
	}
	fclose(fp);
	return array;
}

int Save_File(char *Filename, long *Array, int Size){
	int count = 0;
	FILE* fp= fopen(Filename, "w+");
	if(fp == NULL){
		return EXIT_FAILURE;
	}
	fprintf(fp,"%d\n",Size);
	int i = 0;
	int j=0;

	for(i = 0; i < Size; i++){
		fprintf(fp,"%li\n",Array[i]);
	}
	fseek (fp , 0 , SEEK_SET);

	for (i = 0;i<Size+1; i++){
		j= fscanf(fp,"%li",&Array[i]);
		if(j==1){
			count++;
		}
	}
	fclose(fp);
	return count - 1;
}


int* Seq1(int n, int *count){
	int *array = malloc(sizeof(int)*n);
	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;
	int i = 1;
	array[0] = 1;
	(*count)+=1;
	for(i = 1; i< n; i++){
		if(array[x]*2 == array[i-1]){
			x+=1;

		}
		if(array[y]*3 == array[i-1]){
			y+=1;
		}
		a = array[x] * 2;
		b = array[y] * 3;
		if(a < b){
			if(a < n){

				x+=1;

				array[i] = a;
			}
			else{
				return array;
			}
		}

		else{
			if(b<n){
				y += 1;
				array[i] = b;
			}
			else{
				return array;
			}
		}
		(*count)++;

	}
	return array;

}

int* Seq2(int N, int* count){
	int *array=malloc(sizeof(int)*N);
	int i=0;
	array[0] = N/1.3;
	while(array[i] >= 1)
	{
		i++;
		array[i] = array[i-1]/1.3;
		if(array[i] == 9| array[i] == 10){
			array[i] = 11;
		}
		(*count)++;

	}
	return array;
}

void Save_Seq1(char *Filename, int n){
	int count = 0;
	int *array = Seq1(n, &count);
	FILE* fp = fopen(Filename, "w");
	int i = count;
	if(fp == NULL){
		return;
	}
	for(i = count-1;i>=0;i--){
		fprintf(fp,"%d\n",array[i]);
	}
	fclose(fp);
	free(array);
	return;
}

void Save_Seq2(char *Filename, int n){
	int count = 0;
	int* array = Seq2(n,&count);
	int i = 0;
	FILE* fp = fopen(Filename, "w");
	if(fp == NULL){
		return;
	}
	for(i = 0; i < count; i++){
		fprintf(fp, "%d\n", array[i]);
	}
	fclose(fp);
	free(array);
	return;
}

void Shell_Insertion_Sort(long *Array, int Size, double *NComp, double *NMove){
	*NComp = 0;
	*NMove = 0;
	int i = 0;
	int count = 0;
	int* new_array = Seq1(Size, &count);
	int k=0;
	int j =0;
	int h = 0;
	for(h=Size;h>=0;--h){
		k=new_array[h];
		for(j=k;j<Size;j++){
			int temp=Array[j];
			*NMove += 1;
			i=j;
			if(i>=k){
				*NComp += 1;
			}
			while((i>=k)&&(Array[i-k]>temp)){

				Array[i]=Array[i-k];
				*NMove += 1;
				i=i-k;
			}
			Array[i] = temp;
			*NMove += 2;
		}
	}
	free(new_array);
	return;
}

void Improved_Bubble_Sort(long *Array, int Size, double *NComp, double *NMove){
	*NComp = 0;
	*NMove = 0;
	int i = 0;
	int count = 0;
	int* new_array = Seq2(Size, &count);
	int k=0;
	int j =0;
	int h = 0;
	for(h=count;h>=0;--h){
		k=new_array[h];
		for(j=k;j<Size;j++){
			int temp=Array[j];
			*NMove += 3;
			*NComp += 1;
			i=j;
			if(i>=k){
				*NComp += 1;
			}
			while((i>=k)&&(Array[i-k]>temp)){
				temp = Array[i];
				Array[i]=Array[i-k];

				Array[i-k] = temp;
				i=i-k;
			}

		}
	}
	free(new_array);	
	return;
}
