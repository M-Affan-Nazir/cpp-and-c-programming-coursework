/*

- C has no classes / objects. I simply has structs
- C will not copy the pointer to a structure (when passed through a function) [unlike arrays; whereby function ONLY receieves a pointer]
  C will 'copy' the entire structure  (making a totally new entity in memory)
- Therefore, if you need to make a change to the actualy structure: Pass it as a pointer
- BUT BUT BUT
  since C literally 'copies' the entire structure ; it is not useful to access the structure using Pointer notation [you will pass the structure variable as pointer to function; you just wont access it using *r] (as it copies the structure).
  CREATOR'S OF C knew this was an issue; therefore they made the arrow operator '->'; indicating something is a structure
  (*r).x  == r->x

*/

#include <stdio.h>



struct Rectangle{
        int x;
        int y;
        int height;
        int width;
};

void printRectangle(struct Rectangle r){
    printf("x: %d, y: %d, height:%d, width:%d", r.x, r.y,r.height,r.width);
}

void translate(struct Rectangle *r, int xDelta, int yDelta){
    (*r).x += xDelta;           // (*r) = go to the pointer AND THEN (*r).x 'get the x attribute'
    (*r).y += yDelta;
    //OR:
    r->x += xDelta;
    r->y += yDelta;
}

void main(){


}