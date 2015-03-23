#include "rocket.hpp"


//Konsturktører
//Initialize normal -rocket will just create default dots
rocket::rocket(int _dotcount, int dotsize, int _fuse, int x, int y) : 
  dotcount{_dotcount}, fuse{_fuse}, dots(_dotcount)
{
  for(dot* d : dots){
    d = new dot(x, y, dotsize);
  }  
}
// Initialize with factory
/*rocket::rocket(int _dotcount, int dotsize, int _fuse, int x, int y,
	       AbstractDotFactory* dotFactory) :
  dotcount{_dotcount}, fuse{_fuse}, dots(_dotcount)
{

}*/
//Destruktør
rocket::~rocket(){
  for(dot* d : dots)
    delete d;

}

void rocket::operator++(){
  if(fuse < 0)
    --fuse;
  else{
    for(dot* d : dots){
      --d;
    }
  }
    
}
