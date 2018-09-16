#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

bool isSafe(char board[][100], int row, int column, int n)
{

    //check that whole row should not have a queen
    for (int i = 0; i < n; i++)
        if (board[row][i] == 'Q')
            return false;

    //check that whole column should not have a queen
    for (int i = 0; i < n; i++)
        if (board[i][column] == 'Q')
            return false;

    //check that left diagonal to the current cell should not have queen
    int p = row, q = column;
    while (p >= 0 && q >= 0)
    {
        if (board[p][q] == 'Q')
            return false;
        p--; q--;
    }

    //check that right diagonal to the current cell should not have queen
    p = row; q = column;
    while (p >= 0 && q <= n - 1)
    {
        if (board[p][q] == 'Q')
            return false;
        p--; q++;
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
