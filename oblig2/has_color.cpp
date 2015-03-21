#include "has_color.hpp"
#include <ctime>
#include <cstdlib> //rand()
#include <Fl/fl_draw.H>
//konstruktører
has_color::has_color(bool Random) : 
  red_{new ColorPart}, green_{new ColorPart}, blue_{new ColorPart}
{
  if(!Random){ //sett farge til hvit
    Fl::get_color(color_, *red_, *green_, *blue_);
    
  }
  else{ //sett en random farge
    int orange=0xffa500;
    srand(time(0));
    int rnum=rand() %(0xffffff-orange) + orange;
    *blue_= char(rnum%256);
    rnum = rnum/256;
    *green_=char(rnum%256);
    rnum = rnum/256;
    *red_=char(rnum%256);
  } 
  color_=fl_rgb_color(*red_,*green_,*blue_); //Returnerer fl_color nærmest rgb
  Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}


//Initialiser med en full farge
has_color::has_color(Color start) : 
  red_{new ColorPart}, green_{new ColorPart}, 
  blue_{new ColorPart}, color_{start} 
{
  Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}

//Initialize with RGB-parts
has_color::has_color(ColorPart red, ColorPart green, ColorPart blue) :
  red_{&red}, green_{&green}, blue_{&blue}
{
  color_=fl_rgb_color(*red_,*green_,*blue_); //Returnerer fl_color nærmest rgb
}

// Make color darker
void has_color::darken_color(){
  color_=fl_darker(color_);
  Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}

// Make color lighter
void has_color::lighten_color(){
  color_=fl_lighter(color_);
  Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}

// Return the approximate visibility of the color, from 0-1
float has_color::visibility(){}

//OBS! hører ikke hjemme her.
//Destruktor må overides i de klassene som arver has_color. De får ansvaret.
has_color::~has_color(){

  delete blue_;
  delete green_;
  delete red_;
 
}
