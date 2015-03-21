#include "has_color.hpp"
#include "is_vector.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
  
  /*  has_color col{true};
  cout << "Har color: " << col.color() << endl;
  cout << "Rød: " << int(col.red()) << endl;
  cout << "Grønn: " << int(col.green()) << endl;
  cout << "Blå: " << int(col.blue()) << endl;
  */

  is_vector vec{10.10,20.20};
  cout << "Vector har posisjon: ( " << vec.x() << ", " << vec.y();
  cout << " )" << endl;
  cout << "Speed: " << vec.speed() << endl;
  cout << "Retning(Rad): " << vec.direction() << endl;
  vec.increment_position();
  vec.increment_position();
  vec.increment_position();
  cout << "Vector har posisjon: ( " << vec.x() << ", " << vec.y();
  cout << " )" << endl;
  cout << "Speed: " << vec.speed() << endl;
  cout << "Retning(Rad): " << vec.direction() << endl;


}
