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
  std::uniform_int_distribution<int> distribx(100,w-100);//minst 100 fra kanten
  std::uniform_int_distribution<int> distriby(100,h-100);//minst 100 fra kanten
  std::uniform_int_distribution<int> distribfuse(1,200); //fuse
  int x;
  int y;
  int fuse;
  for(int i=0;i < rocketcount; i++){
    x=distribx(gen); //random i x-aksen med 100 avstand fra kanten
    y=distriby(gen); //random i y-aksen med 100 avstand fra kanten
    fuse=distribfuse(gen);
    animated *r = new rocket{200,5,fuse,x,y};
    add(r);
  }
}

//Destruktør
fireworks::~fireworks(){

}
