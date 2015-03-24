#include "fireworks.hpp"
#include "rocket.hpp"
#include <random>
#include <chrono>
//Konstruktør
fireworks::fireworks(const char* title, int w, int h, int _rocketcount) :
  animation_canvas(title, w, h), rocketcount{_rocketcount}
{
  unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  int x;
  int y;
  int fuse;
  for(int i=0;i < rocketcount; i++){
    x=gen()%(w-200)+100; //random i x-aksen med 100 avstand fra kanten
    y=gen()%(h-200)+100; //random i y-aksen med 100 avstand fra kanten
    fuse=gen()%200+1;
    animated *r = new rocket{200,5,fuse,x,y};
    add(r);
  }
}

//Destruktør
fireworks::~fireworks(){

}
