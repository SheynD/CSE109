//Sheyn Denizov
//CSE 109
//10/24/13
//P3
//Purpose:

#include "String.h"

int main() {
  String word;
  String word2("Hello World", ", \t");
  String word3(word2);
  String word4('x');
  String number(100);
  String number1("500.25");
  String number2("750");
  double num = number1.asDouble();
  cout << "Expect 500.25: " << num << endl;
  int integer = number2.asInt();
  cout << "Expect 750: " << integer << endl;
  word4 + word2 + number;
  cout << "Expect: 1: " << (word4 == "xHello World100") << endl;
  cout << "Expect 100: " << number << endl;
  cout << "Expect: ' Hello World Hello World xHello World100'\n         ";
  cout << "'" << word << " " << word2 << " " << word3 << " " << word4 << " " << number << "'\n";
  word2 = word4;
  word4 = "Lehigh";
  word3 = "won";
  cout << "Expect: 'xHello World100 Lehigh won'\n      ";
  cout << "'" << word2 << " " << word4 << " " << word3 << "'\n";
  word4 = '!';
  word4[0] = 'S';
  cout << "Expect: 'S'\n       '" << word4 << "'\n";
  char* temp;
  temp = word2.getStr();
  temp[0] = '!';
  cout << "Expect: 'xHello World100 !Hello World100' \n         '" << word2 << " " << temp << "'\n";
  delete[] temp;
  word.add('!').add('!').add('!').add('!').add('!').add('!').add('!');
  cout << "Expect: '!!!!!!!' has 7 letters'\n         ";
  cout << "'" << "' has " << word.length() << " letters\n";
  cout << "Expect: 010110\n        ";
  cout << (word < word) << (word <= word) << (word > word) << (word >= word) << (word == word) << (word != word) << endl;
  cout << "Expect: 001101\n        ";
  cout << (word2 < "Hello") << (word2 <= "Hello") << (word2 > "Hello") << (word2 >= "Hello") << (word2 == "Hello") << (word2 != "Hello") << endl;
  cout << "Expect 100: " << String("100").asInt() << endl;
  cout << "Expect 101.23: " << String("101.23").asDouble() << endl;
  word.setDelimiters(",\n");
  cin >> word;
  cout << "You entered: '" << word << "'\n";
  cout << "Expect crash (non double): \n";
  cout << word.asDouble() << endl;
}
