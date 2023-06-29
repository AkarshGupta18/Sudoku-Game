#include <iostream>
using namespace std;

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a given number can be placed in a particular cell
bool isSafe(int grid[9][9], int row, int col, int num) {
    // Check if the number already exists in the row or column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number already exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                // Try placing numbers 1-9
                for (int num = 1; num <= 9; num++) {
                    // Check if the number can be placed in the cell
                    if (isSafe(grid, row, col, num)) {
                        // Place the number in the cell
                        grid[row][col] = num;

                        // Recursively solve the rest of the puzzle
                        if (solveSudoku(grid)) {
                            return true;
                        }

                        // If the number doesn't lead to a solution, backtrack
                        grid[row][col] = 0;
                    }
                }

                // If no number can be placed, the puzzle is unsolvable
                return false;
            }
        }
    }

    // If all cells are filled, the puzzle is solved
    return true;
}

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku puzzle:" << endl;
    printGrid(grid);
    cout << endl;

    if (solveSudoku(grid)) {
        cout << "Solution found:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for the given puzzle." << endl;
    }

    return 0;
}
