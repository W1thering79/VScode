/*
Program Name: Array Sort Using Pointers
Date: 2/18/2025
Author: Samuel Song
Module Purpose: 
*/

#include <iostream>
#include <fstream>

using namespace std;

bool ReadIntoDataArray(ifstream& inputFileStreamObj, unsigned& maxElements, int dataArray[], int* pointerArray[]);
void DisplayArray(int dataArray[], unsigned maxElements);
void DisplayArray(int* pointerArray[],unsigned maxElements);
void Sorting(int* pointerArray[],unsigned maxElements);
void SwapIntPtr(int** a,int** b);

int main()
{
    ifstream inputfile ("arrayData.txt");

    int dataArray[5];
    int *pointerArray[5];

    unsigned maxElements;

    while (ReadIntoDataArray(inputfile,maxElements,dataArray,pointerArray))
    {
        Sorting(pointerArray,maxElements);
        cout<<"Now displaying data in sorted order";
        DisplayArray(pointerArray,maxElements);
        cout<<"Now displaying data in the original order";
        DisplayArray(dataArray,maxElements);
        cout<<"Press the enter key once or twice to continue..."<<endl;cin.ignore();cin.get();
    }
}


bool ReadIntoDataArray(ifstream& inputFileStreamObj,unsigned& maxElements,int dataArray,int* pointerArray)
{
    for (unsigned i=0;i<maxElements;i++) 
    {
        inputFileStreamObj>>dataArray[i];
        pointerArray[i]=&dataArray[i];
    }
    return true;
}

void DisplayArray(int dataArray,unsigned maxElements)
{

}

void DisplayArray(int* pointerArray,unsigned maxElements)
{

}

void Sorting(int* pointerArray,unsigned maxElements)
{

}

void SwapIntPtr(int** a,int** b)
{

}