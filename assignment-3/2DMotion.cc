#include <iostream>
#include <cmath>
#include "2DMotion.h"
using namespace std;
#define PI 3.14159265

  
  Point::Point() : x{0}, y{0} {}

  istream &operator>>(istream &inputVar, Point &pointObject){
    inputVar >> pointObject.x >> pointObject.y;
    return inputVar;
  }

  ostream &operator<<(ostream &outputVar, Point &pointObject){
    outputVar << "(" << pointObject.x << ", " << pointObject.y << ")";
    return outputVar;
  }

   int Point::quadrant(){
        if (x > 0 && y > 0) {
            return 1; 
        } else if (x < 0 && y > 0) {
            return 2;
        } else if (x < 0 && y < 0) {
            return 3;
        } else if (x > 0 && y < 0) {
            return 4;
        } else {
            return 0;
        }
    }
 

  Force::Force() : angle{0}, magnitude{0} {}

  istream &operator>>(istream &inputVar, Force &forceObject){
    inputVar >> forceObject.angle >> forceObject.magnitude;
    return inputVar;
  }

  ostream &operator<<(ostream &outputVar, Force &forceObject){
    outputVar << forceObject.angle << " degrees with magnitude of " << forceObject.magnitude;
    return outputVar;
  }
  


Point operator+(Point pointObj, Force forceObj){
  Point point2;
  float radians = forceObj.angle * (PI/180);
  float xForce = forceObj.magnitude * cos(radians);
  float yForce = forceObj.magnitude * sin(radians);
  point2.x = pointObj.x + xForce;
  point2.y = pointObj.y + yForce;
  return point2;
}

Force operator*(Force forceObject, int scalar){
  Force force2;
  force2.angle = forceObject.angle;
  force2.magnitude = forceObject.magnitude * scalar;
  return force2;
}

