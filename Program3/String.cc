//Sheyn Denizov
//CSE 109

#include "String.h"

String::String() {
  index = 0;
  sLength = 1;
  charArray = new char[sLength + 1];
  check(charArray != NULL, "String::String() charArray heap overflow");
  delimArray = new char[4];
  check(delimArray != NULL, "String::String() delimArray heap overflow");
  charArray[sLength] = '\0';
  delimArray[0] = ' ';
  delimArray[1] = '\t';
  delimArray[2] = '\n';
  delimArray[3] = '\0';
}

String::String(const char* phrase, const char* delimit) {
  sLength = strlen(phrase);
  charArray = new char[sLength + 1];
  check(charArray != NULL, "String::String(phrase, delimit) heap overflow");
  strcpy(charArray, phrase);
  delimArray = new char[strlen(delimit) + 1];
  check(delimArray != NULL, "String::String(phrase, delimit) heap overflow");
  strcpy(delimArray, delimit);
  charArray[sLength] = '\0';
  delimArray[strlen(delimit)] = '\0';
}

String::String(const char c) {
  sLength = 1;
  charArray = new char[sLength + 1];
  check(charArray != NULL, "String::String(const char c) heap overflow");
  charArray[0] = c;
  charArray[sLength] = '\0';
  delimArray = new char[5];
  check(delimArray != NULL, "String::String(const char c) delimArray heap overflow");
  delimArray[0] = ' ';
  delimArray[1] = '\t';
  delimAray[2] = '\n';
  delimArray[4] = '\0';
}

String::String(const String &str) {
  sLength = str.sLength;
  charArray = new char[sLength];
  check(charArray != NULL, "String::String(const String &str) charArray heap overflow");
  int delimit = 5;
  delimArray = new char[delimit];
  check(delimArray != NULL, "String::String(const String &str) delimArray heap overflow");
  for(int i = 0; i < sLength; i++) {
    charArray[i] = str.charArray[i];
  }
  for(int i = 0; i < delimit; i++) {
    delimArray[i] = str.delimArray[i];
  }
  charArray[sLength] = '\0';
  delimArray = new char[5];
  delimArray[0] = ' ';
  delimArray[1] = '\t';
  delimArray[2] = '\n';
  delimArray[3] = '\0';
}

String::String(int num) {
  int digit = 0;
  int val;
  char* charArr;
  val = num;
  if(val == 0) {
    digit = 1;
  }
  while(val > 0) {
    val /= 10;
    digit++;
  }
  charArr = new char[digit + 1];
  check(charArr != NULL, "String::String(int num) charArr heap overflow");
  charArr[digit] = '\0';
  while(digit > 0) {
    digit--;
    charArr[digit] = num % 10 + '0';
    num = num / 10;
  }
  strcpy(charArray, charArr);
  delimArray = new char[5];
  check(delimArray != NULL, "String::String(int num) delimArray heap overflow");
  delimArray[0] = ' ';
  delimArray[1] = '\t';
  delimArray[2] = '\n';
  delimArray[3] = '\0';
}

String::~String() {
  delete[] charArray;
  delete[] delimArray;
  charArray = NULL;
  delimArray = NULL;
}

double String::asDouble() {
  int decimal = 0;
  double dblChar = 0;
  for(int i = 0; i < sLength; i++) {
    if(charArray[i] == '.') {
      decimal++;
    }
    else {
      check(charArray[i] >= '0' && charArray[i] <= '9', "crash (non double)");
    }
  }
  dblChar = arof(charArray);
  check(decimal == 1, "String::asDouble() The String object is not a double");
  return dblChar;
}

int String::asInt() {
  for(int i = 0; i < sLength; i++) {
    check(charArray[i] >= '0' && charArray[i] <= '9', "String::asInt() The String object is not an int");
  }
  intChar = atoi(charArray);
  return intChar;
}

String& String::operator +(const String &s1) {
  sLength += s1.sLength;
  strncat(charArray, s1.charArray, sLength);
  charArray[sLength] = '\0';
  return *this;
}

char* String::getStr() {
  char* temp = new char[index + 1];
  check(temp != NULL, "String::getStr() temp heap oveflow");
  strcpy(temp, charArray);
  index++;
  temp[sLength] = '\0';
  return temp;
}

void String::setDelimiters(const char* delimit) {
  delete[] delimArray;
  delimArray = new char[strlen(delimit) + 1];
  check(delimArray != NULL, "String::setDelimiters(delimit) delimArray heap overflow");
  strcpy(delimArray, delimit);
  delimArray[strlen(delimit)] = '\0';
}

String& String::add(char c) {
  if(index > sLength - 1) {
    sLength += 10;
    char* charArray2 = new char[sLength + 1];
    check(charArray2 != NULL, "String::add(c) charArray2 heap overflow");
    strcpy(charArray2, charArray);
    delete[] charArray;
    charArray = charArray2;
  }
  charArray[index] = c;
  index++;
  charArray[index] = '\0';
  return *this;
}

char& String::operator [](int val) {
  check(val >= 0 && val < sLength, "String::operator [](val) val cannot be 0 or less and val cannot be less than the sLength");
  return charArray[val];
}

bool operator ==(const String &s1, const String &s2) {
  if(strcmp(s1.charArray, s2.charArray) == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator ==(const String &s1, const char* norm) {
  if(strcmp(s1.charArray, norm) == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator >(const String &s1, const String &s2) {
  if(strcmp(s1.charArray, s2.charArray) > 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator >(const String &s1, const char* norm) {
  if(strcmp(s1.charArray, norm) > 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator >=(const String &s1, const String &s2) {
  if(strcmp(s1.charArray, s2.charArray) >= 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator >=(const String &s1, const char* norm) {
  if(strcmp(s1.charArray, norm) >= 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator <(const String &s1, const String &s2) {
  if(strcmp(s1.charArray, s2.charArray) < 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator <(const String &s1, const char* norm) {
  if(strcmp(s1.charArray, norm) < 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator <=(const String &s1, const String &s2) {
  if(strcmp(s1.charArray, s2.charArray) <= 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator <=(const String &s1, const char* norm) {
  if(strcmp(s1.charArray, norm) <= 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator !=(const String &s1, const String &s2) {
  if(strcmp(s1.charArray, s2.charArray) != 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator !=(const String &s1, const char* norm) {
  if(strcmp(s1.charArray, norm) != 0) {
    return true;
  }
  else {
    return false;
  }
}

istream& operator >>(istream &in, String &st) {
  char c;
  st.index = 0;
  st.charArray = new char[st.sLength];
  int delength = strlen(st.delimArray);
  check(st.charArray != NULL, "operator >>(in, st) st.charArray heap overflow");
  bool flag = false;
  while(flag == false) {
    in.get(c);
    int place = 0;
    while(place < delength) {
      if(c == st.delimArray[place]) {
	flag = true;
      }
      place++;
    }
    if(flag == false) {
      st.add(c);
    }
  }
  return in;
}

ostream& operator <<(ostream &out, String &st) {
  st.print(out);
  return out;
}

String& String::operator =(const String &st) {
  index = st.index;
  sLength = st.sLength;
  charArray = new char[st.sLength];
  check(charArray != NULL, "String::operator =(String &st) charArray heap overflow");
  for(int i = 0; i < sLength; i++) {
    charArray[i] = st.charArray[i];
  }
  return *this;
}

String& String::operator =(const char* wd) {
  sLength = strlen(wd);
  charArray = new char[sLength];
  check(charArray != NULL, "String::operator =(const char* wd) charArray heap overflow");
  for(int i = 0; i < sLength; i++) {
    charArray[i] = wd[i];
  }
  return *this;
}

String& String::operator =(char c) {
  sLength = 1;
  charArray = new char[sLength + 1];
  check(charArray != NULL, "String::operator =(char c) charArray heap overflow");
  charArray[0] = c;
  charArray[sLength] = '\0';
  return *this;
}

void String::print(ostream &out) const {
  int place = 0;
  while(charArray[place] != '\0') {
    out << charArray[place] << "";
    place++;
  }
}

int String::length() {
  return index;
}
