#include "Kortstokk.hpp"
#include "Kort.hpp"
#include <vector>
#include <iostream>

using namespace std;

static int nr{0};

Kortstokk::Kortstokk() :
  stokken{}, kastet{}
{
  Kort k{'h',(int)1};
  Kort l{'h',(int)2};
  
  stokken.push_back(k);
  stokken.push_back(l);

  for(auto k : stokken)
    cout << "Laget kort: " << k.getsuit() << k.getvalue() << endl;
  
}
bool Kortstokk::empty(){
  return stokken.empty();
}

void Kortstokk::stokk(){}

Kort Kortstokk::del(){
  /*Skulle ha en sikkerhet at stokken ikke er tom. nullptr virker ikke.
    Kan ikke dereference nullpointer*/
  /* Returns a nullpointer if empty */
  /*if(stokken.empty()){
    Kort* p =0;                //nullptr
    
    return *p;
    }*/
  Kort ut = stokken.at(stokken.size()-1);
  kastet.push_back(ut);
  stokken.pop_back();
  return ut;
}
