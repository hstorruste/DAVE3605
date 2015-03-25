#include "has_color.hpp"
#include <random>
#include <chrono>
#include <Fl/fl_draw.H>
//konstruktører
has_color::has_color(bool Random) : 
  red_{(ColorPart*)&color_+3}, 
  green_{(ColorPart*)&color_+2}, 
  blue_{(ColorPart*)&color_+1}  
{
  if(!Random){ //sett farge til hvit
       Fl::get_color(color_, *red_, *green_, *blue_);
  }
  if(Random){ //sett en random farge
    //Vil ha overvekt av orange=0xffa500;
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distrib(0,127);
    ColorPart red= distrib(gen)+128; //Minst halvparten av rød i orange
    ColorPart green=distrib(gen)+82; //Minst halvparten av grønn i orange
    ColorPart blue=distrib(gen);
    color_=fl_rgb_color(red,green,blue); //Returnerer fl_color nærmest rgb
  } 
  Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}


//Initialiser med en full farge
has_color::has_color(Color start) : 
  red_{(ColorPart*)&color_+3}, 
  green_{(ColorPart*)&color_+2}, 
  blue_{(ColorPart*)&color_+1}
{
  color_=start;
  Fl::get_color(start, *red_, *green_, *blue_); //Setter rgb for fl_color
}

//Initialize with RGB-parts
has_color::has_color(ColorPart red, ColorPart green, ColorPart blue) :
  red_{(ColorPart*)&color_+3}, 
  green_{(ColorPart*)&color_+2}, 
  blue_{(ColorPart*)&color_+1}
{
  color_=fl_rgb_color(red,green,blue); //Returnerer fl_color nærmest rgb
}

// Make color darker
void has_color::darken_color(){
  color_=fl_darker(color_);
}

// Make color lighter
void has_color::lighten_color(){
  color_=fl_lighter(color_);
}

// Return the approximate visibility of the color, from 0-1
float has_color::visibility(){
  return (float)(*red_+*green_+*blue_)/(255*3);
}
