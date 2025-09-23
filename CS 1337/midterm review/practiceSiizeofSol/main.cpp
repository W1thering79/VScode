#include <cctype>    // isnnn(char)
#include <cstring>   // str(strings)
#include <string>    // string objs
#include <iostream>

using namespace std;

int main() {

  struct People {
    int    age;
    string name;
    double income;
  };

  cout << "int    " << sizeof(int)    << endl 
       << "float  " << sizeof(float)  << endl 
       << "double " << sizeof(double) << endl
       << "string " << sizeof(string) << endl;

  cout << sizeof(int) + sizeof(double) + sizeof(string) << endl;

  cout << sizeof(int) + sizeof(double) + 32 << endl;

  cout << "sizeof(People) " << sizeof(People) << endl;

}