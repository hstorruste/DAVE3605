#include "has_color.hpp"
#include "is_vector.hpp"
#include "dot.hpp"
#include <iostream>
#include <string>
#include <FL/fl_draw.H>

using namespace std;

int main(){
  
  /*  has_color col{true};
  cout << "Har color: " << col.color() << endl;
  cout << "Rød: " << int(col.red()) << endl;
  cout << "Grønn: " << int(col.green()) << endl;
  cout << "Blå: " << int(col.blue()) << endl;
  */

  /*  is_vector vec{10.10,20.20};
  cout << "Vector har posisjon: ( " << vec.x() << ", " << vec.y();
  cout << " )" << endl;
  cout << "Speed: " << vec.speed() << endl;
  cout << "Retning(Rad): " << vec.direction() << endl;
  vec.increment_position();
  vec.increment_position();
  vec.increment_position();
  cout << "Vector har posisjon: ( " << vec.x() << ", " << vec.y();
  cout << " )" << endl;
  cout << "Speed: " << vec.speed() << endl;
  cout << "Retning(Rad): " << vec.direction() << endl;
  */
  
  dot dot1{40.3,40.5,20.0,FL_YELLOW};
  cout << "Dot'en har: \n";
  Color col = dot1.color();
  ColorPart* p = (ColorPart*)&col;
  cout << "Color: ";
  for(int i=0;i<10;i++){
    cout << (int)*(p+i) << " ";
  }
  cout << endl;
  cout << "Rød: " << (int)dot1.red() << endl;
  cout << "Grønn: " << (int)dot1.green() << endl;
  cout << "Blå: " << (int)dot1.blue() << endl;
  cout << "Dot'en har posisjon: ( " << dot1.x() << ", " << dot1.y();
  cout << " )" << endl;
  cout << "Speed: " << dot1.speed() << endl;
  cout << "Retning(Rad): " << dot1.direction() << endl;
  
  for(int i=0;i<5;i++){
    dot1.darken_color();
    Color col = dot1.color();
    ColorPart* p = (ColorPart*)&col;
    cout << "New color: ";
    for(int i=0;i<10;i++){
      cout << (int)*(p+i) << " ";
    }
    cout << endl;
    cout << "Rød: " << (int)dot1.red() << endl;
    cout << "Grønn: " << (int)dot1.green() << endl;
    cout << "Blå: " << (int)dot1.blue() << endl;
  }

  for(int i=0;i<5;i++){
    dot1.lighten_color();
    Color col = dot1.color();
    ColorPart* p = (ColorPart*)&col;
    cout << "New color: ";
    for(int i=0;i<10;i++){
      cout << (int)*(p+i) << " ";
    }
    cout << endl;
    cout << "Rød: " << (int)dot1.red() << endl;
    cout << "Grønn: " << (int)dot1.green() << endl;
    cout << "Blå: " << (int)dot1.blue() << endl;
  }

  /*  dot1.increment_position();
  dot1.increment_position();
  dot1.increment_position();
  cout << "Dot'en har posisjon: ( " << dot1.x() << ", " << dot1.y();
  cout << " )" << endl;
  cout << "Speed: " << dot1.speed() << endl;
  cout << "Retning(Rad): " << dot1.direction() << endl;*/
  
   
  /*  int test{1918986818};
  
  char* ch=(char*)&test;
  cout << *ch << endl;
  ch= ch +1;
  cout << *ch << endl;*/
 
}