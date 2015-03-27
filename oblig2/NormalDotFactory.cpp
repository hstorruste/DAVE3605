#include "NormalDotFactory.hpp"


NormalDotFactory::NormalDotFactory(int _dotsize, int _x, int _y) :
  dotsize{_dotsize}, x{_x}, y{_y}
{
  
}

dot* NormalDotFactory::createDot(){
  return new dot(x, y, dotsize);
}

NormalDotFactory::~NormalDotFactory(){

}
