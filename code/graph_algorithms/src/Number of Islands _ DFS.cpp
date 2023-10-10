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
    int numIslands(vector<vector<char>> &grid)
    {
        // By the method of DFS
        // Time Complexity of code: O(m*n)
        // Auxillary Space Complexity of code: O(m*n)
        int ans = solver(grid);
        return ans;
    }
};
