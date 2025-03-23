#include<stdio.h>
void main()
{
	int n,temp=0,i,j,arr[10];
	printf("ENTER THE NO OF ARRAY ELEMENT:");
	scanf("%d",&n);
	
	printf("\n Enter the elements in array:");
        for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
        	

	printf("Sorted array is:\n");

	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
	
	
}
                                    
