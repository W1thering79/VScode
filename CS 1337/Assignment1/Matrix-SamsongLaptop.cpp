/*
Program Name: Assign Matrix Vertical Symmetry
Date: 2/5/2025
Author: Samuel Song
Module Purpose: The purpose of the program is to read a matrix from a text file, determine if it is 
vertically additive symmetry (output t/f depending on result) and then sort each row from least to greatest.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_MATRIX_SIZE=20;
bool readMatrixFromFile (int matrix[][MAX_MATRIX_SIZE], unsigned& rows, unsigned& cols, ifstream&);
void displayMatrix (int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols);
void displayCalcMatrixSums (int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols, int[MAX_MATRIX_SIZE]);
void symmetryCheckMatrix (int matrix[], unsigned rows, unsigned cols);
void sortMatrixRows (int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols);

int main()
{
    ifstream inputfile ("matrixes.txt");
    
    //Validates if the textfile was successfully opened.
    if (!inputfile.is_open())
    {
        cout<<"Error: File failed to open."<<endl;
        return 0;
    }

    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    unsigned rows,cols;


    while (readMatrixFromFile(matrix,rows,cols,inputfile))
    {
        displayMatrix(matrix,rows,cols);

        int columnsum[MAX_MATRIX_SIZE];
        displayCalcMatrixSums(matrix,rows,cols,columnsum);

        symmetryCheckMatrix(columnsum,rows,cols);

        sortMatrixRows(matrix,rows,cols);

        cout << "Press the enter key once or twice to continue..." << endl; cin.ignore(); cin.get();
    }

    inputfile.close();
    return 0;
}


//Function reads the matrix from file by iterating through each row/column 
bool readMatrixFromFile (int matrix[][MAX_MATRIX_SIZE],unsigned& rows,unsigned& cols,ifstream& inputfile)
{
    if (inputfile>>rows>>cols)
    {
        for (int i=0;i<rows;++i)
        {
            for (int j=0;j<cols;++j)
            {
                inputfile>>matrix[i][j];
            }
        }
        return true;
    }
    return false;
}

//Function in charge of displaying the matrix that was read from the previous function
void displayMatrix (int matrix[][MAX_MATRIX_SIZE],unsigned rows,unsigned cols)
{
    cout<<"Input:"<<endl;
    for (unsigned i=0; i<rows;++i)
    {
        for (unsigned j=0;j<cols;++j)
        {
            cout<<setw(10)<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

//Calculates the sum of each columns by adding each row value of each column and printing out
void displayCalcMatrixSums (int matrix[][MAX_MATRIX_SIZE],unsigned rows,unsigned cols,int columnsum[MAX_MATRIX_SIZE])
{
    cout<<"Sums:"<<endl;
    for (unsigned j=0;j<cols;++j)
    {
        columnsum[j]=0;
        for (unsigned i=0;i<rows;++i)
        {
            columnsum[j]+=matrix[i][j];
        }
        cout<<setw(10)<<columnsum[j];
    }
    cout<<endl;
}

//Function determines whether or not the sum of the column is symmetric with the opposite side of the matrix
void symmetryCheckMatrix (int columnsum[],unsigned rows,unsigned cols)
{
    bool isSymmetrical=true;
    for (unsigned i=0;i<rows;++i)
    {
        for (unsigned j=0;j<cols/2;++j)
        {
            if (columnsum[j]!=columnsum[cols-j-1])
            {
            isSymmetrical=false;
            break;
            }
        }
    }

    if (isSymmetrical)
    {
        cout<<"Vertical Additive Symmetry:True"<<endl;
    }
    else
    {
        cout<<"Vertical Additive Symmetry:False"<<endl;
    }
}

//Function iterates for each row and column, uses bubble sort.
void sortMatrixRows (int matrix[][MAX_MATRIX_SIZE],unsigned rows,unsigned cols)
{
    for (unsigned i=0;i<rows;i++)
    {
        for (unsigned j=0;j<cols-1;j++) 
        {
            for (unsigned k=0;k<cols-j-1;k++) 
            {
                if (matrix[i][k]>matrix[i][k+1]) 
                {
                    int temp=matrix[i][k];
                    matrix[i][k]=matrix[i][k+1];
                    matrix[i][k+1]=temp;
                }
            }
        }
    }
    cout<<"Sorted:"<<endl;
    for (unsigned i=0; i<rows;++i)
    {
        for (unsigned j=0;j<cols;++j)
        {
            cout<<setw(10)<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

