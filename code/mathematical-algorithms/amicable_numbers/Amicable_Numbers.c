/* Part of Cosmos by OpenGenus Foundation */

#include<stdio.h>
long int sum(long int a)
{
	long int s=0,i;
	for(i=1;i<=a/2;i++)
	{
		if(a%i==0)
			s+=i;
	}
	return s;
}
int main()
{
	long int t,n,s1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		s1=sum(n);
		if(n==sum(s1))
			printf("Yes, amicable with %ld\n",s1);
		else
			printf("No\n");
	}
	return 0;
} 
