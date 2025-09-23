#include <cctype>  // isnnn(char)
#include <cstring> // str(strings)
#include <string>  // string objs
#include <iostream>

using namespace std;

int main() {

  int primes[] = { 1, 2, 5, 7, 11, 13, 17, 19 };
  int total = 0;

  for (int i = 4; i > 0; i--) {
    cout << primes[i] << " ";
    total += primes[i];
  }

  cout << endl;

  cout << total << endl;

}