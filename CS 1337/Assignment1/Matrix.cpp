/*
Program Name: Assign Matrix Vertical Symmetry
Date: 2/5/2025
Author: Samuel Song
Module Purpose:
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_MATRIX_SIZE=20;
bool readMatrixFromFile (int matrix[][MAX_MATRIX_SIZE], unsigned& rows, unsigned& cols, ifstream&);
void displayMatrix (int matrix[][MAX_MATRIX_SIZE], unsigned, unsigned);
void displayCalcMatrixSums (int matrix[][MAX_MATRIX_SIZE], unsigned, unsigned, int[MAX_MATRIX_SIZE]);
void symmetryCheckMatrix (int matrix[], unsigned, unsigned);
void sortMatrixRows (int matrix[][MAX_MATRIX_SIZE], unsigned, unsigned);

int main()
{
    cout<<"Hello world";
    /*
    ifstream inputfile ("matrixes.txt");
    
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
    }

    //cout << "Press the enter key once or twice to continue..." << endl; cin.ignore(); cin.get();

    */
}

/*
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

/*
void displayMatrix (int [][MAX_MATRIX_SIZE],unsigned,unsigned)
{

}

void displayCalcMatrixSums (int[][MAX_MATRIX_SIZE],unsigned,unsigned,int[MAX_MATRIX_SIZE])
{

}

void symmetryCheckMatrix (int [],unsigned,unsigned)
{

}

void sortMatrixRows (int[][MAX_MATRIX_SIZE],unsigned,unsigned)
{

}
*/