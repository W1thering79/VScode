#include <iostream>
#include <string>

using namespace std;

void displayArray(int displayArray[], int noOfItems) {
	for (int i = 0; 
		i < noOfItems; 
		++i)
		cout<<displayArray[i] << " ";
	cout << endl << endl;
}

void functionArray(int arrayInside[], int noOfItems) {

	displayArray(arrayInside, noOfItems);

}

void functionChangeArray(int arrayInside[], int noOfItems) {

	displayArray(arrayInside, noOfItems);
	for (int i = 0; 
		i < noOfItems; 
		i++)
		arrayInside[i] = 7;
	displayArray(arrayInside, noOfItems);
}


int main() {

	int arrayA[] = { 0, 1, 2, 3 };

	int noOfItems = sizeof (arrayA) / sizeof(int);

	displayArray(arrayA, noOfItems);

	functionArray(arrayA, noOfItems);

	displayArray(arrayA, noOfItems);


	displayArray(arrayA, noOfItems);

	functionChangeArray(arrayA, noOfItems);

	displayArray(arrayA, noOfItems);

}
