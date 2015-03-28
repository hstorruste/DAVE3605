#ifndef CLASS_BLINKINGDOT_H
#define CLASS_BLINKINGDOT_H

//Local includes
#include "dot.hpp"

class blinkingDot : public dot{

public:
  
  /** Initialize the dot */
  blinkingDot(float _x,float _y, float _r);

  /** Initialize the dot with a starting color */
  blinkingDot(float _x,float _y, float _r, Color c);

  /**Virtual destructor. */
  ~blinkingDot() override;

  void operator++() override;

};
#endif
