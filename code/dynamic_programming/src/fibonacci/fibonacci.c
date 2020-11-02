//Program to find nth fibonacci number
//Time complexity = O(n)
//Space complexity = O(1)
//Part of Cosmos by OpenGenus
#include<stdio.h>
int
fib(int n)
{
	int a=0, b=1, c=1;
    
	for(int i=2; i<=n; i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
    
	return c;
}

int
main(){
	int n;
    
	printf("Enter n:");
    
	scanf("%d", &n);
    
	int answer=fib(n);
	printf("\nThe nth term of the fibonacci sequence is: %d", answer);
}