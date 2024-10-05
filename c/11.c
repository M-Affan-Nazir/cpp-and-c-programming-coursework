/*

- 2D Matrix with a 1D array
- making a 2D array with a array of pointers is highly INEFFICENT
  The concept of cache comes in. Cache stores recent/mostly used memory addresses. 
  Using an array of Pointers; the cache has to constantly update the memory-addresses it stores (maybe it stored an address to the main array (that had pointers to OTHER arrays; 2D). Now; when access the array pointed by the element in the main array; cache HAS to update its value to the new pointer). This is highly inefficent and slow
  Not somthing you will be worried on day to day basis; unless making something highly speed efficent
  If you make a 1D array (for representing the matrix); the cache has to store only the address to ONE ARRAY (the main one). Thus, no need to get new memory address from RAM by the cache; thus high speed

*/


#include <stdio.h>

int *identity_matrix_1d(int x, int y){
    int *matrix = malloc(sizeof(int)*x*y);
    for(int i = 0; i<y; i++){
        for(int j = 0; j<y;j++){
            matrix[i*x+j] = ( (i = j) ? 1:0);
        }
    }
    return matrix;
}

void main(){
    int *matrix = identity_matrix_1d(5,5);
}