#include "tintedDot.hpp"
#include <chrono>
#include <random>
/**Initialize the dot and randomly set a tint (1 out of 7) of the initial color*/
tintedDot::tintedDot(float _x,float _y, float _r, Color c) :
  dot{_x, _y, _r, c}
{
  unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  std::uniform_int_distribution<int> distrib(1,7);
  int fade=distrib(gen);
  //If fade is 1-3: make it darker
  while(fade < 4){
    darken_color();
    ++fade;
  }
  //If fade is 5-7: make it lighter
  while(fade > 4){
    lighten_color();
    --fade;
  }
}

tintedDot::~tintedDot(){

}
