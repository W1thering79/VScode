#include <cctype>  // isnnn(char)
#include <cstring> // str(strings)
#include <string>  // string objs
#include <iostream>

using namespace std;

int main() {

  int a[10] = { 1, 2, 3, 5, 7, 11, 13, 15, 17, 19 };

  int* currentptr = &a[2];
  int* stopptr = &a[9];

  int total = 0;

  while (currentptr < stopptr) {

    total += *currentptr;
    currentptr += 2;

  }

  cout << total;
}



