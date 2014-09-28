//Sheyn Denizov
//CSE 109
//10/24/13
//P3
//Purpose: The purpose of this program is to create a String class that holds sets of characters in a char dynamic array (or string) object and model the concepts behind strings and C-strings

#include "check.h"
#include<cstring>
#include<stdlib.h>
#include<string>

//This string class stores a series of characters
class String {
 private:
  char* charArray;
  char* delimArray;
  int index;
  int sLength;

 public:
  String();
  String(const char* phrase, const char* delimit = " \t\n");
  String(const char c);
  String(const String &str);
  String(int num);
  ~String();
  double asDouble();
  int asInt();
  String& operator +(const String &s1);
  char* getStr();
  void setDelimiters(const char* delimit);
  String& add(char c);
  char& operator [](int val);
  friend bool operator ==(const String &s1, const String &s2);
  friend bool operator ==(const String &s1, const char* norm);
  friend bool operator >(const String &s1, const String &s2);
  friend bool operator >(const String &s1, const char* norm);
  friend bool operator >=(const String &s1, const String &s2);
  friend bool operator >=(const String &s1, const char* norm);
  friend bool operator <(const String &s1, const String &s2);
  friend bool operator <(const String &s1, const char* norm);
  friend bool operator <=(const String &s1, const String &s2);
  friend bool operator <=(const String &s1, const char* norm);
  friend bool operator !=(const String &s1, const String &s2);
  friend bool operator !=(const String &s1, const char* norm);
  friend istream& operator >>(istream &in, String &st);
  friend ostream& operator <<(ostream &out, String &st);
  String& operator =(const String &st);
  String& operator =(const char* wd);
  String& operator =(char c);
  void print(ostream &out = cout) const;
  int length();
};

