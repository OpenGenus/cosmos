#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n){
	int i, j, maxValue = 0; //Declaration of Pointers
	int dp[n]; //Declaration of DP Array

	for (i = 0; i < n; i++){
		dp[i] = arr[i];
	} //Initialization of DP Array

	for (i = 1; i < n; i++ ){
		for (j = 0; j < i; j++ ){ //2 Nested For Loops for Bottom-Up approach
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]){ // If subsequence is increasing and dp[i] is lesser than current sum
				dp[i] = dp[j] + arr[i]; // dp[i] stores the maximum sum
			}
		}
	}

	for (i = 0; i < n; i++){
		maxValue = max(dp[i], maxValue); //Picking the maximum value in the DP Array
	}
	return max;
}

// Driver Code
int main(){
	int arr[] = {4, 6, 1, 3, 8, 4, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sum of maximum sum increasing subsequence is " << maxSum(arr, n) << ".\n";
	return (0);
}

//Space Complexity: O(N)
//Time Complexity: O(N^2)
