#ifndef INTSET_H_
#define INTSET_H_
#include <iostream>
class intSet {
  int *data;
  int size;
  int capacity;
 public:
  intSet(); // default constructor
  intSet(const intSet& is); // copy constructor
  intSet(intSet &&is); // move constructor
  intSet &operator=(const intSet& is); // copy assignment operator
  intSet &operator=(intSet &&is); // move assignment operator
  ~intSet();  // destructor
  intSet operator|(const intSet &other); // Set union
  intSet operator&(intSet &other); // Set intersection.
  bool operator==(intSet &other);  // Set equality.
  bool isSubset(const intSet &s);  // True if s is a subset of *this
  bool contains(int e);     // True if *this contains e
  void add(int e);          // Add e to this set.
  void remove(int e);       // Remove e from this set.
  friend std::ostream& operator<<(std::ostream& out, const intSet& is); // output operator for intSet


  //my Methods: (private methods can only be called inside member functions, not externally (set.numberInSet() not allowed since it's private))
  private:
  int indexofNumberInSet(int e);   //checks if number 
  void doubleSize();

};


#endif
