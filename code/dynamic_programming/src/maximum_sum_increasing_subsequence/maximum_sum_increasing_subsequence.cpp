#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxSum(int arr[], int n)
{
	int i, j, max = 0;
	vector<int> dp(n);

	for (i = 0; i < n; i++)
	{
		dp[i] = arr[i];
	}

	for (i = 1; i < n; i++ )
    {
		for (j = 0; j < i; j++ )
        {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
            {
				dp[i] = dp[j] + arr[i];
            }
        }
    }

	for (i = 0; i < n; i++)
    {
		if (max < dp[i])
        {
			max = dp[i];
        }
    }

	return max;
}

// Driver Code
int main()
{
	int arr[] = {4, 6, 1, 3, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of maximum sum increasing subsequence is " << maxSum(arr, n) << ".\n";

	return (0);
}
