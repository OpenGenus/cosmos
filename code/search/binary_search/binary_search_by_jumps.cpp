#include <iostream>
using namespace std;

int main()
{
	int array[] = {0,2,8,46,48,88,102,105};
	int k = 0, n, x;
	n = sizeof(array)/sizeof(array[0]);
	cin>>x;

	/* The search goes through the array from left to right, and the initial jump
	length is n /2. At each step, the jump length will be halved: first n /4, then n /8,
	n /16, etc., until finally the length is 1. */

	for (int b = n/2; b >= 1; b /= 2) {
		while (k+b < n && array[k+b] <= x) k += b;
	}
	if (array[k] == x) {
		cout<<"Element found at index = "<<k<<endl;
	}
	else
	{
		cout<<"Element not found"<<endl;
	}
	return 0;
}
