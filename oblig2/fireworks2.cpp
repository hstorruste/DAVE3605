#include "fireworks.hpp"
#include "rocket.hpp"
#include "BlinkingDotFactory.hpp"
#include <random>
#include <chrono>

//Konstruktør
fireworks::fireworks(const char* title, int w, int h, int _rocketcount) :
  animation_canvas(title, w, h), rocketcount{_rocketcount}
{
  unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  std::uniform_int_distribution<int> distribx(100,w-100); //random i x, men 100 fra kanten
  std::uniform_int_distribution<int> distriby(100,h-100); //random i y, men 100 fra kanten
  std::uniform_int_distribution<int> distribfuse(1,200); //fuse,
  int x;
  int y;
  int fuse;
  for(int i=0;i<rocketcount;i++){
    x=distribx(gen);
    y=distriby(gen);
    fuse=distribfuse(gen);
    AbstractDotFactory* fact = new BlinkingDotFactory{5,x,y};
    animated *r = new rocket{200,5,fuse,x,y,fact}; //Sette forskjellige rockets
    add(r);
    delete fact;
  }
}

//Destruktør
fireworks::~fireworks(){
  
}
