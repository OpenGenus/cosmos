#include <stdio.h>
typedef unsigned long long int ll;

ll fact(int n)
{
	if(n==0 || n==1)
		return 1;

	return n*fact(n-1);
}
int main()
{
	ll n;
	scanf("%llu",&n);
	printf("Factorial of %llu is : %llu\n",n,fact(n));
	return 0;
}