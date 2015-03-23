#include "has_color.hpp"
#include <ctime>
#include <cstdlib> //rand()
#include <Fl/fl_draw.H>
//konstruktører
has_color::has_color(bool Random) : 
  red_{(ColorPart*)&color_+1}, 
  green_{(ColorPart*)&color_+2}, 
  blue_{(ColorPart*)&color_+3}  
{
  if(!Random){ //sett farge til hvit
       Fl::get_color(color_, *red_, *green_, *blue_);
  }
  if(Random){ //sett en random farge
    //Vil ha overvekt av orange=0xffa500;
    srand(time(0));
    ColorPart red= rand()%(265-128)+128; //Minst halvparten av rød i orange
    ColorPart green=rand()%(256-82)+82; //Minst halvparten av grønn i orange
    ColorPart blue=rand()%256;
    color_=fl_rgb_color(red,green,blue); //Returnerer fl_color nærmest rgb
  } 
  Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}


//Initialiser med en full farge
has_color::has_color(Color start) : 
  //color_{start},
  red_{(ColorPart*)&color_+1}, 
  green_{(ColorPart*)&color_+2}, 
  blue_{(ColorPart*)&color_+3}
{
  color_=start;
  Fl::get_color(start, *red_, *green_, *blue_); //Setter rgb for fl_color
}

//Initialize with RGB-parts
has_color::has_color(ColorPart red, ColorPart green, ColorPart blue) :
  red_{(ColorPart*)&color_+1}, 
  green_{(ColorPart*)&color_+2}, 
  blue_{(ColorPart*)&color_+3}
{
  color_=fl_rgb_color(red,green,blue); //Returnerer fl_color nærmest rgb
}

// Make color darker
void has_color::darken_color(){
  color_=fl_darker(color_);
  // Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}

// Make color lighter
void has_color::lighten_color(){
  color_=fl_lighter(color_);
  //Fl::get_color(color_, *red_, *green_, *blue_); //Setter rgb for fl_color
}

// Return the approximate visibility of the color, from 0-1
float has_color::visibility(){}
