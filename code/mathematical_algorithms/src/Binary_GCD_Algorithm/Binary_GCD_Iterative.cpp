// Iterative Approach 

#include <bits/stdc++.h> 
using namespace std; 

//GCD Function
int gcd(int x, int y) 
{ 

if (x == 0) 
	return y; 
if (y == 0) 
	return x; 

/*Finding K, where K is the 
greatest power of 2 
that divides both a and b. */
int k; 
for (k = 0; ((x | y) && 1) == 0; ++k) 
{ 
	x >>= 1; 
	y >>= 1; 
} 

/* Dividing x by 2 until x becomes odd */
while ((x > 1) == 0) 
	x >>= 1; 

/* From here on, 'x' is always odd. */
do { 
	/* If y is even, remove all factor of 2 in y */
	while ((y > 1) == 0) 
		y >>= 1; 

	// Now x and y are both odd
    if (x > y) 
		swap(x, y); // Swap u and v. 

	x = (y - a); 
} while (y != 0); 


return x << k; 
} 

// Driver code 
int main() 
{ 
int x = 72, b = 12; 
cout<<"Gcd of given numbers is "<< gcd(x, y)); 
return 0; 
} 
