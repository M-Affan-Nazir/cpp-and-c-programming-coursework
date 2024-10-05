/*

- Struct and their constrictors
- member initializaion
- int x{2};      ->   int x = 2;
- MIL initialization is much FASTER for program execution. 
  It tells compiler to assign data from parameter somehow directly (at stage 2)

*/


struct rect{
    int x, y, w, h;
    rect(int x, int y, int w, int h){   //connstructor function; has to have same name as the struct
        this->x = x;
        this->y= y;
        this->w=w,
        this->h = h;  //this->h = 'h' of struct (defined on top)

    }
    rect(){ //overloading constructor
        this->x = 1;
        this->y = 1;
        this->w = 1;
        this->h = 1;

        //since this constructor does not have arguments x,y,w,h; you can simply say x=1, y=1 ...

    }
    int area(){
        return w*h;
    }
};


struct Student{

    int courseCount;
    int gpa;
    const int sID;

    // Student(int courseCount, float gpa, int sID){
    //     this->courseCount = courseCount;
    //     this->gpa = gpa;
    //     this->sID = sID;   // cant change const! Thus, we use MIL
    // }

    Student(int courseCount, float gpa, int sID): courseCount{courseCount}, gpa{gpa}, sID{sID}{     //MIL; member initialization List
    }
};


int main(){

    int x{2};   //int x = 2;

}