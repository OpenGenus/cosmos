#include <stdio.h>

long long int factorial(long long int n);

int main()
{
	long long int n,sum=0;
	printf("Enter a Natural number\n");
	scanf("%lli",&n);
	int sign=1;
	for(int i=2;i<=n;i++){
		sum=sum+(sign*factorial(n)/factorial(i));
		sign=-sign;
	}
	printf("Number of derangements possible for %lli are %lli\n",n,sum);

	return(0);
}

long long int factorial(long long int n)
{
	if(n==0 || n==1){
		return 1;
	}
	else{
		return(n*factorial(n-1));
	}
}
