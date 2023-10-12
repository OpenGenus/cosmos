#include <iostream>
#include <vector>

using namespace std;

const int N = 9; 


void printSudoku(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }


    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}


bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;

    
    bool foundEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) {
            break;
        }
    }

    
    if (!foundEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            
            if (solveSudoku(grid)) {
                return true; 
            }

            
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> sudokuGrid(N, vector<int>(N, 0));

    cout << "Enter the Sudoku puzzle (0 for empty cells, separate digits with spaces):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudokuGrid[i][j];
        }
    }

    if (solveSudoku(sudokuGrid)) {
        cout << "Solved Sudoku:" << endl;
        printSudoku(sudokuGrid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
