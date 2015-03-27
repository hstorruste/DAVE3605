#include "rocket.hpp"
#include "AbstractDotFactory.hpp"
//Konstruktører
//Initialize normal -rocket will just create default dots
rocket::rocket(int _dotcount, int dotsize, int _fuse, int x , int y) :
  dotcount{_dotcount}, fuse{_fuse}
{
  for(int i=0;i< dotcount;i++)
    dots.push_back(new dot(x,y, dotsize));
}

//Initialize with factory
rocket::rocket(int _dotcount, int dotsize, int _fuse, int x , int y,
	       AbstractDotFactory* dotFactory) :
  dotcount{_dotcount}, fuse{_fuse}
{
  for(int i=0; i<dotcount; i++){
    dot* d= &*(dotFactory->createDot());
    dots.push_back(d);
  }
}

rocket::~rocket(){
  for(dot* d : dots)
    delete d;
}

//Burn fuse, then increment dots.
void rocket::operator++(){
  if(fuse > 0)
    --fuse;
  else
    for(int i=0; i<dots.size();i++){
      ++*dots[i];
    }
}

