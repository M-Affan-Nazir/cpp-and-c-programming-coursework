/*

- #include <iomanip>
  mapilautes input / output for you

  std::cout << std::hex << 237
  outputs to 'cout'; the 'hexadecimal representation, of 237

  std::cout << std::dec;
  std::cout << 777
  std::cout << 27
  outputs to cout, the decimal representation, of 777 and 27

-manipulation WILL REMAIN until explicitly reset

*/


#include <iostream>
#include <iomanip>

using namespace std;

void main(){

}


void manipulateOutput(){

    std::cout << std::hex << 237;
    std::cout << std::dec;
    std::cout << 777;

}