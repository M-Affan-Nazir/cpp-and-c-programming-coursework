#include "intSet.h"
#include <iostream>

intSet::intSet(){
    this->data = new int[4];
    this->size = 0;
    this->capacity = 4;
}

void intSet::add(int e){
    if( (this->size < this->capacity) && (this->indexofNumberInSet(e) == -1) ){
        //space & number not in set
        this->data[this->size] = e;
        this->size = this->size + 1;
    }
    else if( (this->size == this->capacity) && (this->indexofNumberInSet(e) == -1) ){
        //no Space BUT number not in set (needs to be added)
        this->doubleSize();
        // recursive calling, will automatically Add because there is space now
        this->add(e);
    }
}

int intSet::indexofNumberInSet(int e){
    int index = -1;
    for(int i=0; i<this->size;++i){
        if(this->data[i] == e) index = i;
    }
    return index;
}

void intSet::doubleSize(){
    //Allocating new memory-array in heap
    int* newData = new int[capacity*2];
    
    //Migrating conetents
    for(int i=0; i<this->size;++i){
        newData[i] = this->data[i];
    }

    //Deleting Old Memory-array
    delete[] this->data;
    
    //Readjusting pointer
    this->data = newData;

    //Adjusting Capacity:
    this->capacity = capacity*2;

}

void intSet::remove(int e){
    int index = this->indexofNumberInSet(e);
    if( index != -1 ){
        //number in set
        //1010123456 refers to NULL
        this->data[index] = 1010123456;
    }
}

bool intSet::isSubset(const intSet &s){
    //reference used since it simply refers to the memory address. Does'nt copy, so MUCH faster
    bool isSubset = true;
    for(int i = 0; i < s.size; ++i){
        //use s.size If 's' is an object OR reference to an object
        //use s->size IFF 's' is a Pointer to an object
        if( this->indexofNumberInSet( s.data[i] ) == -1 ){
            //number in set 's', not a part of this set;
            //therefore not a subset
            isSubset = false;
        }
    }
    return isSubset;
}

bool intSet::contains(int e){
    int index = this->indexofNumberInSet(e);
    if(index == -1){
        return false;
    }
    else{
        return true;
    }
}

std::ostream& operator<<(std::ostream& outVar, const intSet& set){
    outVar << "(";
    for(int i = 0; i<set.size; ++i){
        if(i < set.size-1){
            outVar << set.data[i];
            outVar << ", ";
        }
        else{
            outVar << set.data[i];
        }
    }
    outVar << ")";
    return outVar;
}

//An object 'a' has a copy constructor, which takes in an object 'x' as a parameter. This copy-constructor copies the entire object 'x' data inside object 'a'
//This ensure 'a' is a seperate independent Object, but has same data as 'x'
//if we were to do Object a = x; 'a' would simply point to the memory address of 'x'; thus 'a' would be the same object as 'x'!

//Copy Constructor:
intSet::intSet(const intSet& set){
    //copying variables
    this->size = set.size;
    this->capacity = set.capacity;

    //Allocation Heap memory, similar in size to 'set' memory
    this->data = new int[set.capacity];
    
    //copying data:
    //this->data = set.data   :  can not do. as set.data is a pointer to memory in heap. This way, this->data will only point to the same memory in heap! NOT A DEEP COPY!
    for(int i = 0; i<set.size; ++i){
        this->data[i] = set.data[i];
    }


}

intSet& intSet::operator=(const intSet& set){
    //Copy operator; same function as copy constructor; but uses '='
    this->size = set.size;
    this->capacity = set.capacity;
    
    delete[] this->data;  //previous data of object deleted
    this->data = new int[set.capacity];
    for(int i = 0; i<set.size; ++i){
        this->data[i] = set.data[i];
    }

    return *this;   //return reference to this object
}

intSet intSet::operator|(const intSet &other){
    intSet unionSet(*this);
    
    for(int i = 0; i<other.size;++i){
        int index = this->indexofNumberInSet(other.data[i]);
        if( index == -1 ){
            //element in UnionSet not In this->set ; so add in union
            unionSet.add(other.data[i]);
        }
    }

    return unionSet;

}

//Move constructor:
intSet::intSet(intSet &&is){
    //copying
    this->data = is.data;
    this->size = is.size;
    this->capacity = is.capacity;

    //rendering last one useless
    is.data = nullptr;
    is.size=0;
    is.capacity=0;
}

intSet& intSet::operator=(intSet &&set){
    //moving:
    this->size = set.size;
    this->capacity = set.capacity;

    delete[] this->data;
    this->data = set.data;

    //rendring Last useless:
    set.data = nullptr;
    set.size=0;
    set.capacity=0;



    return *this;
}

intSet::~intSet(){
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

bool intSet::operator==(intSet &other){
    if (this->size != other.size) {
        return false;
    }
    for (int i = 0; i < this->size; ++i) {
        if (!other.contains(this->data[i])) {
            return false;
        }
    }
    return true;
}

intSet intSet::operator&(intSet &other){
    intSet interSection;
     for (int i = 0; i < this->size; ++i) {
        if (other.contains(this->data[i])) {
            interSection.add(this->data[i]);
        }
    }

    return interSection;
}