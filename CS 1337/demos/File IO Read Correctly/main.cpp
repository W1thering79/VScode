#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>              //exit() and EXIT_FAILURE

using namespace std;

int main() {
    ifstream namefileObj("names.txt");
    string   inputStr;

    if (!namefileObj.is_open()) {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    unsigned nameCount = 0;

//    while (!namefileObj.eof()) {        // incorect, trailing white space will break
//      namefileObj >> inputStr;
      while (namefileObj >> inputStr) {   // using streams

      cout << inputStr << endl;
      nameCount++;

    }

    cout << endl << "Number of names read from file: " << nameCount << endl;

    namefileObj.close();
}
