#include <iostream>
#include <fstream>
#include <iomanip>   // for formatting
using namespace std;

const int MAX_MATRIX_SIZE = 20; // Maximum number of rows or columns

// Function prototypes
bool readMatrixFromFile(int matrix[][MAX_MATRIX_SIZE], unsigned& rows, unsigned& cols, ifstream& inputFile);
void displayMatrix(int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols);
void displayCalcMatrixSums(int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols, int columnSums[MAX_MATRIX_SIZE]);
void symmetryCheckMatrix(int columnSums[MAX_MATRIX_SIZE], unsigned cols);
void sortMatrixRows(int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols);

int main() {
    ifstream inputFile("matrixes.txt");
    
    // Check if the file was opened successfully
    if (!inputFile) {
        cout << "Failed to open the file 'matrixes.txt'. Please ensure the file exists in the correct location." << endl;
        return 1;  // Exit the program if the file cannot be opened
    }

    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    unsigned rows, cols;
    
    while (readMatrixFromFile(matrix, rows, cols, inputFile)) {
        displayMatrix(matrix, rows, cols);

        int columnSums[MAX_MATRIX_SIZE];
        displayCalcMatrixSums(matrix, rows, cols, columnSums);

        symmetryCheckMatrix(columnSums, cols);

        sortMatrixRows(matrix, rows, cols);
        displayMatrix(matrix, rows, cols);  // Display sorted matrix rows

        cout << "Press the enter key once or twice to continue..." << endl;
        cin.ignore(); cin.get();  // Pause the screen
    }

    inputFile.close();
    return 0;
}

bool readMatrixFromFile(int matrix[][MAX_MATRIX_SIZE], unsigned& rows, unsigned& cols, ifstream& inputFile) {
    if (inputFile >> rows >> cols) {
        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                inputFile >> matrix[i][j];
            }
        }
        return true;
    }
    return false;  // Return false when we reach the end of the file or fail to read
}

void displayMatrix(int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols) {
    cout << "Matrix:" << endl;
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];  // Displaying each element with proper spacing
        }
        cout << endl;
    }
}

void displayCalcMatrixSums(int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols, int columnSums[MAX_MATRIX_SIZE]) {
    cout << "Column Vertical Additive Sums:" << endl;
    for (unsigned j = 0; j < cols; ++j) {
        columnSums[j] = 0;
        for (unsigned i = 0; i < rows; ++i) {
            columnSums[j] += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << columnSums[j] << endl;
    }
}

void symmetryCheckMatrix(int columnSums[MAX_MATRIX_SIZE], unsigned cols) {
    bool isSymmetric = true;
    for (unsigned i = 0; i < cols / 2; ++i) {
        if (columnSums[i] != columnSums[cols - i - 1]) {
            isSymmetric = false;
            break;
        }
    }
    if (isSymmetric) {
        cout << "This matrix has vertical additive symmetry." << endl;
    } else {
        cout << "This matrix does not have vertical additive symmetry." << endl;
    }
}

void sortMatrixRows(int matrix[][MAX_MATRIX_SIZE], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols - 1; ++j) {
            for (unsigned k = j + 1; k < cols; ++k) {
                if (matrix[i][j] > matrix[i][k]) {
                    swap(matrix[i][j], matrix[i][k]);
                }
            }
        }
    }
}
