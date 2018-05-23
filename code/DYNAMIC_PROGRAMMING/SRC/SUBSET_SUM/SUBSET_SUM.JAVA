/* Part of Cosmos by OpenGenus Foundation */

// A Java programm for subset sum problem using Dynamic Programming.
class subset_sum
{
	static boolean isSubsetSum(int set[], int n, int sum)
	{
	    
		boolean subset[][] = new boolean[sum+1][n+1];
	
		for (int i = 0; i <= n; i++)
		subset[0][i] = true;
	
		for (int i = 1; i <= sum; i++)
		subset[i][0] = false;
	
		for (int i = 1; i <= sum; i++)
		{
		for (int j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j-1];
			if (i >= set[j-1])
			subset[i][j] = subset[i][j]||subset[i - set[j-1]][j-1];
		}
		}
		return subset[sum][n];
	}
	
	public static void main (String args[])
	{
		int set[] = {3, 34, 4, 12, 5, 7};
		int sum = 19;
		int n = set.length;
		if (isSubsetSum(set, n, sum) == true)
			System.out.println("Subset found");
		else
			System.out.println("No subset found");
	}
}
