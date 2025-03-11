#include <cctype>  // isnnn(char)
#include <cstring> // str(strings)
#include <string>  // string objs
#include <iostream>

using namespace std;

int main() {

  int x[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

  int* xp = x;

  int* yp = &xp[5];

  cout << yp[2];
}