#include <cctype>  // isnnn(char)
#include <cstring> // str(strings)
#include <string>  // string objs
#include <iostream>
#include <sstream>

using namespace std;

// The std::istringstream is a string class object 
// which is used to stream the string into different variables 
// and similarly files can be stream into strings.

int main() {

  istringstream lineInput("10 UTD 20 Comets 30");
  int total = 0;
  string item = "";

  while (lineInput >> item) {
    int value = 0;
    istringstream(item) >> value;
    total += value;
  }

  cout << total << endl;

  {
    istringstream lineInput("10.1 20.2 30.7");
    int total = 0, value = 0;

    while (lineInput >> value)
      total += value;

    cout << total;
  }

}

