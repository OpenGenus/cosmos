#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 20;
    int a[n][n];
    // Passing the 20 * 20 array as input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                int prod = 1, flag = 0;
                for(int steps = 0; steps < 4; steps++)
                {
                    int u = i + steps * dr[k], v = j + steps * dc[k];
                    if(u >= 0 && u < n && v >= 0 && v < n)
                    {
                        prod *= a[u][v];
                    }
                    else 
                    {
                        flag = 1;
                    }
                }
                if(flag == 0) 
                {
                    ans = max(ans, prod);
                }
            }
        }
    }
    cout << ans;
}
