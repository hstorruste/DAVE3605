#ifndef CLASS_TINTEDDOT_H
#define CLASS_TINTEDDOT_H

#include "dot.hpp"

class tintedDot : public dot {

public:

  /** Initialize the dot with a starting color */
  tintedDot(float _x, float _y, float _r, Color c);

  ~tintedDot() override;

};

#endif
