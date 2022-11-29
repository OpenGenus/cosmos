#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
	if (n==1) // Base case 
		return 1;
	else 
		return n*fact(n-1); 
}

int main()
{
	int  n,ans;
	printf("Enter the number \n");
	cin >> n; // Number whose factorial we have to find
	ans=fact(n); // Function call 
	cout<<"The Factorial of "<<ans<<endl;
	return 0;
}
