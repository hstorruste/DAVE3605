#ifndef CLASS_MIXEDDOTFACTORY_H
#define CLASS_MIXEDDOTFACTORY_H

#include "AbstractDotFactory.hpp"
#include <vector>

class MixedDotFactory : public AbstractDotFactory{
  std::vector<Color> colors_{FL_RED, FL_GREEN, FL_BLUE};
  int dotsize;
  int x;
  int y;

public:

  MixedDotFactory(int _dotsize, int _x, int _y);

  dot* createDot() override;

  ~MixedDotFactory() override;

};

#endif
