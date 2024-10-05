/*

- new = used to allocate memory in heap
  equivalent to malloc
- delete = free memory in heap
  equivalent to 'free'

- overloading a function = defining a different function THAT has different argument types/ number of arguments/ return type
  only different arugument types are allowed
  if both have same argument types (or both accept no arguments); then overloading is not allowed
  new function can have your OWN RETURN DATATYPE (i.e. struct)

  struct abc {}
  abc myFunc(){
    ...
  }

- you can overload the operators THEMSELVES (+,-.*,/)
- you can overload the 'output' operator

*/


int max(int a, int b){
    return a > b ? a : b;
}

float max(float a, float b){
    return a > b ? a : b; 
}

struct myVector{
    int x,y,z;
}

myVector operator*(myVector v, int scalar){
    myVector v2;
    v2.x = v.x*scalar;
    v2.y = v.y*scalar;
    v2.z = v.z*scalar;

    return v2;
}


int main(){

    int *p = new int;  //allocates an int in heap
    int *arr = new int[100]; //allocates array of 100 ints ON THE HEAP

    delete p;
    delete[] arr;  // free memory in heap


}