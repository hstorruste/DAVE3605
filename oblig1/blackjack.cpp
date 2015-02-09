#include "Kortstokk.hpp"
#include "Kort.hpp"
#include <iostream>

using namespace std;

int main(){

  int i{1};
  Kort k{'h',i};
  Kortstokk stokk{};
  //Må try-catch på del() funksjonen. Catche out-of-range hvis stokken er tom.
  int antall{0};
  stokk.stokk();
  while(!stokk.empty()){
  Kort l = stokk.del();
  antall++;
  cout << "Delte: " << l.toString() << endl;
  }

  int antall2{0};
  stokk.stokk();
  while(!stokk.empty()){
  Kort l = stokk.del();
  antall2++;
  cout << "Delte: " << l.toString() << endl;
  }

  cout << "Delte første gang totalt: " << antall << " kort" <<endl;
  cout << "Delte andre gang totalt: " << antall2 << " kort" <<endl;


  //  Kort m = stokk.del();
  //  cout << "Delte: " << m.getsuit() << m.getvalue() << endl;
  
  //  Kort n = stokk.del();
  
  // cout << "Delte: " << n.getsuit() << n.getvalue() << endl;

  //cout << "Suksess!\n" << k.getsuit() << k.getvalue() << endl;
  
}
