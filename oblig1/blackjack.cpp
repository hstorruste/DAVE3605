#include "Kortstokk.hpp"
#include "Kort.hpp"
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
    cout << k.toString() << endl;
  }
  while(sum > BLACKJACK && aces > 0){ /*Setter ess til å være 1 
					om summen er over 21*/
    sum = sum - 10;
    aces--;
  }
  return sum;

}

//Returnerer true hvis hand er under 17, false hvis 17 eller mer.
bool dealerhit( vector<Kort>* hand_){
  vector<Kort> hand = *hand_;
  int sum = score(&hand);
  bool hit{false};
  if(sum < 17){
    hit = true;
  }
  return hit;
} 

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
  input = "";

  for(int i{0}; i < antSpillere; i++){
    cout << "Player" << i+1 << " name: \n";
    getline(cin, navn[i]);
    cout << "Player" << i+1 << " is named: " << navn[i] << endl << endl;
  }


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
