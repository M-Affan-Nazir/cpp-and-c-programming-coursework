/*

- segmentation error = memory not allowed to touch
- int x,y  [declare 2 integers]
- %lu = long unassigned integer
- sizeof(y) = tells the size of the datatype
- size of a pointer variable = 8 bytes; size of integer variable = 4 bytes
- thinking of a stack; when you delete a value; only the 'pointer' moves down (remeber from Alevel). The value is untouched (since it is replaced by the new value when added
  thinking; lets say you declare a variable 'x'. The pointer moves up into the free address (it still holds the value held previosly; LETS SAY NUMBER '33' ).
  since you only 'declare', not give it a value; BY DEFAULT, X WILL HOLD THE NUMBER 33!
- * = TO the address
  & = address of
- int x;
  flag = scanf("%d", &x)  //read number; and save it to 'ADDRESS OF' x.
  scanf returns 1 if it read successfully; 0 if not. (if you want "%d" i.e. number; and it read a string; it will return 0)
  therefore; flag will have the value 1 if scanf() read successfully
- scanf() stores the value read with persistency. Therefore:
    While(1) {
        int x;
        scanf("%d",&x)              //On the first loop run; it will ask the user for input; but every loop after it will not ask for input (it already has stored an input in x; even if its wrong)
        scanf("%c", &x)             //Iterating over the characters
    }
- feof(stdin) => returns True when EOF reached
  a.exe < inputs.txt

-getchar()  => Returns one character from standard input; returns EOF if end of file
 it returns an 'integer' (ASCII representation)

*/

#include <stdio.h>


void wordCount(){
    int charAcii;
    int characters = 0;
    int words = 1;
    int lines = 0;
    int spaceAscii = 32;
    int endOfLineAscii = 10;
    while((charAcii = getchar()) != EOF){
        if (charAcii != spaceAscii && charAcii != endOfLineAscii){
            characters += 1;
        }
        if (charAcii == spaceAscii){
            words += 1;
        }
        if (charAcii == endOfLineAscii){
            lines += 1;
        }
        
    }
    printf("Characters: %d  Words: %d   Lines: %d", characters, words, lines);
}


void main(){
    int x,y;
    printf("%lu", sizeof(x));  //prints 4 (bytes)
    wordCount();
}

void times2Direct(int *p){
    int newValue = *p *2;       //takes the value at address 'p'; and multiplies by 2 
    *p = newValue;              //replaces the value AT address 'p'; to the newValue (which is twice the old one)              
}