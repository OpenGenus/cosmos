/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <vector>

using namespace std;

/*
    This algorithm takes in a 2-dimensional vector and
    outputs its contents in a clockwise spiral form.

    Example Input:

    [ [  1   2   3   4 ],
      [  5   6   7   8 ],
      [  9  10  11  12 ],
      [ 13  14  15  16 ] ];

    Example Traversal:

    1  →  2  →  3  →  4
                      ↓
    5  →  6  →  7     8
    ↑           ↓     ↓
    9    10  ←  11   12
    ↑                 ↓
    13 ← 14  ←  15 ← 16

    Example Output:

    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

// Recursive implementation of printing a matrix in clockwise spiral form
// Informally, this function prints the outermost "ring" around the matrix,
// in a clockwise fashion, and then prints the next outermost "ring", and so on
//   Arguments:
//     mat: a 2-dimensional vector of ints
//
//     row_start/col_start: beginning index of matrix (i.e. 0, 0)
//
//     row_end/col_end: ending index of matrix (a 0-based index!)
//                      Ex. a 4 x 4 matrix would have an ending index of 3, 3
//                          a 5 x 6 matrix would have an ending index of 4, 5
//   Time Complexity: O(m*n)
//   Space Complexity: O(1), 2-d vector is passed by reference

void spiral_print(vector<vector<int> > &mat, int row_start, int col_start,
                                           int row_end, int col_end) {
    // check to see if we are "outside" the ring we are currently printing
    if (row_start > row_end || col_start > col_end) {
      return;
    }

    // Print top row
    for (int i = row_start; i <= col_end; i++) {
        cout << mat[row_start][i] << " ";
    }

    // Print rightmost column
    for (int i = row_start + 1; i <= row_end; i++) {
        cout << mat[i][col_end ] << " ";
    }

    // Print bottom row, only if this row hasn't been printed yet
    if (row_end != row_start) {
        for (int i = col_end - 1; i >= col_start; i--) {
            cout << mat[row_end][i] << " ";
        }
    }

    // Print leftmost column, only if this column hasn't been printed yet
    if (col_end != col_start) {
        for (int i = row_end - 1; i > row_start; i--) {
            cout << mat[i][col_start] << " ";
        }
    }

    // Function calls itself to print the next innermost "ring"
    spiral_print(mat, row_start + 1, col_start + 1, row_end - 1, col_end - 1);
}

// Driver
int main()
{
    // a 4x4 matrix
    vector<vector<int> > mat_a = { {1, 2, 3, 4},
                               { 12, 13, 14, 5},
                               { 11, 16, 15, 6},
                               { 10, 9, 8, 7} };

    spiral_print(mat_a, 0, 0, 3, 3);
    cout << '\n';

    // a 3x10 matrix
    vector<vector<int> > mat_b = { {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                                   {21, 22, 23, 24, 25, 26, 27, 28, 29, 10},
                                   {20, 19, 18, 17, 16, 15, 14, 13, 12, 11}};

    spiral_print(mat_b, 0, 0, 2, 9);
    cout << '\n';

    // a 12x4 matrix
    vector<vector<int> > mat_c = { {1, 2, 3, 4},
                                   {28, 29, 30, 5},
                                   {27, 48, 31, 6},
                                   {26, 47, 32, 7},
                                   {25, 46, 33, 8},
                                   {24, 45, 34, 9},
                                   {23, 44, 35, 10},
                                   {22, 43, 36, 11},
                                   {21, 42, 37, 12},
                                   {20, 41, 38, 13},
                                   {19, 40, 39, 14},
                                   {18, 17, 16, 15}};

    spiral_print(mat_c, 0, 0, 11, 3);
    cout << '\n';

}
