#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const unsigned noOfRows = 2;
const unsigned noOfCols = 5;


void FunctionArray(int matrixInside[][noOfCols]) {

    for (unsigned row = 0;
        row < noOfRows;
        ++row) {
        for (unsigned col = 0; 
            col < noOfCols; 
            ++col)
            cout << setw(5) << matrixInside[row][col];
        cout << endl;
    }
    cout << endl;

}

void FunctionArrayChange(int matrixInside[][noOfCols]) {

    for (unsigned row = 0;
        row < noOfRows;
        ++row)
        for (unsigned col = 0; 
            col < noOfCols; 
            ++col)
            matrixInside[row][col] = 666;

}


int main() {

    const unsigned noOfColsSize = 5;
          unsigned noOfRows;
          unsigned noOfCols;

    int matrix[][noOfColsSize] = { 
        {1, 2, 3, 4,  5},
        {6, 7, 8, 9, 10}
    };

    noOfRows = sizeof matrix    / sizeof matrix[0];   
    noOfCols = sizeof matrix[0] / sizeof(int);

    cout << noOfRows << " " << noOfCols << endl;

    for (unsigned row = 0; 
        row < noOfRows; 
        ++row) {
        for (unsigned col = 0; 
            col < noOfCols; 
            ++col)
            cout << setw(5) << matrix[row][col];
        cout << endl;
    }
    cout << endl;

    for (auto &row : matrix) {
        for (auto col : row)
            cout << setw(5) << col;
        cout << endl;
    }

    for (unsigned row = 0; 
        row < noOfRows; 
        ++row)
        for (unsigned col = 0; 
            col < noOfCols; 
            ++col)
            matrix[row][col] = 99;
    cout << endl;

    for (unsigned row = 0; 
        row < noOfRows; 
        ++row) {
        for (unsigned col = 0; 
            col < noOfCols; 
            ++col)
            cout << setw(5) << matrix[row][col];
        cout << endl;
    }
    cout << endl;

    for (auto& row : matrix) {
        for (auto& col : row)
            col = 0;
        cout << endl;
    }

    for (auto& row : matrix) {
        for (auto col : row)
            cout << setw(5) << col;
        cout << endl;
    }
    cout << endl;

    int count = 1;
    for (auto& row : matrix) {
        for (auto& col : row)
            col = count++;
    }

    for (auto& row : matrix) {
        for (auto col : row)
            cout << setw(5) << col;
        cout << endl;
    }
    cout << endl;

    for (int row = noOfRows-1;
        row >= 0;
        --row) {
        for (int col = noOfCols - 1;
            col >= 0;
            --col)
            cout << setw(5) << matrix[row][col];
        cout << endl;
    }
    cout << endl;

    FunctionArray(matrix);
    
    for (auto& row : matrix) {
        for (auto col : row)
            cout << setw(5) << col;
        cout << endl;
    }
    cout << endl;

    FunctionArrayChange(matrix);
    
    for (auto& row : matrix) {
        for (auto col : row)
            cout << setw(5) << col;
        cout << endl;
    }
    cout << endl;

    exit(EXIT_SUCCESS);
}