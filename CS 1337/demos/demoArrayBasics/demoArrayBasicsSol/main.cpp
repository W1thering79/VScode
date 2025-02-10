#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	char arrayCharString[]    = { 'H','i','\0' };
	char arrayLiteralString[] = { "Hi" };

	int NoOfElements;

	NoOfElements = sizeof(arrayCharString) /
		           sizeof(char);
	cout << NoOfElements << endl;

	for (int i = 0; 
		i < NoOfElements; 
		i++)
		  cout << arrayCharString[i];
	cout << endl;

	for (int i = NoOfElements - 2; 
		i >= 0; 
		i--)
		  cout << arrayCharString[i];
	cout << endl << endl;

	NoOfElements = sizeof(arrayLiteralString) /
		           sizeof(char);
	cout << NoOfElements << endl;

	for (int i = NoOfElements - 2; 
		i >= 0; 
		i--)
		cout << arrayLiteralString[i];
	cout << endl << endl;

	cout << arrayCharString[0] << endl;
	cout << arrayCharString    << endl;
	cout << arrayLiteralString << endl << endl;

	char c;
	c = "MyString"[3];
	cout << c << endl;

	c = "MyString"[8];
	cout << c << endl << endl;

	NoOfElements = sizeof("A literal string") /
		           sizeof(char);
	cout << NoOfElements << endl;

	for (int i = 0; 
		i < NoOfElements; 
		i++)
		cout << "A literal string"[i];
	cout << endl << endl;

	const int array1Size = 5;
	int array1[array1Size];

	cout << array1Size << endl;

	for (int i = 0; 
		i < array1Size; 
		++i) {
		array1[i] = 666;
		cout << array1[i] << " ";;
	}
	cout << endl << endl;

	for (int& item : array1) {
		item = 777;
	}

	for (int& item : array1) {
		cout << item << " ";
	}

	cout << endl << endl;

	const string inputFileName = "numbers.txt";
	ifstream inputFileStream(inputFileName);

	const int NumbersInFileCount = 5;
	int inputArray[NumbersInFileCount];

	int index = 0;
	while (inputFileStream >> inputArray[index])
	{
		index++;
	}

	for (int item : inputArray)
		cout << item << " ";
	cout << endl << endl;

	int arrayA[] = { 0, 1, 2, 3 };

	NoOfElements = sizeof(arrayA) /
                   sizeof(int);
	cout << NoOfElements << endl;

	for (int& itemA : arrayA)
		cout << itemA << " ";
	cout << endl << endl;

	int arrayB[] = { 0,-1,-2,-3 };

	NoOfElements = sizeof(arrayB) /
		sizeof(arrayB[1]);
	cout << NoOfElements << endl ;

	for (int& itemB : arrayB)
		cout << itemB << " ";
	cout << endl << endl;

	index = 0;
	for (int item : { 10, 11, 12, 13 }) {
		arrayB[index] = item;
		index++;
	}

	for (int index = 0;
		index < (sizeof(arrayB) / sizeof(int));
		index++)
		cout << arrayB[index] << " ";
	cout << endl << endl;

	//arrayB = arrayA;     // syntax error

	for (int index = 0;
		index < (sizeof(arrayB) / sizeof(int));
		index++)
		arrayB[index] = arrayA[index];

	for (int index = 0;
		index < (sizeof(arrayB) / sizeof(int));
		index++)
		cout << arrayB[index] << " ";
	cout << endl << endl;

	return(EXIT_SUCCESS);

}