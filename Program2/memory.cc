//Sheyn Denizov                                                                 
//10/16/2013                                                                    
//Program 2                                                                     
//The purpose of this program is to use a subclass of Stack, called             
//Memory, to simulate memory locations and store double values                  

#include "memory.h"
#include "check.h"

//No-arg constructor initializes the size of the memoryArray to 10              
Memory::Memory():Stack() {
  memSize = 10;
  memoryArray = new double[memSize];
  check(memoryArray != NULL, "(Memory::Memory() memoryArray cannot be NULL)");
}

//Two-arg constructor initializes the size of the memoryArray to mem            
//and the size of the stack to stk                                              
Memory::Memory(int mem, int stk):Stack(stk) {
  memSize = mem;
  //Check to see that mem is greater than zero and not greater than
  //the size of the memoryArray, this check will be implemented                 
  //everywhere mem is used                                                      
  check(mem > 0 && mem <= memSize, "(Memory::Memory(mem, stk) mem cannot be les\
s than 0 or more than memSize)");
  memoryArray = new double[memSize];
  check(memoryArray != NULL, "(Memory::Memory(mem, stk) memoryArray cannot be N\
ULL)");
}

//Copy constructor does a copy from each memoryArray element to the             
//same element in the memoryArray of a constant Memory object &mem
Memory::Memory(const Memory &mem):Stack(mem) {
  memSize = mem.memSize;
  memoryArray = new double[memSize];
  for(int i = 0; i < memSize; i++) {
    memoryArray[i] = mem.memoryArray[i];
  }
  check(memoryArray != NULL, "(Memory::Memory(&mem) memoryArray cannot be NULL)");
}

Memory::~Memory() {
  //Delete the memoryArray                                                      
  delete[] memoryArray;
  //Assign the memoryArray to NULL so no dangling pointers                      
  memoryArray = NULL;
}

Memory& Memory::operationMemory(int op, int mem) {
  check(mem > 0 && mem <= memSize, "(Memory::operationMemory(op, mem) mem canno\
t be less than 0 or more than memSize)");
  //Use conditional statements to see if op is equal to any of the
  //operations and perform the operation on the value in the memory             
  //location and the register                                                   
  if(op == ADD) {
    memoryArray[mem - 1] += getRegister();
  }
  if(op == SUB) {
    memoryArray[mem - 1] -= getRegister();
  }
  if(op == MUL) {
    memoryArray[mem - 1] *= getRegister();
  }
  if(op == DIV) {
    memoryArray[mem - 1] /= getRegister();
  }
  return *this;
}

Memory& Memory::clearReg() {
  //Set the register to 0                                                       
  setRegister(0);
  return *this;
}

Memory& Memory::clearMemory(int mem) {
  check(mem > 0 && mem <= memSize, "(Memory::clearMemory(mem) mem cannot be les\
s than 0 or more than memSize)");
  memoryArray[mem - 1] = 0;
  return *this;
}

//Return the double value that is in the mem - 1 element in the                 
//memoryArray (given that check is true)                                        
double Memory::getMemory(int mem) {
  check(mem > 0 && mem <= memSize, "(Memory::getMemory(mem) mem cannot be less than 0 or more than memSize)");
  double memoryValue = memoryArray[mem - 1];
  return memoryValue;
}

//Load the double value into the mem - 1 element in memoryArray (again          
//given check is true)                                                          
Memory& Memory::loadMemory(int mem, double value) {
  check(mem > 0 && mem <= memSize, "(Memory::loadMemory(mem, value) mem cannot be less than 0 or more than memSize)");
  memoryArray[mem - 1] = value;
  return *this;
}

//Add the value that is in the register to what is in the register              
//(using getRegister) and put the result back in the mem - 1 memory location    
Memory& Memory::addMemory(int mem) {
  check(mem > 0 && mem <= memSize, "(Memory::addMemory(mem) mem cannot be less than 0 or more than memSize)");
  double value = getRegister();
  memoryArray[mem - 1] += value;
  return *this;
}

//Set the register to what is in the mem - 1 element in the memoryArray         
Memory& Memory::loadReg(int mem) {
  check(mem > 0 && mem <= memSize, "Memory::loadReg(mem) mem cannot be less tha\
n 0 or more than memSize)");
  setRegister(memoryArray[mem - 1]);
  return *this;
}

istream& operator >>(istream &in, Memory &m) {
  double input;
  //Take in the double value and set the register of Memory &m to the           
  //input value                                                                 
  in >> input;
  m.setRegister(input);
  return in;
}

ostream& operator <<(ostream &out, Memory &m) {
  //Call print method to print out what is in the memory object                 
  m.print(out);
  return out;
}

//Overloaded = operator copies the elements from one memory object to another   
Memory& Memory::operator =(const Memory &m) {
  memSize = m.memSize;
  memoryArray = new double[m.memSize];
  for(int i = 0; i < memSize; i++) {
    memoryArray[i] = m.memoryArray[i];
  }
  return *this;
}

//Similar print method as in Stack class except used to print out what          
//is in the memoryArray, with some decoration                                   
void Memory::print(ostream &out) const {
  out << "Memory(" << "";
  for(int i = 0; i < memSize; i++) {
    //If i is equal to the memSize - 1, there will be no commas
    //printed out in between, so last element has no comma after it             
    if(i == memSize - 1) {
      out << memoryArray[i] << "";
    }
    else {
      out << memoryArray[i] << ",";
    }
  }
  out << ")" << "";
  out << endl;
}

