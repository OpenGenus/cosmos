/*for loop*/
/*C program to print sum of n natural numbers using for loop*/

#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter a number:");
	scanf("%d",&n);
	printf("First %d natural numbers are:\n",n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",i);
	}
	return 0;
}

/*Output */
/*
Input:
5
Output:
1 2 3 4 5 
*/
