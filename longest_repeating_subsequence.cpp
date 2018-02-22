/* Part of Cosmos by OpenGenus Foundation */

//dynamic programming || Longest repeating subsequence

#include <iostream>
#include<cstring>
using namespace std;

int longest_repeating_subsequence(string s)
{
    int n=s.size();  // Obtaining the length of the string
    int dp[n+1][n+1];

    //Initializing the table

    for (int x=0;x<=n;x++)
    {
        for (int y=0;y<=n;y++)
        {
            dp[x][y]=0;
        }
    }

    // Implementation is very similar to Longest Common Subsequence problem

    for (int x=1;x<=n;x++)
    {
        for (int y=1;y<=n;y++)
        {

            // If values at indexes match and indexes are not equal

            if (s[x-1]==s[y-1] && x!=y)

            {
                dp[x][y]=1+dp[x-1][y-1];
            }

            // If values at indexes do not match

            else
            {
                dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
            }
        }
    }

    // Returning the value of the result

    return dp[n][n];
}


int main() {
    string str;
    cin>>str;
    cout<<longest_repeating_subsequence(str);
}
