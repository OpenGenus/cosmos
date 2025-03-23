import java.util.*;

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


public class countWays
{
  #create the dp table for storing the data
  public static int dp[][] = new int[1000][1000];

  public static int getWays (int i, int j, int n, int m)
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
    return dp[i][j] = getWays (i + 1, j, n, m) + getWays (i, j + 1, n, m);
  }

  public static void main (String[]args)
  {
    Scanner sc = new Scanner (System.in);

    System.out.println ("Enter maze");
    System.out.println ("Enter row");
    int n = sc.nextInt ();
    System.out.println ("Enter column");
    int m = sc.nextInt ();
    for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
		    dp[i][j] = -1;
		}
    }
    int path = getWays (0, 0, n, m);

    System.out.println ("Number of way to reach destination to the path: " +path);
  }
}
