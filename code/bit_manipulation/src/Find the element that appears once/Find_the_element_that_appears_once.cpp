// C++ program to find the element
// that occur only once
#include <bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

int getSingle(int arr[], int n)
{
	// Initialize result
	int result = 0;

	int x, sum;

	// Iterate through every bit
	for (int i = 0; i < INT_SIZE; i++) {

		// Find sum of set bits at ith position in all
		// array elements
		sum = 0;
		x = (1 << i);
		for (int j = 0; j < n; j++) {
			if (arr[j] & x)
				sum++;
		}

		// The bits with sum not multiple of 3, are the
		// bits of element with single occurrence.
		if ((sum % 3) != 0)
			result |= x;
	}

	return result;
}

// Driver code
int main()
{
	int arr[] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The element with single occurrence is " << getSingle(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra
