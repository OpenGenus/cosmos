/* Part of Cosmos by OpenGenus Foundation */

/*
 * 2D Fenwick tree to solve sub-matrix sum query.
 */

#include <iostream>
#include <vector>

class FenwickTree
{
    // Matrix to store the tree
    std::vector<std::vector<int>> ft;

public:
    // Function to get least significant bit
    int LSB (int x)
    {
        return x & (-x);
    }

    int query (int x, int y)
    {
        int sum = 0;
        for (int x_ = x; x_ > 0; x_ = x_ - LSB(x_))
            for (int y_ = y; y_ > 0; y_ = y_ - LSB(y_))
                sum = sum + ft[x_][y_];
        return sum;
    }

    int query (int x1, int y1, int x2, int y2)
    {
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
    }

    void update (int x, int y, int value)
    {
        // also update matrix[x][y] if needed.

        for (int x_ = x; x_ < ft.size(); x_ = x_ + LSB(x_))
            for (int y_ = y; y_ < ft[0].size(); y_ = y_ + LSB(y_))
                ft[x_][y_] += value;
    }

    FenwickTree(std::vector<std::vector<int>> matrix)
    {
        int n = matrix.size();
        // matrix must not be empty.
        int m = matrix[0].size();
        // Initialize matrix ft
        ft.assign(m + 1, std::vector<int> (n + 1, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                update(i + 1, j + 1, matrix[i][j]);
    }
};

int main ()
{
    //sample code
    std::vector<std::vector<int>> matrix = {std::vector<int>({1, 1, 2, 2}),
                              std::vector<int>({3, 3, 4, 4}),
                              std::vector<int>({5, 5, 6, 6}),
                              std::vector<int>({7, 7, 8, 8})};
    FenwickTree ft(matrix);
    std::cout << "Matrix is\n";
    for (int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << "Sum of submatrix ((2, 2), (4, 4)) is " << ft.query(2, 2, 4, 4) << '\n';

    std::cout << "After changing 3 at (2, 2) to 10, matrix is\n";
    matrix[2 - 1][2 - 1] += 7;
    ft.update(2, 2, 7);
    std::cout << "Matrix is\n";
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << "Sum of submatrix ((2, 2), (4, 4)) is " << ft.query(2, 2, 4, 4) << '\n';

    return 0;
}
