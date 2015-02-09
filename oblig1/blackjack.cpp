#include "Kortstokk.hpp"
#include "Kort.hpp"
#include <iostream>
#include <vector>

using namespace std;

int score( vector<Kort>* hand_){
  vector<Kort> hand = *hand_;
  //Regner sammen poeng på en hånd
  int sum{0};
  int aces{0}; //Antall ess
  for(Kort k : hand){
    int temp = k.getvalue();
    if(temp == 1){  // Sjekker om det er et ess
      aces++;
      temp = 11;
    }
    else if(temp > 10)  //Setter verdi til 10 om det er bildekort
      temp = 10;
    sum += temp;
    cout << k.toString() << endl;
  }
  while(sum > 21 && aces > 0){ //Setter ess til å være 1 om summen er over 21
    sum = sum - 10;
    aces--;
  }
  return sum;

}

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
  /*while(!stokk.empty()){
  Kort l = stokk.del();
  antall2++;
  cout << "Delte: " << l.toString() << endl;
  }*/

  cout << "Delte første gang totalt: " << antall << " kort" <<endl;
  //cout << "Delte andre gang totalt: " << antall2 << " kort" <<endl;
  vector<Kort> hand{};
  Kort m = stokk.del();
  hand.push_back(m);
  hand.push_back(stokk.del());
  antall2 = score( &hand );
  cout << "Sum på hånd: " << antall2 << endl;

  //  Kort m = stokk.del();
  //  cout << "Delte: " << m.getsuit() << m.getvalue() << endl;
  
  //  Kort n = stokk.del();
  
  // cout << "Delte: " << n.getsuit() << n.getvalue() << endl;

  //cout << "Suksess!\n" << k.getsuit() << k.getvalue() << endl;
  
}
