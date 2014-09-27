//Sheyn Denizov
//10/16/2013
//Program 2
//The purpose of this program is to use a subclass of Stack, called
//Memory, to simulate memory locations and store double values

#include "memory.h"

int main() {
  Memory mem2; //initialize memory size to 10                               
  Memory mem1(30,20); //30 is memory size, 20 is stack size                   
  Memory mem3(mem2);

  cout << "Maximum number of memory areas for Memory " << mem2.MAXMEM << endl; //this should illustrate the need for a static const
  cout << "Enter a number" << endl;

  cin >> mem3;  //overload >> for reading in a double and storing the double 
  //into the register of Stack                                     
  //Assume a 10.25 is entered                                             

  cout << "Expect 10.25: " << mem3.getRegister() << endl; //returns register value
  mem3.clearReg(); //set Register to 0 

  mem3.clearMemory(2).setRegister(25.5);   //sets the value in memory location
  //2 to 0, setRegister sets the value in register to 25.5                          
  cout << "Expect 25.5: " << mem3.getRegister() << endl;


  mem3.loadMemory(2,50.65).addMemory(2);   //sets the value in memory location
  //2 to 50.65, adds the value in memory 2 with the value in register and puts result back in memory location 2

  cout << "Expect 76.15: " << mem3.getMemory(2) << endl;


 mem3.loadMemory(1,30.50).loadMemory(3,25).loadMemory(4,65).loadMemory(10,100)\
   ; //loading values into memory locations                                      
 cout << "Expect Memory(30.5,76.15,25,65,0,0,0,0,0,100): " << mem3;

 mem3.loadReg(2).push(); //set register to the value in memory location 2 and push to stack
 mem3.loadReg(3).push().add().pop(); //set register to the value in memory location 3 and push to stack add values in memory location 2 and 3 and pop from stack
  cout << "Expect 101.15: " << mem3.getRegister() << endl;


 mem3.operationMemory(mem3.ADD,2).operationMemory(mem3.MUL,2).operationMemory(
 Memory::SUB,2);  //this should illustrate that ADD,MUL,SUB,DIV should be decla red as static const where each of them hold a number that represents the arithmetic operation to perform. This method will use the value within the register and the value within the memory location (stated as second parameter) and perform the operation that is stated as the first parameter. The result of the operation should be put back into the memory location.                                 

   mem3.operationMemory(mem3.DIV,2);  //this will take the value in memory location 2 and divide it by the value in the register and then put the result back into memory location 2                                                           

  cout<< "Expect: 176.3: " << mem3.getMemory(2) << endl; //returns register value

 mem1 = mem3; //copies values from mem3 to mem1                             

 mem1.loadMemory(2,750); //checks to see if the equals works correctly.     

 cout << "Expect Memory(30.5,176.3,25,65,0,0,0,0,0,100): " << mem3;
 cout << "Expect Memory(30.5,750,25,65,0,0,0,0,0,100): " << mem1;
}
