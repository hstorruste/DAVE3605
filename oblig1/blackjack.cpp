#include "Kortstokk.hpp"
#include "Kort.hpp"
#include "Spiller.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#define BLACKJACK 21

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
    //cout << k.toString() << endl;
  }
  while(sum > BLACKJACK && aces > 0){ /*Setter ess til å være 1 
					om summen er over 21*/
    sum = sum - 10;
    aces--;
  }
  return sum;
} // end of function

//Returnerer true hvis hand er under 17, false hvis 17 eller mer.
bool dealerhit( vector<Kort>* hand_){
  vector<Kort> hand = *hand_;
  int sum = score(&hand);
  bool hit{false};
  if(sum < 17){
    hit = true;
  }
  return hit;
} // end of function

int main(){

  Kortstokk stokk{};
  //Må try-catch på del() funksjonen. Catche out-of-range hvis stokken er tom.

  /*Tester at alle kort er i stokken*/
  /*int antall{0};
  stokk.stokk();
  while(!stokk.empty()){
    Kort k = stokk.del();
    antall++;
    cout << "Delte: " << k.toString() << endl;
  }
  cout << "Delte første gang totalt: " << antall << " kort" <<endl;*/
  
  stokk.stokk();
  /*Tar imot input fra bruker om antall spillere*/
  string input = "";
  int antSpillere{0};
  while(true){
    cout << "Number of players (1-5): \n";
    getline(cin, input);
    
    //Konverterer fra string til int
    stringstream myStream(input);
    if(myStream >> antSpillere)
      if(antSpillere > 0 && antSpillere < 6) //Antall må være 1-5
	break;
    
    cout << "Invalid number, please try again" << endl;
  }
  cout << "Blackjack with " << antSpillere << " players." << endl << endl;

  /*Tar imot input fra bruker om navn på spillere*/
  string navn[antSpillere];
  //input = "";

  for(int i{0}; i < antSpillere; i++){
    cout << "Player" << i+1 << " name: \n";
    getline(cin, navn[i]);
    cout << "Player" << i+1 << " is named: " << navn[i] << endl << endl;
  }

  /*Tar imot input fra bruker om saldo for spillere*/
  int saldo[antSpillere];
  input = "";

  for(int i{0}; i < antSpillere; i++){
    while(true){
      cout << navn[i] <<", how much cash do you have? (10 - 100000)\n";
      getline(cin, input);
    
      //Konverterer fra string til int
      stringstream myStream(input);
      if(myStream >> saldo[i])
	if(saldo[i] > 9 && saldo[i] <= 100000) //Saldo må være 10-100000
	  break;
    
      cout << "Invalid number, please try again" << endl;
    }
    cout << navn[i] << " has " << saldo[i] << ",-" << endl;
    
  }

  /* Oppretter spillere */
  vector<Spiller> spiller{};
  for(int i{0}; i < antSpillere; i++){
    Spiller s{navn[i],saldo[i]};
    spiller.push_back(s);
  }
  
  /* Satse penger */
  int belop[antSpillere];
  input = "";
  int i{0};
  for(vector<Spiller>::iterator it=spiller.begin();it != spiller.end(); ++it){
    Spiller s = *it;
    while(true){
      cout << s.getnavn() << ", how much do you want to bet? (1 - "
	   << s.getsaldo() << ")\n";
      getline(cin, input);
    
      //Konverterer fra string til int
      stringstream myStream(input);
      if(myStream >> belop[i])
	if(belop[i] > 0 && belop[i] <= s.getsaldo()) //Beløp må være gyldig
	  break;
    
	  cout << "Invalid number, please try again" << endl;
    }
    cout << s.getnavn() << " is betting " << belop[i] << ",-" << endl;
    i++;
  }
  
  /*Deler kort*/


  //Dealer
  int sumDealer{0};
  
  vector<Kort> dealer{};

  dealer.push_back(stokk.del());
  dealer.push_back(stokk.del());

  while(dealerhit(&dealer))
    dealer.push_back(stokk.del());

  sumDealer = score( &dealer );
  cout << "Dealer: " << sumDealer;
  if(sumDealer == BLACKJACK && dealer.size() == 2)
    cout << " BLACKJACK!";
  if(sumDealer > BLACKJACK)
    cout << " BUST!";
  cout << endl;
  
}
