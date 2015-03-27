#ifndef CLASS_TINTEDDOTFACTORY_H
#define CLASS_TINTEDDOTFACTORY_H

#include "AbstractDotFactory.hpp"

class TintedDotFactory : public AbstractDotFactory{
  int dotsize;
  int x;
  int y;
  Color color_=FL_CYAN;

public:

  TintedDotFactory(int _dotsize, int _x, int _y, Color c);

  dot* createDot() override;

  ~TintedDotFactory() override;

};


#endif
