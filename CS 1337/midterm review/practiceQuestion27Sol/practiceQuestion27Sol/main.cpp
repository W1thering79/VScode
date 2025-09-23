/*
An employee record consists of the following details :

· ID      : A unique integer representing the employee ID.
· FName   : A string to store the patient's first name.
· LName   : A string to store the patient's last name.
· details : An integer array to store the employee's details, such as age, weight, and years of employment.

Define a structure for an employee.

Create a pointer to an array of these structures and access the array through the pointer.

Read all patient information from employees.txt and store it in a dynamically allocated
array of structures.

A sample of employees.txt is:

7777 Priya Kesavan 72   98    23
6666 Abdul Aziz    32  128     2
4123 Bucky Baxter  25  135     7
          :
          :

Implement a function named displayAbove50 that takes the array of structures and
the size of the array as parameters.
This function should display only the names of employees whose Age is 50 or above,
with the names displayed using setw(12) and left - justified.

Implement a function named displayAbove100 that takes the array of structures and
the size of the array as parameters.
This function should display only the names of employees whose wieght  is 100 or above,
with the names displayed using setw(12) and left - justified.

You need to write code for the following :

1. Read the input file and handle any errors opening the file (3 points)

2. Declare a structure employee with fields and their appropriate data types (4 points)

3. In your main function, declare an array of employees structures (2 points)

4. In your main function, read all the data from the file into the structures (4 points)

5. Implement the display Above50 function :

a.This function should display only the names of employees whose age is 50 or above,
  formatted with setw(12) and left - justified (5 points)

6. Ensure you write the prototype of the function and make the function call (2 points)

*/

// employee solution

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// employees structure definition

struct Employees {
  int    employeeId;
  string FName;
  string LName;
  int details[3];
};

void displayAbove50(Employees details[], int asize);

void displayAbove100(Employees details[], int asize);

int main() {

  string filename = "", fname, lname;

  cout << "Enter filename: ";
  cin >> filename;

  int Id, totalCount = 0;

  //open the input file for reading.
  ifstream finput(filename);

  if (!finput) {
    cout << "Could not open file" << endl;
    cout << "Exiting" << endl;
    exit(EXIT_FAILURE);
  }

  string temp;
  
  while (finput >> Id) {       //is there one or more sample data?
    getline(finput, temp);
    totalCount++;
  }

  finput.clear();
  finput.seekg(0); // seek to start

  //Dynamically create Employees array
  Employees* info = new Employees[totalCount];

  int index = 0;
  while (index < totalCount) {
    finput >> info[index].employeeId;
    finput >> info[index].FName;
    finput >> info[index].LName;
    finput >> info[index].details[0];
    finput >> info[index].details[1];
    finput >> info[index].details[2];

    index++;
  } // Finished scanning the file

  // display the records

  for (int i = 0; i < totalCount; i++) {
    cout << left << setw(4) << info[i].employeeId
      << left << setw(12)   << info[i].FName
      << left << setw(12)   << info[i].LName
      << left << setw(4)    << info[i].details[0]
      << left << setw(4)    << info[i].details[1]
      << left << setw(4)    << info[i].details[2] << endl;
  }
  cout<<endl;

  finput.close();

  displayAbove50(info, totalCount);

  displayAbove100(info, totalCount);

  delete[]info;
  info = nullptr;

}//end of main


void displayAbove50(Employees employees[], int asize) {

   cout << endl << "The employees having an AGE of 50 and above are : " << endl;

  for (int i = 0; i < asize; i++) {
    if (employees[i].details[0] >= 50) {
      cout << left << setw(12) << employees[i].FName
        << left << setw(12) << employees[i].LName 
        << left << setw(04) << employees[i].details[0] << endl;
    }
  }
}

void displayAbove100(Employees employees[], int asize) {
  cout << endl << "The employees that weigh 100 lbs and above are :" << endl;

  for (int i = 0; i < asize; i++) {
    if (employees[i].details[1] >= 100) {
      cout << left << setw(12) << employees[i].FName
           << left << setw(12) << employees[i].LName 
           << left << setw(04) << employees[i].details[1]
           << endl;
    }
  }
}
