#include <iostream>
#include <vector>

using namespace std;


void printBoard(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}


bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();


    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}


bool solveNQueens(vector<vector<int>>& board, int col) {
    int N = board.size();

    
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            
            board[i][col] = 1;

            
            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    
    return false;
}

int main() {
    int N;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution for " << N << "-Queens problem:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the " << N << "-Queens problem." << endl;
    }

    return 0;
}
