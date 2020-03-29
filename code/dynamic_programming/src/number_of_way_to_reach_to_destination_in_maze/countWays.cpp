#include<bits/stdc++.h>
using namespace std;
int n, m;
int dp[1000][1000];

int getCount (int i, int j, int n, int m, int dp[1000][1000])
{
  if (dp[i][j] != -1)
    {
      return dp[i][j];
    }
  if (i == n - 1 && j == m - 1)
    {
      return 0;
    }
  if (i == n - 1 || j == m - 1)
    {
      return 1;
    }
  return dp[i][j] =
    getCount (i + 1, j, n, m, dp) + getCount (i, j + 1, n, m, dp);
}

int main ()
{

  cout << "Enter maze size" << endl;
  cout << "Enter row" << endl;
  cin >> n;
  cout << "Enter column" << endl;
  cin >> m;
  for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
	{
	  dp[i][j] = -1;
	}
    }
  int ways = getCount (0, 0, n, m, dp);
  cout << "Number of ways to destination: " << ways;
}
