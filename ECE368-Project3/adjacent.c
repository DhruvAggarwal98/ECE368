#include <stdio.h>
#include <stdlib.h>
#include "adjacent.h"
/*void adjacent(FILE* fp){
        int nodes = 0;
        int edges = 0;
        int counter = 0;
        int x = 0;
        int y = 0;
        int node = 0;
        int i = 0;        
        int new_nodes = 0;
        int new_edges = 0;
        int j = 0;
        int k = 0;

        
        fscanf(fp,"%d" "%d\n", &nodes, &edges);//read the first line and store it in nodes/edges
        
        for(counter = 0; counter < nodes; counter++){ //iterate through it nodes amount of times and store the coordinates
                fscanf(fp, "%d" "%d" "%d\n", &node, &x, &y);
                
        }
        
        int **arr = (int **)calloc(nodes,sizeof(int*));//allocate a 2d array for Nodes*Nodes
        for(i = 0; i< nodes;i++){
                arr[i] = calloc(nodes,sizeof(int));
        }
        
        counter = 0;
        for(counter = 0; counter < edges; counter ++){//for everytime you go through the input file and find a node change the matrix to hold a value of 1
                fscanf(fp, "%d" "%d\n", &new_nodes, &new_edges);
                arr[new_nodes][new_edges] = 1;
                arr[new_edges][new_nodes] = 1;
        }
        
        for(j=0; j< nodes;j++){//to print a matrix of adjacent nodes go through the loop and everytime a matrix place is 1, print it
                printf("%d: ", j);
                for(k = 0; k<nodes; k++){
                        if(arr[j][k] == 1){
                                printf("%d ", k);
                        }
                }
                printf("\n");
        }

        for(i = 0; i < nodes; i++){//free array
                free(arr[i]);
        }
        free(arr);
}
*/



int main(int argc, char* argv[]){
        if(argc != 3){
                printf("Error");
        }
        FILE* fp = fopen(argv[1],"r");
        FILE* gp = fopen(argv[2],"r");
        if(fp == NULL){
            printf("Wrong File Name");
            return EXIT_SUCCESS;
        }
        if(gp == NULL){
            printf("Wrong File Name");
            return EXIT_SUCCESS;
        }
        long nodes;
        long edges;
        long i;
        long j;
        long counter;
    
        fscanf(fp,"%ld" "%ld\n", &nodes, &edges);//read the first line and store it in nodes/edges
        Point* points = malloc(sizeof(*points)*nodes);
        make_points(fp, points, nodes);

        long * matrix = malloc(sizeof(*matrix) * nodes * nodes);
        make_edges(fp, matrix, edges, nodes);

        
        for(i=0; i< nodes;i++){//to print a matrix of adjacent nodes go through the loop and everytime a matrix place is 1, print it
                printf("%ld: ", i);
                for(j = 0; j<nodes; j++){
                        counter = i * nodes + j;
                        if(matrix[counter] == 1){
                                printf("%ld ", j);
                        }
                }
                printf("\n");
        }


        fclose(fp); 
        fclose(gp);
        free(points);
        free(matrix);

        return EXIT_SUCCESS;
}
