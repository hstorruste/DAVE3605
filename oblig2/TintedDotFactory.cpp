#include "TintedDotFactory.hpp"
#include "tintedDot.hpp"

TintedDotFactory::TintedDotFactory(int _dotsize, int _x, int _y, Color c) :
  dotsize{_dotsize}, x{_x}, y{_y}, color_{c}
{
}
/** Returns dot* with 1 of 7 tints of the color provided in constructer*/
dot* TintedDotFactory::createDot(){
  return new tintedDot(x, y, dotsize, color_);
}

TintedDotFactory::~TintedDotFactory(){
}
