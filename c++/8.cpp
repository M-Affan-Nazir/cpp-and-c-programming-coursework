/*

- C++ has another type called 'Reference Type'
  int &y = x
- int &y;   //not allowed; cannot leave reference empty
- references may not have a memeory address;
  therefore you can not have a pointer to a reference
-  you can NOT have a reference array
    int x,y,x;
    int &arr[] = {x,y,z}    : not alloaws

- You can, however , have a refernce TO a pointer
 int *p = &x;   //this pointer, stores the address of x. Pointer points to 'x'
 int* &pr = p;  

-REFERNCES ARE NOT POINTERS
- void myFunc(const int &y){
    now, you can access the content of 'y'; but cant change it
}

- like pointers, never return a refernce to a pointer which limited to the scope of the function

- use pointer's when mutating/accessing heap memory;
  use referencing when accessing/mutating stack memory

- 

*/

#include <iostream>
using namespace std;

void times2(int &n){
    n = n*2;
}

void newTimes2(const int &n){
}

int main(){

    int x = 10;
    int &y = x;    //refernce to int 'y' IS ACTUALLY a reference of x
    y = 10;               //any operation applied to y, behaves as if it were appleid to x.

    times2(x);    //function will mutate x, 10 --> 20
                  // similar to passing it as a pointer

    times2(5);     //will not work! You need to pass a variable

    newTimes2(5); //this will work, because the function knows that even though the parameter is a reference; it is a const! You will not mutate the content of it. I mean, cant mutate '5' right? Its not a variable

}
