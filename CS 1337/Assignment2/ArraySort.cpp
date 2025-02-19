/*
Program Name: Array Sort Using Pointers
Date: 2/18/2025
Author: Samuel Song
Module Purpose: Gets the value data from the arrayData.txt and sorts using bubble sort
and inputted into pointerArray to then be displayed alongside dataArray for the user to see.
*/

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

bool ReadIntoDataArray(ifstream& inputFileStreamObj, unsigned& maxElements, int dataArray[], int* pointerArray[]);
void DisplayArray(int dataArray[], unsigned maxElements);
void DisplayArray(int* pointerArray[],unsigned maxElements);
void Sorting(int* pointerArray[],unsigned maxElements);
void SwapIntPtr(int** a,int** b);

int main()
{
    ifstream inputfile ("arrayData.txt");

    //Size declaration for arrays
    int dataArray[10];
    int *pointerArray[10];

    unsigned maxElements;

    while (ReadIntoDataArray(inputfile,maxElements,dataArray,pointerArray))
    {
        Sorting(pointerArray,maxElements);
        cout<<"Now displaying data in sorted order:"<<endl;
        DisplayArray(pointerArray,maxElements);
        cout<<"Now displaying data in the original order:"<<endl;
        DisplayArray(dataArray,maxElements);
        cout<<"Press the enter key once or twice to continue..."<<endl;cin.ignore();cin.get();
    }
}

//Reads the data that is stored in arrayData.txt file
bool ReadIntoDataArray(ifstream& inputFileStreamObj,unsigned& maxElements,int dataArray[],int* pointerArray[])
{
    inputFileStreamObj>>maxElements;
    for (unsigned i=0;i<maxElements;i++) 
    {
        if (!(inputFileStreamObj>>dataArray[i]))
        {
            return false;
        }
        pointerArray[i]=&dataArray[i];
    }
    return true;
}

//Display function for dataArray, array of unsorted values 
void DisplayArray(int dataArray[],unsigned maxElements)
{
    for (unsigned i=0;i<maxElements;i++)
    {
        cout<<dataArray[i]<<" ";
    }
    cout<<endl;
}

//Display function for pointerArray, array of sorted values
void DisplayArray(int* pointerArray[],unsigned maxElements)
{
    for (unsigned i=0;i<maxElements;i++)
    {
        cout<<*pointerArray[i]<<" ";
    }
    cout<<endl;
}

//Sorting function. Iterates through pointerArray values to sort and calls the SwapIntPtr function. 
void Sorting(int* pointerArray[],unsigned maxElements)
{
    for (int i=0;i<maxElements-1;i++) 
    {
        for (int j=0;j<maxElements-i-1;j++)
        {
            if (*pointerArray[j]>*pointerArray[j+1])
            {
                SwapIntPtr(&pointerArray[j],&pointerArray[j+1]);
            }
        }
    }
}

//Function dedicated to swapping two int pointer values.
void SwapIntPtr(int** a,int** b)
{
    int* temp=*a;
    *a=*b;
    *b=temp;
}
