//Sheyn Denizov
//CSE 109
//10/24/13
//P3
//Purpose: The purpose of this program is to create a String class that holds the sets of characters in a char dynamic array (or string) object and model the concepts behind strings and C-strings

#include "check.h"

void check(bool good, const char* msg) {
  if(!good) {
    cerr << msg << endl;
    exit(1);
  }
}
