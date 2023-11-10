// Part of OpenGenus Cosmos
// A C++ program to find minimum possible 
// time by the car chassis to complete 
#include <bits/stdc++.h> 
using namespace std; 
#define NUM_LINE 2 
#define NUM_STATION 4 

// Utility function to find a minimum of two numbers 
int min(int a, int b) 
{ 
	return a < b ? a : b; 
} 

int carAssembly(int a[][NUM_STATION], 
				int t[][NUM_STATION], 
				int *e, int *x) 
{ 
	int T1[NUM_STATION], T2[NUM_STATION], i; 

	// time taken to leave first station in line 1 
	T1[0] = e[0] + a[0][0]; 
	
	// time taken to leave first station in line 2 
	T2[0] = e[1] + a[1][0]; 

	// Fill tables T1[] and T2[] using the 
	// above given recursive relations 
	for (i = 1; i < NUM_STATION; ++i) 
	{ 
		T1[i] = min(T1[i - 1] + a[0][i], 
					T2[i - 1] + t[1][i] + a[0][i]); 
		T2[i] = min(T2[i - 1] + a[1][i], 
					T1[i - 1] + t[0][i] + a[1][i]); 
	} 

	// Consider exit times and retutn minimum 
	return min(T1[NUM_STATION - 1] + x[0], 
			T2[NUM_STATION - 1] + x[1]); 
} 

// Driver Code 
int main() 
{ 
	int a[][NUM_STATION] = {{4, 5, 3, 2}, 
							{2, 10, 1, 4}}; 
	int t[][NUM_STATION] = {{0, 7, 4, 5}, 
							{0, 9, 2, 8}}; 
	int e[] = {10, 12}, x[] = {18, 7}; 

	cout << carAssembly(a, t, e, x); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
