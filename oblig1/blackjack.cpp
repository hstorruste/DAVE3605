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

void opprettSpillere(vector<Spiller> *spiller_){

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
  for(int i{0}; i < antSpillere; i++){
    Spiller s{navn[i],saldo[i]};
    spiller_->push_back(s);
  }

} // end of opprettSpillere

int main(){

  Kortstokk stokk{};
  
  /* Oppretter spillere */
  vector<Spiller> spiller{};
  opprettSpillere( &spiller );

  /*The game is on! Returnerer hit for ny runde*/
  while(true){  
    stokk.stokk();
    /* Satse penger */
  int belop[spiller.size()];
  string input = "";
  int i{0};
  for(vector<Spiller>::iterator it=spiller.begin();it != spiller.end(); ++it){
    Spiller s = *it;
    while(s.getsaldo() != 0){
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
    if(s.getsaldo() == 0){
      cout << s.getnavn() << " is out of money!\nExiting..." <<  endl;
      return 0;
    }else
      cout << s.getnavn() << " is betting " << belop[i] << ",-" << endl;
    i++;
  }
  
  /*Deler kort*/
  for(vector<Spiller>::iterator it=spiller.begin();it != spiller.end(); ++it){
    it->hit(stokk.del());
    it->hit(stokk.del());
  }
  
   //Dealer
  vector<Kort> dealer{};
  dealer.push_back(*stokk.del());
  dealer.push_back(*stokk.del());

  /*Spillet begynner*/
  int antSpillere = spiller.size();
  int poengsum[antSpillere];
 
  bool dealdraw = false; //Sjekk om dealer trenger å spille
  for(vector<Spiller>::iterator it=spiller.begin();it != spiller.end(); ++it){
    cout << "Dealer has: " << dealer.begin()->toString() << endl;
    
    /* Leser input HIT or STAY */
    string input = "";
    cout << it->getnavn() << " has: ";
    vector<Kort*>* hand = it->gethand();
    for(Kort* k : *hand)
      cout << k->toString();
    cout << endl;
    while(true){
      
      cout <<"Do you HIT(h) or STAY(s)? ";
      getline(cin, input);
    
      //Leser inn første char og sammenligner
      stringstream myStream(input);
      char c{'a'};
      myStream.get(c);
      if(c == 'h'){  // Tar et kort til
	it->hit(stokk.del());
	cout << it->getnavn() << " has: ";
	for(Kort* k : *hand)
	  cout << k->toString();
	cout << endl;
      }
      else if(c == 's'){
	break;
      }
      else{
	cout << "Invalid input, please try again" << endl;
      }
    }
    vector<Kort> temphand{};
    for(Kort* k : *hand)
      temphand.push_back(*k);
    poengsum[i] = score(&temphand);
    cout << it->getnavn() << " has: ";
    cout << poengsum[i] << endl;
    if(poengsum[i] == BLACKJACK && temphand.size() == 2){
       cout << "BLACKJACK!" << endl;
    }else if(poengsum[i] > BLACKJACK){
      cout << "BUST!" << endl;
    }
    else
      dealdraw = true; //Dealer må spille
    cout << endl;
    i++;
  }
  
  /*Dealer draws*/
  int sumDealer{0};
  bool dealbust = false;
  bool dealbj = false;
  if(dealdraw){
    while(dealerhit(&dealer))
      dealer.push_back(*stokk.del());

    sumDealer = score( &dealer );
    cout << "Dealer: " << sumDealer;
    if(sumDealer == BLACKJACK && dealer.size() == 2){
      cout << " BLACKJACK!";
      dealbj = true;
    }
    if(sumDealer > BLACKJACK){
      dealbust = true;
      cout << " BUST!";
    }
    cout << endl;
  }

  /*Ordner gevinst og tap*/
  i=0;
  for(vector<Spiller>::iterator it=spiller.begin();it != spiller.end(); ++it){
    cout << it->getnavn() << " ";
    vector<Kort> temphand{};
    for(Kort* k : *it->gethand())
      temphand.push_back(*k);
    poengsum[i] = score(&temphand); // spiller sin poengsum
    bool push = false;
    bool gevinst = false;
    if(poengsum[i] == BLACKJACK && it->gethand()->size() == 2){
      it->updateSaldo((belop[i]*3)/2);  //Gevinst BLACKJACK
      gevinst = true;
    }
    else if( poengsum[i] > BLACKJACK ){
      it->updateSaldo(-belop[i]);      //Tap (bust)
    }
    else if(dealbj)
	it->updateSaldo(-belop[i]);      //Tap (dealer blackjack)
    else if(dealbust){
	it->updateSaldo(belop[i]);      //Gevinst (dealer bust)
	gevinst = true;
    }
    else if(sumDealer > poengsum[i])  //Tap (dealer mer en spiller)
      it->updateSaldo(-belop[i]);      
    else if(sumDealer < poengsum[i]){    //Gevinst (spiller mer en dealer)
      it->updateSaldo(belop[i]);      
	  gevinst = true;      
    } else push = true;
    i++;
    if(push)
      cout << "PUSH!" << endl;
    else if(gevinst)
      cout << "WON!" << endl;
    else
      cout << "LOST!" << endl;
    cout << "New balance: " << it->getsaldo() << endl;
    it->throwhand();
  }
  

  while(true){
    cout << "Play again? (y/n)\n";
      getline(cin, input);
    
      //Leser inn første char og sammenligner
      stringstream myStream(input);
      char c{'a'};
      myStream.get(c);
      if(c == 'y'){  // En runde til
	break;
      }
      else if(c == 'n'){
	return 0;
      }
      else{
	cout << "Invalid input, please try again" << endl;
      }
    }
  }//End of while: The game is on!
}
