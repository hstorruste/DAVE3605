#include "animation_canvas.hpp"
#include <iostream>
#include <Fl/Fl_Window.H>

//Static member
int animation_canvas::fps=24; //frames pr sekund

//Konstruktør
animation_canvas::animation_canvas(const char *l, int w, int h) :
  Fl_Box(0,0,w,h,l)
{
  
}

void animation_canvas::timer(void* canvas){
  Fl::repeat_timeout((double)1/fps, timer, canvas);
  std::cout << "Tick" << std::endl;
  ((Fl_Window*)canvas)->redraw();
}

void animation_canvas::add(animated* part){
  parts.push_back(part);
}

animation_canvas::~animation_canvas(){
  for(animated* part : parts)
    delete part;
}

void animation_canvas::draw(){
  increment();
}

void animation_canvas::increment(){
  for(int i=0; i<parts.size();i++){
    if(parts[i]->animation_finished()){
      delete parts[i];
      parts.erase(parts.begin()+i);
    }
    else
      ++*parts[i];
  }
}
