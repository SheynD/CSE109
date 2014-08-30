//Sheyn Denizov
//09/25/13
//Program 1
//The purpose of this program is to develop a class whose objects
//simulate the workings of A Stack data structure

#include <iostream>
#include <stdlib.h>

using namespace std;

//This is the class whose members and objects will simulate the Stack
class Stack {
private:
  //Dynamic array that holds double values
  double* stackArray;
  //Index for array
  int index;
  int size;
  //Register variable that can hold a double value
  double reg;

public:
  //Initialize a default size for the double array
  static const int DEFSIZE = 100;
  //No arg constructor
  Stack();
  //One-arg constructor whose parameter defines the stack size
  Stack(int size);
  //Copy constructor
  Stack(const Stack &s);
  //Deconstructor deletes stack and sets its memory space to NULL
  ~Stack(); 
  Stack& push();
  Stack& pop();
  Stack& add();
  Stack& sub();
  Stack& mul();
  Stack& div();
  double getRegister();
  Stack& setRegister(double reg);
  void print(ostream &out = cout) const;
  Stack& operator +=(double dbl);
  friend bool operator ==(Stack &s, double dbl);
  friend istream& operator >>(istream &in, Stack &s);
  friend ostream& operator <<(ostream &out, Stack &s);
private:
  void check(bool exp, const char* msg);
};

int main() {
  //Create a stack object of size 10
  Stack st(10);
  st.setRegister(2);
  st.push().setRegister(3);
  st.push().add().pop();
  cout << " Expect 5: " << st.getRegister() << endl;
  st.setRegister(4).push().setRegister(15).push().setRegister(20).push();
  cout << "Expect Stack:(20 15 4 ): " << st;
  cout << "Expect Stack(200 4): " << st.mul();
  st.setRegister(8);
  cout << "Expect Stack(4): " << st.push().div().pop();
  cout << "Expect 37.5: " << st.getRegister() << endl;
  cout << "Expect Stack(-33.5): " << st.push().sub();
  cin >> st;  //enter a 100
  st += 65.5;
  cout << "Expect 165.5: " << st.getRegister() << endl;
  cout << "Expect 1: " << (st == 165.5) << endl;
  st.pop().pop().pop();
}

Stack::Stack() {
  stackArray = new double[DEFSIZE];
  index = 0;
  size = DEFSIZE;
}

Stack::Stack(int sz) {
  index = 0;
  size = sz;
  check(sz > 0, "Stack(size) Invalid Stack Size");
  stackArray = new double[sz];
  check(stackArray != NULL, "Stack cannot be NULL");
}

Stack::Stack(const Stack &s) {
  size = s.size;
  index = s.index;
  stackArray = new double[size];
  check(stackArray != NULL, "Stack");
  for(int i = 0; i < index; i++) {
    stackArray[i] = s.stackArray[i];
  }
}

Stack::~Stack() {
  delete[] stackArray;
  stackArray = NULL;
}

void Stack::check(bool good, const char* msg) {
  if(!good) {
    cout << msg << endl;
    exit(0);
  }
}

Stack& Stack::push() {
  check(index >= 0, "(Stack::push() stack underflow)");
  stackArray[index] = reg;
  index++;
  return *this;
}

Stack& Stack::pop() {
  check(index >= 0, "(Stack::pop() stack underflow)");
  index--;
  reg = stackArray[index];
  return *this;
}

Stack& Stack::add() {
}
