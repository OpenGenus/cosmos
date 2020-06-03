#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

bool isSafe(char board[][100], int row, int column, int n)
{
    int dir[][] = {{-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}};
    for (int i = 0; i < 8; i++)
    {
        for (int rad = 1; rad < n; rad++)
        {
            int new_row = row + rad * dir[i][0];
            int new_column = column + rad * dir[i][1];
            if (new_row < 0 || new_column < 0 || new_row >= n || new_column >= n)
                break;
            if (board[new_row][new_column]=='Q')
                return false;
        }
    }
    return true;
}

bool nqueen(char board[][100], int n, int i = 0)
{
    if (i == n)
    {
        //board is filled with the n-queens, just print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        return true;         //hack :: if to print all possible combination just make it false
    }

    for (int j = 0; j < n; j++)
        if (isSafe(board, i, j, n))         //check that cell is safe or not
        {
            board[i][j] = 'Q';             //if it's safe, then place a queen at that cell
            if (nqueen(board, n, i + 1))          //now searching place for queen in next row
                return true;
            board[i][j] = '.';             //since, not safe, so again mark that cell with '.'
        }
    return false;
}

int main()
{
    int n;
    cin >> n;

    char board[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '.';

    if (!nqueen(board, n))
        cout << "No state possible!";

    return 0;
}
