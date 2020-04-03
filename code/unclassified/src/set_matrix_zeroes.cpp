/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire
row and column to 0. Note: This will be evaluated on the extra memory used. Try
to minimize the space and time complexity.
*/
#include <cstdlib>
#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>> &A) {

    const int m = A.size();
    const int n = A[0].size();
    std::vector<bool> row_zeroes(m);
    std::vector<bool> col_zeroes(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 0) {
                row_zeroes[i] = true;
                col_zeroes[j] = true;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row_zeroes[i] || col_zeroes[j]) {
                A[i][j] = 0;
            }
        }
    }
}

int main() {
    int row, col;
    std::cout << "Enter the row size of the Matrix : ";
    std::cin >> row;
    std::cout << "Enter the col size of the Matrix : ";
    std::cin >> col;
    std::vector<std::vector<int>> A(row);
    std::cout << "Enter the values for the Matrix : \n";
    for (int i = 0; i < row; ++i) {
        // declare  the i-th row to size of column
        A[i] = std::vector<int>(col);
        for (int j = 0; j < col; j++)
            std::cin >> A[i][j];
    }

    std::cout << "Input Matrix : \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < A[i].size(); j++)
            std::cout << A[i][j] << " ";
        std::cout << "\n";
    }

    setZeroes(A);

    std::cout << "Output Matrix : \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < A[i].size(); j++)
            std::cout << A[i][j] << " ";
        std::cout << "\n";
    }
}

/*Sample Input-Output
Enter the row size of the Matrix : 3
Enter the col size of the Matrix : 3
Enter the values for the Matrix :
1 0 1
1 1 1
1 1 0
Input Matrix :
1 0 1
1 1 1
1 1 0
Output Matrix :
0 0 0
1 0 0
0 0 0
*/