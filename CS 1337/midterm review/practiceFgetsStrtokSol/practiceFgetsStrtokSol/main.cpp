#define _CRT_SECURE_NO_WARNINGS

#include <cctype>  // isnnn(char)
#include <cstring> // str(strings)
#include <string>  // string objs
#include <iostream>

using namespace std;

int main()
{

  char word[150] = "Comets unite!UTD is a world class university$ I think $ I hope";
  // printf("Enter a string: ");
  // fgets(word, 150, stdin);

  char* tokenPtr = strtok(word, "$!");

  while (tokenPtr != NULL) {
    cout << tokenPtr << endl;
    tokenPtr = strtok(NULL, "$");
  }

}