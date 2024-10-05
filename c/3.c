/*
- high and low voltage = 0/1 -> Machine Code 
- every program is converted to Machine code; specific to the hardware (different compiler for intel and ARM (Mac): due to different arhitecture)
- Registers are physical parts of CPU
- statically typed: explicitly define data type for variable/function. Can't change it
- entry point of many languages is the function 'main()'
- c does not have 'string'
- gcc 3.c -o my_file
- it's totally upto us to decide what combination of 1,0 represents what (A,B,C, letters etc etc). The beauty is in the eye of the beholder.
  someone said A=0110101; and it became standard

- base-10:  2130 = 2*10^3 + 1*10^2 + 3*10 + 0*10^0          [Base-10: you can only have number 0-9]
- base-8:   472 = 4*8^2 + 7*8^1 + 2*8^0  ===  3140 !!!      [Base-8: you can only have number 0-7 : 489 = not valid]
- base-2:   (binary)  9 = 1*2^3 + 0*2^2 + 0*2^1 + 1*2^0     [you can only have numbers 0-1]

- unsigned integer = positive
- signed integer (most significant bit = flag) == positive/negative  [subtraction problem: -1+1 = -2]
- ones compliment == set the sign-bit; then flip the rest of bits  [solves subtraction/addition problem]
- twos compliment == set the sign-bit; then flip the rest of bits, add one

*/


#include <stdio.h>

int num = 3;
int main(){
    int num1 = 1;
    printf("Hello World\n");
;    return 0;
}