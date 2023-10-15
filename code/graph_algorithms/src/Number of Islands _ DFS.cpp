#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfsTraversal(int row, int col, vector<int> &delr, vector<int> &delc, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        // delr = {-1, 0, 1 ,0};
        // delc = {0, -1, 0, 1};
        vis[row][col] = true;
        int total_rows = grid.size();
        int total_columns = grid[0].size();
        for (int i = 0; i < 4; i++)
        {
            int new_row = row + delr[i];
            int new_col = col + delc[i];
            if (new_row >= 0 && new_row < total_rows && new_col >= 0 && new_col < total_columns)
            {
                // checked validity of new row and new column
                if (grid[new_row][new_col] == '1' && vis[new_row][new_col] == 0)
                {
                    dfsTraversal(new_row, new_col, delr, delc, grid, vis);
                }
            }
        }
    }
    int solver(vector<vector<char>> &grid)
    {
        int total_rows = grid.size();
        int total_columns = grid[0].size();
        vector<vector<bool>> vis(total_rows, vector<bool>(total_columns, false));
        int count = 0;
        vector<int> delr = {-1, 0, 1, 0}; // change in row
        vector<int> delc = {0, -1, 0, 1}; // change in column
        // changes from one cell to another cell in 4 directions given by corresponding values at same index in delr and delc
        for (int row = 0; row < total_rows; row++)
        {
            for (int col = 0; col < total_columns; col++)
            {
                if (grid[row][col] == '1' && vis[row][col] == false)
                {
                    count++;
                    dfsTraversal(row, col, delr, delc, grid, vis);
                }
            }
        }
        return count;
    }

public:
    Solution(vector<vector<char>> &grid)
    {
        // constructor created
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // By the method of DFS
        // Time Complexity of code: O(m*n)
        // Auxillary Space Complexity of code: O(m*n)
        // LeetCode link: https://leetcode.com/problems/number-of-islands/description/

        // Sample Input 1 (for LeetCode): [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
        /*
        In the sample input, "1" represents a land piece, and "0" represents a water area.
        The grid is a m*n matrix with m rows and n columns, here, m being 4 and n being 5.
        The grid is in the form of a 2D array/vector in the input as given above.
        Visualizing the input more effectively,
        [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        */

        /* Sample Input 2 (for terminal): [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
        4 5
        1 1 1 1 0
        1 1 0 1 0
        1 1 0 0 0
        0 0 0 0 0
        */
        /*
        In the sample input, the first line has two integers: m and n.
        m represents the number of rows and n represents the number of columns.
        1 represents a land piece, and 0 represents a water area.
        The grid is a m*n matrix with m rows and n columns, here, m being 4 and n being 5.
        The grid is in the form of a 2D array/vector in the input as given above.
        */

        int ans = solver(grid);
        return ans;
    }
};

int main()
{
    // Number_of_Islands
    //  LeetCode link: https://leetcode.com/problems/number-of-islands/description/
    int m, n;
    cout << "Number of rows and columns: ";
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    cout << "The grid: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution soln(grid);
    int solution = soln.numIslands(grid);
    cout << "The number of Islands: " << solution << endl;
    return 0;
}
