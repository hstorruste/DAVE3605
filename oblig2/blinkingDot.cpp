#include "blinkingDot.hpp"
#include <chrono>
#include <random>
//Konstruktører
blinkingDot::blinkingDot(float _x, float _y, float _r) :
  dot{_x,_y,_r}
{
  
}

blinkingDot::blinkingDot(float _x, float _y, float _r, Color c) :
  dot{_x,_y,_r,c}
{
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distrib(0,2);
    t=distrib(gen);
  
}

blinkingDot::~blinkingDot(){
}

void blinkingDot::operator++(){
  
  ++t;
  
  if(t%4 == 0){
    darken_color();
  }
  increment_position();
  if(t%3 == 0)
    draw();
}
