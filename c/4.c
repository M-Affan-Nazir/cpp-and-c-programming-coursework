/*

- default integer in c ate signed (32 bit twos' complement)
- characters are just numbers (A = 65). Encoding used to map number to characters is ASCII
- print("%x"):
    %c = characters
    %d = signed integer
    %u = unsigned integer
    %f = float
- There is no Boolean type in C (you can use True = 1, False = 0)
- && = and
  || = or
  ! = not

- i++ : increments, but returns the value 'before' being increment 
  ++i : increments, but returns the value 'after' being incremeneted (i.e. incremented value)
  for (i = 0;i<10;i++){
    print(i)
  } -------------------> [0,1,2,3,4,5,6,7,8,9]

  for (i = 0;i<10;++i){
    print(i)
  } -------------------> [1,2,3,4,5,6,7,8,9,10]

  i++:
        temp = i
        i = i+1
        return temp
  ++i:
        i = i+1
        return i
  i++ wastes 32 bits to store a variable 'temp'!

- Memory = RAM : It is simply a bunch of boxes; where each box stores 1 charge (1 bit)!
  Each box has an address (first address = 0).
  We can access RAM data byte by byte (box by box); but usually we don't (way too many access request's)
  We usually access data in 'words'. Word = a certain number of boxes (accessed together). Each Memory archetecture has defined 'word length' (number of boxe's accessed returned each request)
- Actual address of the RAM are hidden from programs. Programs are given virtual addresses.
- Each program has the following Memory Segments:
    text: where program code is stored is stored
    heap: stores data (whose lifetime is declared by programmer) [not known at compile time => Input of user]
    stack: stores data whode lifetime is tied to their enclosing scope (data is known at compile time ==> value of variables [maximumExamMarks = 60, passingMarks = 25])

*/

#include <stdio.h>
int binary[32];
int count = 32;
void print_binary(unsigned int x){
    int remainder = x % 2;
    unsigned int newNumber = x / 2;
    binary[count] = remainder;
    count -= 1;
    if (newNumber != 0){
        print_binary(newNumber);
    }
}

void main(){

    int x; //signed 32 bit int
    signed int y; //signed 32bit int
    unsigned int z; //unsigned 32 bit int

    char c1 = 'H';   //*** use single quotes
    char c2 = 101;  // 'e'
    char c3 = c1+36; // 'l'
    char c4 = 'z' - 11 ; // 'o'

    printf("%c%c%c%c%c\n", c1,c2,c3,c3,c4) ; 

    if(c1 == 'H'){
        printf("It's H\n");
    }

    while(c1 == 'A'){
        printf("C1 in While loop\n");
    }

    for(int i =0; i<2; i++){
        printf("%d\n",i);
    }

    printf("--------- -----------\n");

    print_binary(159);
    for(int i = 0; i<=32; i++){
        printf("%d",binary[i]);
    }
}

