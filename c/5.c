/*

- pointers are variables, but they store memory addresses (of a single box)
- int *ptr = 2*15
  This is some random address in the memory
  Could be the OS program; could be antivirus; could be anything!
  DONT change it (because you dont know what it is). You could crash the computer
- int x =10
  int *ptr = &x  (pointer to memory address of variable 'x')
*** '&' = address of

- *ptr == GO TO THE ADDRESS (stored in ptr); AND GET ME THE VALUE
- Hexadecimal used to display Memory-Addresses [only reason hexa-decimal invented was to represent large binary into smaller form :D]
- we will follow word length of 4 bytes

- int x;
  scanf("%d", &x)
  read signed integer (from console); and store it in x (we give address of x as parameter)


*/


void main(){

int *ptr1; //pointer to integer
float *ptr2; //pointer to float
char *pt3;  //pointer to a character (type variable)

int x = 10;
ptr1 = &x;   //ptr1 = holds address of box which holds 'x'.
printf("%p",ptr1); //prints the address
printf("%d",ptr1); //prints the address; but as a 'number'. SO NOT THE ACTUAL ADDRESS,
printf("%d",*ptr1);  // access the value at the memory address (holed at ptr1, i.e. 10). This prints 10


}
