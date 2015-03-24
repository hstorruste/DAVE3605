#include "rocket.hpp"

//Konsturktører
//Initialize normal -rocket will just create default dots
rocket::rocket(int _dotcount, int dotsize, int _fuse, int x, int y) : 
  dotcount{_dotcount}, fuse{_fuse}
{
  for(int i=0;i< dotcount;i++){
    dots.push_back(new dot(x, y, dotsize));
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
  if(fuse > 0)
    --fuse;
  else{
    for(int i=0;i<dots.size();i++){
      ++*dots[i];
      if(dots[i]->visibility()<0.05){
	delete dots[i];
	dots.erase(dots.begin()+i);
      }
    }
  }    
}
