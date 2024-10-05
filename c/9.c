/*

- memory is allocated in 'heap' manually by the programmer
- 'malloc' used
- size.t 
- when memory allocated in heap gets free by you; 'C' does not give the memory up back to OS.
  it keeps it secured, so that down the line when you want memory in heap; it directly gives you that memory
- malloc asks OS for memory allocation. Asking the OS is slow; that is why it keeps the freed memory in heep secured.
- it is our JOB to free the memory, that was allocated using malloc
  failure to free the memory is called a 'memory leak'. A program with memory leaks , when runs for long enough; crashes.
-  /dev/null   -> a directory where you send outputs that you dont need
- once you free() a block of memory in heap; do not write to that block of memory again; it does not belong to you
  *p = malloc(sizeof(int)*10)
  free(p)
  p = 123   !
- best practise is to assign the freed pointer to NULL
- when need more allocated memory (lets say you have array of size 10; now you need of size 15); allocated a new array, and move/copy contents to the new array!
  BUT, do not allocate new array of size 15; (though memory efficent; its time in efficent). Allocate a larger size (in case needed next time).
  DOUBLE THE SIZE OF ARRAY
- use malloc for making an array from 'function parameter'
- memory allocated in heap will exist FOREVER until explictly freed
- heap memory is much LARGER than stack
- 

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main(){

    int *p = malloc(sizeof(int)*1); // allocate enough bytes for 1 integer [this will be used to store a memory address; a pointer]
    int *array = malloc(sizeof(int)*10);  //allocate enough bytes (on heap) to store 10 integers

    free(p);  //freeing allocated memory
    free(array);
    p = NULL;
    array=NULL;

  returnARray(256);
    
}

void makeArrayFromParameter(int n){
  
  int *arr = malloc(sizeof(int)*n);    //array for 'n' integers
  int *arr2[n];    //WRONG!!! This is 'variable sized array'. DO NOT DO THIS, USE MALLOC.


}