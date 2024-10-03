
#include <iostream>
#include <climits>
using namespace std;

// Values (stored in array v)
// Weights (stored in array w)
// Number of distinct items (n)
// Knapsack capacity W
int knapSack(int v[], int w[], int n, int W)
{
	if (W < 0)
		return INT_MIN;

	if (n < 0 || W == 0)
		return 0;

	int include = v[n] + knapSack(v, w, n - 1, W - w[n]);

	
	int exclude = knapSack(v, w, n - 1, W);

	// return maximum value we get by including or excluding current item
	return max (include, exclude);
}


int main()
{
	// Input: set of items each with a weight and a value
	int v[] = { 20, 5, 10, 40, 15, 25 };
	int w[] = {  1, 2,  3,  8,  7, 4 };

	// Knapsack capacity
	int W = 10;

	// number of items
	int n = sizeof(v) / sizeof(v[0]);

	cout << "Knapsack value is " << knapSack(v, w, n - 1, W);

	return 0;
}