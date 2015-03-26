#include "AbstractDotFactory.hpp"
#include "blinkingDot.hpp"

#include <FL/Fl.H>

class BlinkingDotFactory : public AbstractDotFactory{
  int dotsize;
  int x;
  int y;
public:
  /** Initialize */
  BlinkingDotFactory(int _dotsize, int _x, int _y);
  /** Creates a dot object*/
  dot* createDot() override;
};

BlinkingDotFactory::BlinkingDotFactory(int _dotsize, int _x, int _y) :
  dotsize{_dotsize}, x{_x}, y{_y}
{
}

dot* BlinkingDotFactory::createDot(){

  dot* d = new blinkingDot{x, y, dotsize, Fl_WHITE};

  return d;
}