//Sheyn Denizov                                                                 
//10/16/2013                                                                    
//Program 2                                                                     
//The purpose of this program is to use a subclass of Stack, called             
//Memory, to simulate memory locations and store double values                  

#include "check.h"
#includex<stdlib.h>

void check(bool good, const char* msg) {
  if(!good) {
    cerr << msg << endl;
    exit(1);
  }
}
