#include <iostream>
#include <fstream>

using namespace std;

// Function prototypes
bool ReadIntoDataArray(ifstream &inputFileStreamObj, unsigned &maxElements, int dataArray[], int *pointerArray[]);
void DisplayArray(int dataArray[], unsigned maxElements);
void DisplayArray(int *pointerArray[], unsigned maxElements);
void Sorting(int *pointerArray[], unsigned maxElements);
void SwapIntPtr(int **a, int **b);

int main() {
    ifstream inputFile("arrayData.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int dataArray[10];
    int *pointerArray[10];
    unsigned maxElements;

    while (ReadIntoDataArray(inputFile, maxElements, dataArray, pointerArray)) {
        cout << "Now displaying data in sorted order:\n";
        Sorting(pointerArray, maxElements);
        DisplayArray(pointerArray, maxElements);
        cout << "\nNow displaying data in the original order:\n";
        DisplayArray(dataArray, maxElements);
        cout << "\nPress the enter key once or twice to continue...";
        cin.ignore();
        cin.get();
    }

    inputFile.close();
    cout << "\nProgram Done" << endl;
    return 0;
}

bool ReadIntoDataArray(ifstream &inputFileStreamObj, unsigned &maxElements, int dataArray[], int *pointerArray[]) {
    if (!(inputFileStreamObj >> maxElements) || maxElements > 10) {
        return false;
    }
    
    for (unsigned i = 0; i < maxElements; i++) {
        inputFileStreamObj >> dataArray[i];
        pointerArray[i] = &dataArray[i];
    }
    return true;
}

void DisplayArray(int dataArray[], unsigned maxElements) {
    for (unsigned i = 0; i < maxElements; i++) {
        cout << dataArray[i] << " ";
    }
    cout << endl;
}

void DisplayArray(int *pointerArray[], unsigned maxElements) {
    for (unsigned i = 0; i < maxElements; i++) {
        cout << *(pointerArray[i]) << " ";
    }
    cout << endl;
}

void Sorting(int *pointerArray[], unsigned maxElements) {
    for (unsigned outIndex = maxElements - 1; outIndex > 0; outIndex--) {
        for (unsigned innerIndex = 0; innerIndex < outIndex; innerIndex++) {
            if (*(pointerArray[innerIndex]) > *(pointerArray[innerIndex + 1])) {
                SwapIntPtr(&pointerArray[innerIndex], &pointerArray[innerIndex + 1]);
            }
        }
    }
}

void SwapIntPtr(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}
