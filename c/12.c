/*

- We can not return 2 values by a function in C
- We can make a heap (malloc) array containing 2 values; and return the pointer to this array
  OR
- We can pass 2 pointers to the function as parameters
  These pointers are passed by the function-caller. They are 2 memory address to the caller's stack !
  We can directly write the data to these memory addresses!
- Error handling in C is a nightmare
  it is mostly done either by the function returning an error code (like if it was unsuccessfull; we return -1); 
  OR
  it is done by just having a dumb global variable (kep only for error flags). If an error is encountered; you can simply write something to this variable



NOTE:
- *array = *newArray;
  here you were only changing the first element of 'array' to equal the first element of 'newArray'
  What you THOUGHT were acheieving was updating the pointer to 'array' to 'newArray'. 
  Nope !!!

 you need the function 'pushArray' to accept **array (rather than *array)
 *array means 'the variable array is a pointer data type (array); 
 **array means 'the variable array is a pointer data type (array) AND I need the pointer TO THIS variable itself'!


*** - Now accessing 'array' inside 'pushArray':
   (*array)[i]  
   OR
   *( (*array) + i )
  
  Because; 'array' is a pointer TO the pointer that has the first element of array
  Thus to access the elements you: (*array) = gives the address of the first element of the array; AND then you iterate at conseqitive elements using [i]
 
  OR:
  (*array) = gives the 'address' of the first element of the array
  (*array) + i   = pointer arthmetic ; iterating conseqitive blocks of memory
  *( (*array) + i )    =   getting element AT that conseqitive blocks of memory


  
  Before:
  ~ array was the address of the first element
    so  we (array + i) to go to next address
    *(array + i) to get element at that address

  ~ now array is the address OF the Pointer; that points to the first element

*/

#include <stdio.h>
#include <stdlib.h>

void maxNumber(int *array, int length, int *memoryAddressForIndex, int *memoryAddressForMaxNumber){
    int maxSoFar = array[0];
    int maxIndex = 0;
    for(int i = 0; i<length;i++){
        if(array[i] > maxSoFar){
            maxSoFar = array[i];
            maxIndex = i;
        }
    }
    *memoryAddressForIndex = maxIndex;
    *memoryAddressForMaxNumber = maxSoFar;
}



void pushArray(int **array, size_t *currentLength, size_t *maxLength, int value){

    if(*currentLength == *maxLength){
        *maxLength = (*maxLength)*2;
        int *newArray = malloc((*maxLength)*sizeof(int));
        for(int i =0; i<*currentLength; i++){
            newArray[i] = (*array)[i];
        }
        newArray[*currentLength]=value;
        *currentLength = *currentLength+1;
        free(*array);
        *array = newArray;  //updating pointer
        for(int i=0;i<*currentLength;i++){
            printf("%d ",  (*array)[i]  );         //This is how you access the array. not array[i] !!!!!
        }


    }
    else{
        //simply append to array
        //will implement solution later
    }

}

void main(){
    int array[] = {1,2,3,4,5,6,7,8,9,11,34,5,2,2,2};
    int length = sizeof(array)/sizeof(int);

    int maxNumberX;
    int indexOfMaxNumber;

    maxNumber(array,length,&indexOfMaxNumber,&maxNumberX);   //& = the address of 
    printf("%d  %d\n", maxNumberX, indexOfMaxNumber);




    printf("--------------------------------------------\n");
    int *array2 = malloc(sizeof(int)*3);    //cant declare array like xyz[] for array; Therefore use pointer method!
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 3;
    
    int maxLength = 3;
    int currentLength = 3;
    int value = 27;

    pushArray(&array2,&currentLength, &maxLength, value);

    printf("\n-------------------------------\n");
    printf("Printing In Main:  \n");
     
    for(int i=0;i<currentLength;i++){
        printf("%d ",  array2[i]  );         //This is how you access the array. not array[i] !!!!!
    }

}