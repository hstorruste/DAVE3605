#include "Kort.hpp"

#include <iostream>

using namespace std;

Kort::Kort(char suit, int value) : 
  suit_{suit}, value_{value}
{
  cout << "Constructing card " << suit << value << endl;
}

char Kort::getsuit(){
  return suit_;
} 

int Kort::getvalue(){
  return value_;
}


//får ikke til denne!!!
char* Kort::toString(){
  char* s{&suit_};
  s[1]=value_;
  // s += value_;
  return s;
}
