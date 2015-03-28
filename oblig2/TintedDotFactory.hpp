#ifndef CLASS_TINTEDDOTFACTORY_H
#define CLASS_TINTEDDOTFACTORY_H

#include "AbstractDotFactory.hpp"
#include "tintedDot.hpp"

template<Color N>
class TintedDotFactory : public AbstractDotFactory{
  int dotsize;
  int x;
  int y;
  Color color_=N;

public:

  //  template<Color N>
  TintedDotFactory(int _dotsize, int _x, int _y);

  dot* createDot() override;

  ~TintedDotFactory() override;

};

template<Color N>
TintedDotFactory<N>::TintedDotFactory(int _dotsize, int _x, int _y) :
  dotsize{_dotsize}, x{_x}, y{_y}
{
}
/** Returns dot* with 1 of 7 tints of the color provided in constructer*/
template<Color N>
dot* TintedDotFactory<N>::createDot(){
  return new tintedDot(x, y, dotsize, color_);
}

template<Color N>
TintedDotFactory<N>::~TintedDotFactory(){
}


#endif
