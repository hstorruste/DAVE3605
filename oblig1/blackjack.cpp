#include "Kortstokk.hpp"
#include "Kort.hpp"
#include <iostream>

using namespace std;

int main(){

  int i{1};
  Kort k{'h',i};
  Kortstokk stokk{};
  //Må try-catch på del() funksjonen. Catche out-of-range hvis stokken er tom.

  while(!stokk.empty()){
  Kort l = stokk.del();
  cout << "Delte: " << l.getsuit() << l.getvalue() << endl;
  }
  //  Kort m = stokk.del();
  //  cout << "Delte: " << m.getsuit() << m.getvalue() << endl;
  
  //  Kort n = stokk.del();
  
  // cout << "Delte: " << n.getsuit() << n.getvalue() << endl;

  //cout << "Suksess!\n" << k.getsuit() << k.getvalue() << endl;
  
}
