#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

// Function prototypes
int getTotal(int array[ROWS][COLS]);
double getAverage(int array[ROWS][COLS]);
int getRowTotal(int array[ROWS][COLS], int row);
int getColumnTotal(int array[ROWS][COLS], int col);
int getHighestInRow(int array[ROWS][COLS], int row);
int getLowestInRow(int array[ROWS][COLS], int row);

int main() {
    int bonusPoints[ROWS][COLS];
    ofstream outFile("bonus_points.txt");
    ifstream inFile("bonus_points.txt");
    srand(time(0));

    // Generate 100 random numbers between 50 and 1200, write to file
    for (int i = 0; i < 100; i++) {
        int randomValue = 50 + rand() % (1200 - 50 + 1);
        outFile << randomValue << " ";
    }
    outFile.close();

    // Read the file and populate the 2D array
    if (inFile.is_open()) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                inFile >> bonusPoints[i][j];
            }
        }
        inFile.close();
    } else {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Display total and average of all values
    cout << "Total: " << getTotal(bonusPoints) << endl;
    cout << "Average: " << getAverage(bonusPoints) << endl;

    // Example function usage for row and column totals, highest, and lowest
    int row = 9, col = 9;  // Adjust these values as needed
    cout << "Total of row " << (row+1) << ": " << getRowTotal(bonusPoints, row) << endl;
    cout << "Total of column " << (col+1) << ": " << getColumnTotal(bonusPoints, col) << endl;
    cout << "Highest in row " << row << ": " << getHighestInRow(bonusPoints, row) << endl;
    cout << "Lowest in row " << row << ": " << getLowestInRow(bonusPoints, row) << endl;

    return 0;
}

// Function definitions
int getTotal(int array[ROWS][COLS]) {
    int total = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total += array[i][j];
        }
    }
    return total;
}

double getAverage(int array[ROWS][COLS]) {
    return static_cast<double>(getTotal(array)) / (ROWS * COLS);
}

int getRowTotal(int array[ROWS][COLS], int row) {
    int total = 0;
    for (int j = 0; j < COLS; j++) {
        total += array[row][j];
    }
    return total;
}

int getColumnTotal(int array[ROWS][COLS], int col) {
    int total = 0;
    for (int i = 0; i < ROWS; i++) {
        total += array[i][col];
    }
    return total;
}

int getHighestInRow(int array[ROWS][COLS], int row) {
    int highest = array[row][0];
    for (int j = 1; j < COLS; j++) {
        if (array[row][j] > highest) {
            highest = array[row][j];
        }
    }
    return highest;
}

int getLowestInRow(int array[ROWS][COLS], int row) {
    int lowest = array[row][0];
    for (int j = 1; j < COLS; j++) {
        if (array[row][j] < lowest) {
            lowest = array[row][j];
        }
    }
    return lowest;
}
