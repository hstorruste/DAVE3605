#ifndef KORTSTOKK_HPP
#define KORTSTOKK_HPP

#include <vector>
#include "Kort.hpp"

class Kortstokk{
  std::vector<Kort> stokken;
  std::vector<Kort> kastet;

public:

  /** Constructor */
  Kortstokk();

  bool empty();

  void stokk();
  
  Kort* del();

};

#endif
