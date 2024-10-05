#include <vector>
#include <iostream>
#include <algorithm>  //collection of algorithms, like sort


int main(){
   std::vector<int> v{1,2,3,4,5,6,7,8,9};

   for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }

    for(int i =0; i<10; ++i){
        int x;
        std::cin >> x;
        v.emplace_back(x); //add's element at end of vector

    }

    auto b = v.begin() //'iterator' to first element (acts like a pointer)
    auto e = v.end() //'iterator' to last element
    cout << *b << endl;  //deferenecing like a pointer

    ++b; //increment the iterator (pointer)
    cout << *b << endl;  //2ne element

    int x = std::accumulate(v.begin(),v.end(), 0) //summing 
    int x = std::accumulate(v.begin(),v.end(), 1, std::multiplies<int>()) //multiplying -> last = custom operator
    //last parameter is the initial value to start with. 
    //if in the case of multiplication we set the 3rd param as 0:
    //it will be 0*1*2*3*4*5.... ; thus the answer=0 (useless)
    //in case of addition, it will be 0+1+2+3+4+5..... (adding zero has no effect, but 'accumulate' NEEDS a 3rd parameter. so we have to specify it)

    return 1;
}