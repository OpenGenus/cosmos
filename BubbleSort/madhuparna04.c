#include<stdio.h>
void main()
{
int a[100],n,i=0,j=0;
int temp;

	printf("\n Enter the size of the array ");
	scanf("%d", &n);

	printf("\n Enter the elements of the Array ");

	for(;i<n;++i)
		scanf("%d", &a[i]);

	for(i=0;i<n;++i)
		for(j=0;j<n-i-1;++j)
			if(a[j]>a[j+1])	
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}

	printf("\n The sorted array is : ");
	for(i=0;i<n;++i)
		printf(" %d ", a[i]);
}
