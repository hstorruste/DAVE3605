#include "BlinkingDotFactory.hpp"
#include "blinkingDot.hpp"

BlinkingDotFactory::BlinkingDotFactory(int _dotsize, int _x, int _y) :
  dotsize{_dotsize}, x{_x}, y{_y}
{
}

BlinkingDotFactory::BlinkingDotFactory(int _dotsize, int _x, int _y, Color c) :
  dotsize{_dotsize}, x{_x}, y{_y}, color_{c}
{
}

dot* BlinkingDotFactory::createDot(){
  return new blinkingDot(x, y, dotsize, color_);
}

BlinkingDotFactory::~BlinkingDotFactory(){
}
