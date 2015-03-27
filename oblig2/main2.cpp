#include "blinkingDot.hpp"
#include "rocket.hpp"
#include "BlinkingDotFactory.hpp"
#include "fireworks.hpp"
#include <iostream>
#include <string>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>

using namespace std;

int main(){

  int width=Fl::w();
  int height=Fl::h();
  Fl_Window* window=new Fl_Window{width,height, "fireworks!"};
  window->color(FL_BLACK);
  window->fullscreen();
  fireworks* fwork=new fireworks{"", width, height, 15};
  Fl::add_timeout(1, animation_canvas::timer, window);

  window->end();

  window->show();

  Fl::run();

  //  AbstractDotFactory* factory = new BlinkingDotFactory{5,20,40};
  //  rocket* rock1 = new rocket{200,5,10,20,40, factory};
  delete fwork;
  delete window;
}
