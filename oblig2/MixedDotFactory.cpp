#include "MixedDotFactory.hpp"
#include "blinkingDot.hpp"
#include "tintedDot.hpp"
#include <chrono>
#include <random>


MixedDotFactory::MixedDotFactory(int _dotsize, int _x, int _y) :
  dotsize{_dotsize}, x{_x}, y{_y}
{
}

dot* MixedDotFactory::createDot(){

  unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  std::uniform_int_distribution<int> distrib_dot(1,3);
  std::uniform_int_distribution<int> distrib_tint(0,2);

  int selected=distrib_dot(gen);
  int tint=distrib_tint(gen);

  dot* d;

  switch (selected){
  case 1:
    d = new dot{x, y, dotsize};
    break;
  case 2:
    d = new blinkingDot{x, y, dotsize, FL_WHITE};
    break;
  case 3:
    d = new tintedDot{x, y, dotsize, colors_[tint]};
    break;
  }
  return d;
}

MixedDotFactory::~MixedDotFactory(){

}
