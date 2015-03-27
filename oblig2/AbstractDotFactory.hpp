#ifndef CLASS_ABSTRACTDOTFACTORY_H
#define CLASS_ABSTRACTDOTFACTORY_H

#include "dot.hpp"
#include "rocket.hpp"

class AbstractDotFactory{

public:

  /** Creates a dot object */
  virtual dot* createDot()=0;

  virtual ~AbstractDotFactory() {};
};
#endif
