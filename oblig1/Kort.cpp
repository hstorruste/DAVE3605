#include "Kort.hpp"
#include <string>
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

string Kort::toString(){
  string s{suit_+to_string(value_)};
  return s;
}
