//Brian Kernighan’s Algorithm. This programme uses O(logn) to count set bits.

#include <iostream> 
using namespace std; 
 
int countSetBits(int n) 
{ 
	// base case 
	if (n == 0)
	{ 
		return 0; 
 	}
	else
	{
		// if last bit is set, add 1 else add 0 
		return (n & 1) + countSetBits(n >> 1);
	} 
} 

int main() 
{ 
	int n;
	cout << "Enter a positive integer : ";
	cin >> n;
	cout << countSetBits(n); 

	return 0; 
} 