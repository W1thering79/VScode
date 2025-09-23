/*
Write a function named AutoMashUp to create new names based on autos from different eras.
The function will not return anything and has no arguments.

The function should read from two files(1980s.txt and 2010s.txt) and write to a third file(AutoMash.txt).

The function should read the entire names of both autos from the same line of each file.

Then, concatenate the first 5 characters of the auto from 1980s.txt 
with the first 5 characters of the auto on the same line in 2010s.txt.

The function should then concatenate the string "auto" to the name 
and write the resulting name to AutoMash.txt.

The two input files will contain the name of an auto on each line 
and each file will have the same number of lines. 
The function must use the proper string or C - string functions to create the dinosaur names.
No dinosaur name will be more than 20 characters.
Assume that all necessary libraries have already been included.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void AutoMashUp() {
  ifstream autos1980sFile ("1980s.txt");
  ifstream autos2010sFile ("2010s.txt");
  ofstream autosMashFile  ("autosMash.txt");


  if (!autos1980sFile.is_open() || !autos2010sFile.is_open() || !autosMashFile.is_open()) {
    cout << "Error opening files." << endl;
    return;
  }

  string auto1980s, auto2010s;
  while (getline(autos1980sFile, auto1980s) && getline(autos2010sFile, auto2010s))
  {
    string newAutoName = auto1980s.substr(0, 5) + auto2010s.substr(0, 5) + "auto";
    autosMashFile << newAutoName << endl;
  }

  autos1980sFile.close();
  autos2010sFile.close();
  autosMashFile.close();
}

int main() {
  AutoMashUp();
  return 0;
}


