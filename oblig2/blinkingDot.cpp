#include "blinkingDot.hpp"
#include <FL/Fl.H>

//Konstruktører
blinkingDot::blinkingDot(float _x, float _y, float _r) :
  dot(_x,_y,_r)
{
}

blinkingDot::blinkingDot(float _x, float _y, float _r, Color c) :
  dot(_x,_y,_r,c)
{
}

void blinkingDot::draw(){
  static int inc=0;
  inc++;
  if(inc%4 == 0 || (inc+1)%4 == 0) //To ganger med svart og to ganger med color
    fl_color(FL_BLACK);
  else
    fl_color(color());
  fl_pie(x(),y(),r,r,0,360);
    
}

void blinkingDot::operator++(){
  static int inc=0;
  inc++;
  if(inc%4 == 0)
    darken_color();
  increment_posiion();
  draw();
}