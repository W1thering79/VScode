
#define _CRT_SECURE_NO_WARNINGS

#include <cctype>  // isnnn(char)
#include <cstring> // str(strings)
#include <string>  // string objs
#include <iostream>

using namespace std;

int main() {

  int maxChars;

  const int SIZE_1 = 24;

  const int SIZE_2 = 24;

  char string1[SIZE_1] = "Comets say ";
  char string2[SIZE_2] = "1337 owns us all day";

  maxChars = sizeof(string1) - (strlen(string1));

  cout << "sizeof(string1) " << sizeof(string1) << endl;
  cout << "strlen(string1) " << strlen(string1) << endl;
  cout<< "maxChars " << maxChars << endl;

  strncat(string1, string2, maxChars);

  string1[SIZE_1 - 1] = '\0';

  cout << string1 << endl;

}