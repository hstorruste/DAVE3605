#include "Kortstokk.hpp"
#include "Kort.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#define antKort 52

using namespace std;

static int nr{0};

static char suits[4]{'s','h','d','c'};

Kortstokk::Kortstokk() :
  stokken{}, kastet{}
{
  /*Konstruerer en kortstokk med 52 kort*/
  for(int j{0}; j < sizeof(suits); j++) 
    for(int i{0}; i < 13; i++){
      Kort k{suits[j], i+1};
      stokken.push_back(k);
    }
}

bool Kortstokk::empty(){
  return stokken.empty();
}

void Kortstokk::stokk(){
  // seed til generator
  std::mt19937 generator(time(0));

  // Legger tilbake brukte kort.
  while(!kastet.empty()){
    Kort k = kastet.at(kastet.size()-1);
    stokken.push_back(k);
    kastet.pop_back();
  }

  shuffle(stokken.begin(),stokken.end(),generator);
}

Kort* Kortstokk::del(){
  /*Skulle ha en sikkerhet at stokken ikke er tom. nullptr virker ikke.
    Kan ikke dereference nullpointer*/
  
  
  Kort* ut = &stokken.at(stokken.size()-1);
  kastet.push_back(*ut);
  stokken.pop_back();
  return ut;
}
