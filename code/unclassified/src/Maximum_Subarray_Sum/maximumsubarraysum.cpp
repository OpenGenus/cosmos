//Part of Cosmos by OpenGenus Foundation


// C++ implementation of simple algorithm to find
// Maximum Subarray Sum in a given array
//this implementation is done using Kadane's Algorithm which has a time complexity of O(n)

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
	int max_sum_so_far = INT_MIN;
	int curr_max = 0;
	for (int i = 0; i < n; i++) {
		curr_max = curr_max + arr[i];
		if (max_sum_so_far < curr_max)
			max_sum_so_far = curr_max;
		if (curr_max < 0)
			curr_max = 0;
	}
	return max_sum_so_far;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int answer = maxSubarraySum(arr, n);
	cout << "Maximum subarray sum is " << answer;
	return 0;
} 
