#ifndef CLASS_BLINKINGDOTFACTORY_H
#define CLASS_BLINKINGDOTFACTORY_H


#include "AbstractDotFactory.hpp"


class BlinkingDotFactory : public AbstractDotFactory{
  int dotsize;
  int x;
  int y;
  Color color_=FL_WHITE;
public:
  /** Initialize */
  BlinkingDotFactory(int _dotsize, int _x, int _y);

  BlinkingDotFactory(int _dotsize, int _x, int _y, Color c);
  /** Creates a dot object*/
  dot* createDot() override;

  /** Virtual destructor*/
  ~BlinkingDotFactory() override;
};

#endif
