/*

- switch-case
- template functions (function can be used with any data type)
- template classes
- for template classes/functions; the code HAS to be in header file. It can not be in the implementation file.

*/

#include <iostream>
using namespace std;



#include <iostream>
using namespace std;



struct Vec2D {
  int x, y;
  Vec2D operator*(int c) {
    return Vec2D{x*c, y*c};
  }
  
};

Vec2D operator*(int c, Vec2D v) {
  return v*c;
}

ostream &operator<<(ostream &out, const Vec2D &v) {
  return out << "[" << v.x << ", " << v.y << "]";
}

template <typename T, typename P> //defining type

//This function decides HOW to multiply. If x,y simple integers; it simply multiplies.
//If x is vector, "THEN" it calls overloaded-multiplication function in class Vector
void multiply(T x, P y) {  //type of x,y will be defined during execution!
  cout << x*y << endl;
}



//Class
template <typename myType>
class Box{

    public:
    myType x;
    void setItem(myType input){
        x = input;
    }

};



int main(){
    int val = 0;
    switch(val){
        case 1:
        cout << "Its 1" <<  endl;
        break;

        case 2:
        cout << "Its 2" <<  endl;
        break;

        case 3:
        cout << "Its 3" <<  endl;
        break;
    }
    return 1;



    int x = 5;
    float z = 2.2;
    multiply(x, z); //multiply 2 numbers
    multiply(x, 20);

    Vec2D a{3,7}; //multiply vector AND number
    multiply(a, 5); // Using the operator* defined inside the struct
    multiply(3, a); // Using the operator* defined outside the struct


    Box<int> intBox;
    intBox.setItem(33);

    Box<float> floatBox;
    floatBox.setItem(33.777);

    Box<std::string> stringBox;
    stringBox.setItem("Hello World");

    //The amount of power tempplate bring to code. One class for all types!
    //You may then overload operator/functions INSIDE the class to FURTHER adjust for all types.
    //Small, complex, high performant code : because it takes care of all types!

}
