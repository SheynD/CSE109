//Sheyn Denizov                                                                 
//10/16/2013                                                                    
//Program 2                                                                     
//The purpose of this program is to use a subclass of Stack, called             
//Memory, to simulate memory locations and store double values                  

#include "stack.h"

//This class Memory has the members who will simulate a dynamic array           
//of memory locations that hold double values and who is a derived              
//class of Stack                                                                
class Memory:public Stack {
 private:
  //Dynamic array of memory locations that point to double values               
  double* memoryArray;
  //The size of the memoryArray                                                 
  int memSize;

 public:
  //Constant integer that is the maximum size of the array                      
  static const int MAXMEM = 100;
  //Constant integers that each represent an operation                          
  static const int ADD = 1;
  static const int SUB = 2;
  static const int MUL = 3;
  static const int DIV = 4;
  //No-arg constructor initializes size of memoryArray to 10                    
  Memory();
  //Two-arg constructor initializes size of memory to mem and the size          
  //of Stack to stk                                                             
  Memory(int mem, int stk);
  //Copy constructor
  Memory(const Memory &Memory);
  //Deconstructor                                                               
  ~Memory();
  //This method sees what op evaluates to and based on the value of             
  //op, the consequential arithmetic operation is performed on the              
  //register value and the value inside of a memoryArray element                
  Memory& operationMemory(int op, int mem);
  //This method sets the register to 0                                          
  Memory& clearReg();
  //This method sets the value within the memory location stated by             
  //mem to 0
  Memory& clearMemory(int mem);
  //This method returns the memory location stated by mem                       
  double getMemory(int mem);
  //This method puts the number within value into the memory location mem       
  Memory& loadMemory(int mem, double value);
  //This method adds what is in the register with the memory location           
  //mem and puts the result back into the memory location mem                   
  Memory& addMemory(int mem);
  //This method places the value within the memory location mem into            
  //the register                                                                
  Memory& loadReg(int mem);
  //This friend method overloads cin                                            
  friend istream& operator >>(istream &in, Memory &m);
  //This friend method overloads cout                                           
  friend ostream& operator <<(ostream &out, Memory &m);
  //This overloaded method copies the values from one memoryArray into another 
  Memory& operator =(const Memory &m);
  //This method prints out the values                                           
  void print(ostream &out = cout) const;
};
