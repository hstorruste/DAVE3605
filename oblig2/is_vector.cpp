#include "is_vector.hpp"
#include <ctime>
#include <cstdlib> //rand()

//konstuktører
is_vector::is_vector(double x, double y) :
  x_orig_{x}, y_orig_{y}, x_{x}, y_{y}
{
  //assign speed and direction randomly
  srand(time(0));
  speed_=rand() % 5 + 1;
  direction_=(rand()%1000)*TAU/1000; //1000 forskjellige retninger
}

//Increment the position based on current position, speed and direction
void is_vector::increment_position(){
  x_+=speed_*cos(direction_);
  y_+=speed_*sin(direction_);
}

//Optional: Reset the position to its initial state
void is_vector::reset(){
  x_={x_orig_};
  y_={y_orig_};
}
