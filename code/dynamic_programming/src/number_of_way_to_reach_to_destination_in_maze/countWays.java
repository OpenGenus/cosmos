import java.util.*;

public class countWays
{
  public static int dp[][] = new int[1000][1000];

  public static int getWays (int i, int j, int n, int m)
  {
    if (dp[i][j] != -1)
      {
	return dp[i][j];
      }
    if (i == n - 1 || j == m - 1)
      {
	return 1;
      }
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
    for (int i = 0; i <= n; i++)
      {
	for (int j = 0; j <= m; j++)
	  {
	    dp[i][j] = -1;
	  }
      }
    int path = getWays (0, 0, n, m);

    System.out.println ("Number of way to reach destination to the path: " +
			path);
  }
}
