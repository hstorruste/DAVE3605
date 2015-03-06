#ifndef KORT_HPP
#define KORT_HPP

#include <fstream>

class Kort{
  //char suit_;
  std::string suit_;
  int value_;
public:
  //Kort(char suit, int value);
  Kort(std::string suit, int value);
  
  /* Get funksjoner */
  //char getsuit();
  std::string getsuit();
  int getvalue();
  /* ToString */
  std::string toString();

};

#endif
