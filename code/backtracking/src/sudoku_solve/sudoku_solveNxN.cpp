#include<iostream>

using std ::cout;
using std ::cin;

const int n = 9;

int grid[n][n];

void input_grid() {
    //int i, j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
}

void print_grid() {
    //int i, j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}

bool can_be_placed(int row, int col, int num) {
   int ii = 0, jj = col;
    // row check
    while (ii < n) {
        if (grid[ii][jj] == num) {
            return false;
        }
        ii++;
    }
    // col check
    ii = row; jj = 0;
    while (jj < n) {
        if (grid[ii][jj] == num) {
            return false;
        }
        jj++;
    }
    // 3*3 check
    int startrow, startcol;
    startrow = (row / 3) * 3;
    startcol = (col / 3) * 3;
    for (ii = startrow; ii < startrow + 3; ii++) {
        for (jj = startcol; jj < startcol + 3; jj++) {
            if (grid[ii][jj] == num) {
                return false;
            }
        }
    }
    return true;
}

void sudoku_solver(int row, int col) {
    // cout<<row<<" "<<col<<'\n';
    if (row == n && col == 0) {
        print_grid();
        return ;
    }
    if (grid[row][col] == 0) {
        for (int num = 1; num <= n; num++) {
            if ((can_be_placed(row, col, num))) {
                grid[row][col] = num;
                if (col == n - 1) {
                    sudoku_solver(row + 1, 0);
                }
                else {
                    sudoku_solver(row, col + 1);
                }
                grid[row][col] = 0;
            }
        }
    }
    else {
        if (col == n - 1) {
            sudoku_solver(row + 1, 0);
        }
        else {
            sudoku_solver(row, col + 1);
        }
    }
}

int main()
{
    input_grid();
    sudoku_solver(0, 0);
}
//created by aryan 
