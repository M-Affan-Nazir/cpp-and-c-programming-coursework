/*

- parameter's being passed into 'main()'
- use *parameterArray[]     OR      **parameterArray
- parameterArray is technically a 2Dimensional Array!
- parameterArray[1][0]  --> will give the first character of the first argument

*/

#include <stdio.h>
#include <stdlib.h>



int** identityMatrixGen(int x, int y){
    int **matrix = malloc(sizeof(int*)*y);          //a 2D Array. (matrix is a pointer - TO - other pointers)
    for(int i=0; i<y; i++){

        int *row = malloc(sizeof(int)*x);

        for (int j = 0; j<x; j++){
            *(row+j) = (j == i ? 1 : 0);  // row[j] = (j == i ? 1 : 0)
        }

        *(matrix+i) = row;  // matrix[i] = row
    }
    return matrix;
}


int main(int numOfParameters, char *parameterArray[]){   //parameterArray is an array TO/OF pointers : spiral rule
    printf("%d\n",numOfParameters);
    for(int i = 0; i < numOfParameters; i++){
        printf("%s\n",parameterArray[i]);   //parameterArray[i] = pointer to another Array. "%s" automatically goes to that address and reads memory

    }
    printf("------------------------\n");
    int **matrix = identityMatrixGen(5,5);
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<5; i++){
        free(matrix[i]);
    }
    free(matrix);
}