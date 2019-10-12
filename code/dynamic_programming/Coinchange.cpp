/* 
Given a set of coins and amount, 
Write an algorithm to find out how many ways we can make the change of the amount using the coins given.
*/

#include<iostream>
using namespace std;
void coin_change(int coins[], int m, int n);

int main()
 {
	//code
	int t, m, n,i,j;
	cin >> t;
	while(t--)
	{
	    cin >> m;
	    int coins[m];
	    for(i=0; i<m; i++)
	        cin >> coins[i];
	        
	    cin >> n;
	    coin_change(coins,m,n);
	}
	return 0;
}

void coin_change(int coins[], int m, int n)
{
    int i,j;
    int dp[m+1][n+1];
    
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            if (j==0 || i==0)
                dp[i][j] = 0;
                
            else if (j-coins[i-1] < 0) // cannot select coin at i,so combination formed remains with previous given coins 
                dp[i][j] = dp[i-1][j];
                
            else if (j==coins[i-1]) // if no.= given coin, then total combn = 1(this coin) + combn with prev given coins
                dp[i][j] = 1 + dp[i-1][j];
            
            else if (j-coins[i-1] > 0) //if no. > given coin,total combn= combn with prev given coins + combn with given coin at (no. - current coin)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                
        }
    }
    
    cout << dp[m][n] << "\n";
}
