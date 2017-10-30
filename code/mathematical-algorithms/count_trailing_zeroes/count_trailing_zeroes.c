#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int num,x=5,count=0;
	scanf("%d",&num);
	while(x<=num)
	{
		count=count+(num/x);
		x=x*5;
	}
	printf("%d\n",count);
}
	
}
