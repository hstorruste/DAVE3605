#include "Spiller.hpp"
#include "Kort.hpp"
#include <vector>
#include <iostream>

using namespace std;

Spiller::Spiller(string navn_, int saldo_) :
  navn{navn_}, saldo{saldo_}, hand{}
{
  cout << "Constructing player " << navn_ << endl;
}
string Spiller::getnavn(){
  return navn;
}

int Spiller::getsaldo(){
  return saldo;
}

vector<Kort*>* Spiller::gethand(){
  return &hand;
}

void Spiller::hit(Kort* kort){
  hand.push_back(kort);
}

int Spiller::updateSaldo(int belop){
  saldo += (int)belop;
  return saldo;
}

void Spiller::throwhand(){
  hand.erase(hand.begin(),hand.end());
}
