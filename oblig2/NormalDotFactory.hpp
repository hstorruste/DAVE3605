#ifndef CLASS_NORMALDOTFACTORY_H
#define CLASS_NORMALDOTFACTORY_H


#include "AbstractDotFactory.hpp"

class NormalDotFactory : public AbstractDotFactory{
  int dotsize;
  int x;
  int y;
public:

  NormalDotFactory(int _dotsize, int _x, int _y);

  dot* createDot() override;

  /** Virual destructor*/
  ~NormalDotFactory() override;


};

#endif
