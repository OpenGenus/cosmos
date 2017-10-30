/* Part of Cosmos by OpenGenus Foundation */

import java.util.*;
import java.lang.*;
import java.io.*;

/* A DP based program to find length
of the shortest supersequence */
public class SCS {
      
    // Returns length of the shortest supersequence of X and Y
    static int superSequence(String X, String Y, int m, int n)
    {
        int dp[][] = new int[m+1][n+1];
      
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
               if (i == 0)
                   dp[i][j] = j;
               else if (j == 0)
                   dp[i][j] = i;
               else if (X.charAt(i-1) == Y.charAt(j-1))
                    dp[i][j] = 1 + dp[i-1][j-1];
                //Since we need to minimize the length
               else
                    dp[i][j] = 1 + Math.min(dp[i-1][j], dp[i][j-1]);
            }
        }
      
        return dp[m][n];
    }
 
    //Main function
    public static void main(String args[])
    {
      String X = "ABCBDAB";
      String Y = "BDCABA";
      System.out.println("Length of the shortest supersequence is "+ superSequence(X, Y, X.length(),Y.length()));
    }
}
