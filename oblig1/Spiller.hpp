#ifndef SPILLER_HPP
#define SPILLER_HPP


#include <vector>
#include "Kort.hpp"

class Spiller{
  std::string navn;
  int saldo;
  std::vector<Kort> hand;

public:
  /** Constructor */
  Spiller(std::string, int);

  std::string getnavn();

  int getsaldo();

  std::vector<Kort> gethand();
  
  void hit(Kort*);

  int updateSaldo(int);
};

#endif
