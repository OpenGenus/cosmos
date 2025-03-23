/* Part of Cosmos by OpenGenus Foundation */

import java.lang.Math;

class LIS
{
	// returns size of the longest increasing subsequence within the given array
	// O(n^2) approach
	static int lis(int arr[], int n)
	{
		int dp[] = new int[n];
		int ans = 0;
		
		for(int i=0; i<n; i++)
		{
			dp[i] = 1;
			for(int j=0; j<i; j++)
			{
				if(arr[j] < arr[i])
				{
					dp[i] = Math.max(dp[i], 1+dp[j]);
				}
			}
			ans = Math.max(ans, dp[i]);
		}
		return ans;
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
        int n = arr.length;
        System.out.println("Length of lis is " + lis( arr, n ) + "\n" );
	}
}