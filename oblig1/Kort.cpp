#include "Kort.hpp"
#include <string>
#include <iostream>

using namespace std;

//Kort::Kort(char suit, int value) : 
Kort::Kort(string suit, int value) : 
  suit_{suit}, value_{value}
{
  //cout << "Constructing card " << suit << value << endl;
}

//char Kort::getsuit(){
string Kort::getsuit(){
  return suit_;
} 

int Kort::getvalue(){
  return value_;
}

string Kort::toString(){
  string s{};
  switch(value_){
  case 1 :
    s+="A";
    break;
  case 11 :
    s+="J";
    break;
  case 12 :
    s+="Q";
    break;
  case 13 :
    s+="K";
    break;

  default :
    s+=to_string(value_);
  }
  s+=suit_;
  return s;
}
