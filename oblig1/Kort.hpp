#ifndef KORT_HPP
#define KORT_HPP

#include <fstream>

class Kort{
  char suit_;
  int value_;
public:
  Kort(char suit, int value);
  
  /* Get funksjoner */
  char getsuit();
  int getvalue();
  /* ToString */
  char* toString();

};

#endif
