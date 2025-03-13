// Function to check if the 
// Pythagorean triplet exists or not

#include <bits/stdc++.h> 
using namespace std; 
 
bool checkTriplet(int arr[], int n) 
{ 
	int maximum = 0; 

	// Find the maximum element 
	for (int i = 0; i < n; i++) { 
		maximum = max(maximum, arr[i]); 
	} 

	// Hashing array 
	int hash[maximum + 1] = { 0 }; 

	// Increase the count of array elements 
	// in hash table 
	for (int i = 0; i < n; i++) 
		hash[arr[i]]++; 

	// Iterate for all possible a 
	for (int i = 1; i < maximum + 1; i++) { 

		// If a is not there 
		if (hash[i] == 0) 
			continue; 

		// Iterate for all possible b 
		for (int j = 1; j < maximum + 1; j++) { 

			// If a and b are same and there is only one a 
			// or if there is no b in original array 
			if ((i == j && hash[i] == 1) || hash[j] == 0) 
				continue; 

			// Find c 
			int val = sqrt(i * i + j * j); 

			// If c^2 is not a perfect square 
			if ((val * val) != (i * i + j * j)) 
				continue; 

			// If c exceeds the maximum value 
			if (val > maximum) 
				continue; 

			// If there exists c in the original array, 
			// we have the triplet 
			if (hash[val]) { 
				return true; 
			} 
		} 
	} 
	return false; 
} 
// Driver Code 
int main() 
{ 
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	if (checkTriplet(arr, n)) 
		cout << "Yes"; 
	else
		cout << "No"; 
} 
