#include "is_vector.hpp"
#include <random>
#include <chrono>
//konstuktører
is_vector::is_vector(double x, double y) :
  x_orig_{x}, y_orig_{y}, x_{x}, y_{y}
{
  //assign speed and direction randomly
  unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> distrib(1.0,15.0);
  std::uniform_real_distribution<double> distrib2(0.0,TAU);
  speed_=distrib(gen); //Speed 1.0-15.0
  direction_=distrib2(gen);
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
