#include<bits/stdc++.h>
using namespace std;
/*
 *
 * Part of Cosmos by OpenGenus Foundation
 *
 * Description:
 *  1. We will start with inputing the number of row n and column m.
 *  2. We will make memorization table dp[0..n][0..m] for storing precomputed values and fill that matrix with -1
 *  3. We will create function getCount(), which have parameter i represent index along row , j represent index along col, 
 *	   n represent size of row, m represent size of columns and dp[0..n][0..m] used to store the precomputed value	   
 *  4. We take a top-down approach, first filling dp[0..n][0..m] = -1
 *  5. Now, for each (i, j, n, m, dp) we will start moving recuesively along row and column, till we find destination
 *     
 *     Case 1: If we reach the destination or out of the box, we will return 1, which represent 
 *             that their is possible way present to reach destination in maze.
 *  6. We get the formula: dp[i][j] = getCount(i+1, j, n, m, dp) + getCount(i, j+1, n, m, dp)
 *						we will return value, If it is present in the dp[0..n][0..m] 
 *
 */
int n, m;
#create the dp table for storing the data
int dp[1000][1000];

int getCount (int i, int j, int n, int m, int dp[1000][1000])
{
	#return already computed value
	if (dp[i][j] != -1){
      	return dp[i][j];
	}
	#check that it reached the destination or got out of the matrix, if so,return 1
	if (i == n - 1 || j == m - 1){
      	return 1;
	}
	# return the total number of way to reach the destination
	return dp[i][j] = getCount (i + 1, j, n, m, dp) + getCount (i, j + 1, n, m, dp);
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
