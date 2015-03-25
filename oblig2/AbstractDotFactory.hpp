#ifndef CLASS_ABSTRACTDOTFACTORY_H
#define CLASS_ABSTRACTDOTFACTORY_H

class AbstractDotFactory{

public:

  /** Creates a dot object */
  virtual dot* createDot()=0;
};
#endif
