#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <numeric>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int int64_t

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void setneg(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < matrix.size(); ++i)
        if (matrix[i][col] != 0)
            matrix[i][col] = -2147483636;
    for (int j = 0; j < matrix[0].size(); ++j)
        if (matrix[row][j] != 0)
            matrix[row][j] = -2147483636;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        // taking input of number of rows & coloums
        int n, m;
        cin >> n >> m;
        // creating a matrix of size n*m and taking input
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    setneg(matrix, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j]==-2147483636)
                {
                    matrix[i][j]=0;
                }
            }
        }
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
