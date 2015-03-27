#include "blinkingDot.hpp"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <iostream>
//Konstruktører
blinkingDot::blinkingDot(float _x, float _y, float _r) :
  dot{_x,_y,_r}
{
  //color_=Fl::get_color(color_);
  blackout=Fl::get_color(blackout);
}

blinkingDot::blinkingDot(float _x, float _y, float _r, Color c) :
  dot{_x,_y,_r,c}//, color_{c}
{
  //color_=Fl::get_color(color_);
  blackout=Fl::get_color(blackout);
}

blinkingDot::~blinkingDot(){
}

void blinkingDot::operator++(){
  
  ++t; //Bruker t, fungerte ikke med static int... (Den fadet ikke. Hvorfor?)
  
  if(t%4 == 0){
    darken_color();
  }
  increment_position();
  if(t%3 == 0)
    draw();
}
