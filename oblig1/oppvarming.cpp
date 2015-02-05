#include <iostream>

using namespace std;

long long msg1{28539401679696455};

int msg2[]{1918986818,1998611822,1684829551,
    544483182,1701538156,1768453152,8563};


int encrypted[]{1498105673, 1227249735, 1498829639,
    1196119078, 1314530904, 1197024843, 5853000};

int main(){

  
  // Print out the messages in human-readable form!                            

  

  cout << "Message 1: ";
  while(msg1 != 0){
    cout << char(msg1%256);
     msg1 = msg1/256;
  }
  cout << endl;

  cout << "Message 2: ";
  
  for(int i:msg2){
    int temp = i;
    while(temp != 0){
	cout << char(temp%256);
	temp = temp/256;	
     }
  }
  cout << endl;

  cout << "Decrypted: ";
  
  int shift{250};
  for(int i:encrypted){  
    int temp = i;
    while(temp != 0){
      cout << char((temp%256)+shift);
	temp = temp/256;
    }
  }
  cout <<endl;
  

}
