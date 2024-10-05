#ifndef MOTION2D
#define MOTION2D
#define PI 3.14159265
#include <iostream>

class Force;
class Point;

class Point {
  private:

  public:
  float x;
  float y;
  Point();

  friend std::istream &operator>>(std::istream &inputVar, Point &pointObject); 

  friend std::ostream &operator<<(std::ostream &outputVar, Point &pointObject);

  int quadrant();

};

class Force {
  private:
  
  public:
  float angle;
  float magnitude;

  Force();

  friend std::istream &operator>>(std::istream &inputVar, Force &forceObject);

  friend std::ostream &operator<<(std::ostream &outputVar, Force &forceObject);
  
};


Point operator+(Point pointObj, Force forceObj);

Force operator*(Force forceObject, int scalar);


#endif



/*
friend functions are NOT member functions (unlike quadrant())
These are less elite, lower in hierarchy.
However, they do have access to private and public attributes.
For this reason, in implmentation file; you dont have to write Point:: with them! They are not 'literal' members!

*/