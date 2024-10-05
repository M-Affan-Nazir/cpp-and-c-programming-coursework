/*

- sizeof(array) --> gives size of array in bytes
- when array is passed as argument; only the 'ponter' to the first element is passed ! It does not copy the entire array (into a new variable argument!)/
  This is called array decay : entire array 'decays' into simply a pointer to first element
- pointer * and array [] eventually becone the same data type when used as function parameters.
  That is why; even though array is passed as pointer in 'printArray'; you can still access it using indexes.
- HOWEVER; if you were to iterate using sizeof(array); since array is only a pointer it will have only 8 bytes. You will only access first 2 elements (1 element= 4 bytes; since integer)
- *(array + i) ==> Pointer arthmetic (adds i to pointer; AND return/gets the value)
   (array + i) ==> Add's 'i' to pointer; and then returns the array itself.
- array[i] = *(array + i)     (array index is pointer indexing)!

- << 'BIT SHIFT OPERATOR: SHIFT TO LEFT'
    [10]    0000 1010 << 1    [shift left by one]
    [20]    0001 0100

    <Shifting left by 1 == muktiply number by 2>

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

- int, char, array, pointers, float; That is it. In C these are the only data types
- string are simply 'a series of characters'
- char myS[] = "This is a string";        --> stores characters in series (on stack). Thus characters linked to each other by a virtual 'string'!

- Spiral Rule:
  int const * varName   -- varname -> is a pointer -> to a constant -> of type int
   


*/

#include <stdio.h>

void printArray(int *array,unsigned int size){
    for(unsigned int i = 0; i<size;++i){
        printf("%d\n",array[i]);
    }
}

void printArray2(int *array, unsigned int size){
    for(unsigned int i = 0; i<size;++i){
        printf("Array Content : %d | Array Element Address: %p \n",*(array+i), (array+i));   //pointer arthmetic You simply advance the pointer itself; accessing the next element of the array. This is 'dereferncing'
    }
}

void argmax(int *array, unsigned int length){
    signed int highest = -9999;
    unsigned int highestIndex = 0;
    for(unsigned int i = 0; i<length; i++){
        if( *(array + i) > highest){
            highest = *(array + i);
            highestIndex = i;
        }
    }
    printf("Maximum Number: %d  |  Max Number's address: %d", highest, highestIndex);
}

void replace(int *array, signed int target, signed int replace, unsigned int length){
    for(unsigned int i = 0; i<length; i++){
        if( *(array + i) == target){
            *(array + i) = replace;
        }
    }
    printArray2(array,length);
}

void main(){
    int array[] = {1,2,3,4,5,7,5,3,2,1,0};
    int length = sizeof(array)/sizeof(array[0]);   //total bytes / byte of 1 element (to get size)
    printf("%d\n",length);
    printf("\n-----------\n");
    printArray2(array,length);
    printf("\n-----------\n");
    argmax(array,length);
    printf("\n-----------\n");
    replace(array,1,69,length);

    char myS[] = "String on stack";   // mutable
    char *p = "Not on stack" ;         // not mutable - read only.
    const int x = 10;

}

