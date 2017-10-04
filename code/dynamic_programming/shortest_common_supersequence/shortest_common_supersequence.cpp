#include <bits/stdc++.h>
using namespace std;

// Function to find length of shortest Common supersequence of
// sequences X[0..m-1] and Y[0..n-1]
int SCSLength(string X, string Y, int m, int n)
{
	// if we have reached the end of either sequence, return
	// length of other sequence
	if (m == 0 || n == 0)
		return n + m;

	// if last character of X and Y matches
	if (X[m - 1] == Y[n - 1])
		return SCSLength(X, Y, m - 1, n - 1) + 1;
	else
	// else if last character of X and Y don't match
		return min(SCSLength(X, Y, m, n - 1) + 1,
					SCSLength(X, Y, m - 1, n) + 1);
}

// main function
int main()
{
	string X = "ABCBDAB", Y = "BDCABA";
	int m = X.length(), n = Y.length();

	cout << "The length of shortest Common supersequence is "
			<< SCSLength(X, Y, m, n);

	return 0;
}
