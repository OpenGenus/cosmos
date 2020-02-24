#include <iostream>
using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
 */
 
const int N =9;
 /* 
    we can use lookups to directly get the issafe values. since number is till 9 
    we can use int value till 2^10 which is easy to manage.

    For example, if row specific row has 3 in it then the number in should 
    have 4th place in binary should be 1 (1xxx)

    same logic for others as well

    decreases time complexity for isPossible
*/
int safeRow[9];
int safeCol[9];
int safeGrid[3][3];

// using bit shifting 
// this function tells if element 'b' is already present in the entity 'a'(row/column/subgrid)
bool isAlready(int a, int b) {
    if((a >> b) & 1) {
        return true;
    }

    return false;
}

bool isPossible(int mat[][9], int i, int j, int no)
{
    ///Row and column and subgrid should not have no in the digits 
    if(isAlready(safeRow[i], no) || isAlready(safeCol[j], no) || isAlready(safeGrid[i/3][j/3], no)) {
        return false;
    }
    
    return true;
}
void printMat(int mat[][9])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << '\t';

        }
        if ((i + 1) % 3 == 0)
            cout << endl;
        cout << endl;
    }
}


bool solveSudoku(int mat[][9], int i, int j)
{
    ///Base Case
    if (i == 9)
    {
        printMat(mat);
        return true;
    }

    ///Crossed the last  Cell in the row
    if (j == 9)
        return solveSudoku(mat, i + 1, 0);

    ///Skip if filled cell
    if (mat[i][j] != 0)
        return solveSudoku(mat, i, j + 1);
    ///White Cell
    ///Try to place every possible no
    for (int no = 1; no <= 9; no++)
        if (isPossible(mat, i, j, no))
        {
            ///Place the no - assuming solution is possible with this
            mat[i][j] = no;
            int adder = (1 << no);
            safeRow[i] += adder;
            safeCol[j] += adder;
            safeGrid[i/3][j/3] += adder;

            bool isSolve = solveSudoku(mat, i, j + 1);
            if (isSolve)
                return true;
                
            ///loop will place the next no.
            
            ///Backtracking
            safeRow[i] -= adder;
            safeCol[j] -= adder;
            safeGrid[i/3][j/3] -= adder;
        }
        ///Backtracking
        mat[i][j] = 0;

    return false;
}

void initlookupvalues(int mat[][N]) {
    for(int i = 0; i < 9; i++) {
        safeRow[i] = 0;
        safeCol[i] = 0;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            safeGrid[i][j] = 0;
        }
    }
    // creating lookup for already present numbers
    for(int i = 0 ;i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(mat[i][j] != 0) {
                int adder = (1 << mat[i][j]);
                safeRow[i] += adder;
                safeCol[j] += adder;
                safeGrid[i/3][j/3] += adder;
            }
        }
    }
} 

int main()
{

    int mat[9][9] =
    {{5, 3, 0, 0, 7, 0, 0, 0, 0},
     {6, 0, 0, 1, 9, 5, 0, 0, 0},
     {0, 9, 8, 0, 0, 0, 0, 6, 0},
     {8, 0, 0, 0, 6, 0, 0, 0, 3},
     {4, 0, 0, 8, 0, 3, 0, 0, 1},
     {7, 0, 0, 0, 2, 0, 0, 0, 6},
     {0, 6, 0, 0, 0, 0, 2, 8, 0},
     {0, 0, 0, 4, 1, 9, 0, 0, 5},
     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    printMat(mat);
    initlookupvalues(mat);
    cout << "Solution " << endl;
    solveSudoku(mat, 0, 0);
    return 0;
}
