// Recursive program 

#include <bits/stdc++.h> 
using namespace std; 

// Function to implement the  
// Stein's Algorithm 
int gcd(int x, int y) 
{ 
  if (x == y) 
	 return x; 
  if (x == 0) 
	 return y; 
  if (y == 0) 
	 return x; 

// look for factors of 2 
if (~x & 1) // x is even 
{ 
	if (y & 1) // y is odd 
		return gcd(x >> 1, y); 
	else      // both x and y are even 
		return gcd(x >> 1, y >> 1) << 1; 
} 

if (~y & 1) // x is odd, y is even 
	return gcd(x, y >> 1); 

// reduce larger number 
if (x > y) 
	return gcd((x - y) >> 1, y); 

return gcd((y - x) >> 1, x); 
} 

// Driver code 
int main() 
{ 
int a = 34, b = 17; 
cout<<"Gcd of given numbers is"<<gcd(a, b)); 
return 0; 
}
