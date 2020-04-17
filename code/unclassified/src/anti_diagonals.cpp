/*
Give a N*N square matrix, return an array of its anti-diagonals.
Input:
1 2 3
4 5 6
7 8 9
Output :
[
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
*/
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> antiDiagonal(std::vector<std::vector<int>> a) {
    std::vector<std::vector<int>> result(
        (a.size() * 2) -
        1); // 2n-1 number of vectors are needed in the 2D vector
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            result[i + j].push_back(a[i][j]);
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Anti-Diagonals are : \n";
    std::vector<std::vector<int>> result = antiDiagonal(a);
    for (int i = 0; i < result.size(); i++) {
        for (int j : result[i])
            std::cout << j << " ";
        std::cout << "\n";
    }
    return 0;
}

