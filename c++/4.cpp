/*

- namespace
- int x;
  cin >> x;
  cin.fail()  : true if input fails (input a char)
  Once failed; this cin.fail 'bit' will be set to one throughout the program
- To reset the failbit: cin.ignore()
  ignores the inappropriate input; resets the bit; so you can keep reading in while loop

- cin.clear()
  clears all error flags
  use before cin.ignore()

- cout << "XYZ" <<endl;
  =
  ((cout << "XYZ") << endl)

  (((cout << "My name is: ") << variable) << endl )

- ((cin >> x) >> y) : Read into x, THEN read into y
- 

  

*/


#include <iostream>
using namespace std;

int main(){
    readSuccessfullTries();
}


int readSuccessfullTries(){
    int x;
    int inputs = 1;
    cin >> x;
    while(cin.fail() == false){  //not failing
        cin >> x;
        inputs++;
    }
    ((cout << "Total Number of Tries: ") << inputs - 1) << endl;

}

int keepReadingSuccessfullTries(){
    int x;
    int inputs = 1;
    cin >> x;
    while(x != 99){
        if(cin.fail() == false){
            cin >> x;
            inputs++;
        }
        else{
            cin.clear();
            cin.ignore();
        }
    }
    ((cout << "Total Number of Successfull Tries: ") << inputs - 1) << endl;

}