/* Part of Cosmos by OpenGenus Foundation */
/*Added by arpank10 */
#include <stdio.h>
#include <stdbool.h>
/*
Shaker sorting implementation in C
*/
void shaker_sort(int a[],int n)
{
	int i=0,j;
	bool swapped=false;
	for(i=0;i<n/2;i++)
	{
		for(j=i;j<n-1-i;j++)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=true;
			}
		}
		for(j=n-i-2;j>i;j--)	
		{
			if(a[j-1]>a[j])
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				swapped=true;
			}
		}
		if(!swapped)	//If no elements are swapped in the iteration array is sorted
			break;
	}
}
int main()
{
	int n;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	int a[n];
	int i;
	for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	shaker_sort(a,n);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
