//Insertion sort for 20 elements
#include<stdio.h>

int main()
{

int arr[20],i;
//enter elements
for(i=0;i<20;i++)
//arr[i]=20-i*i;
scanf("%d",&arr[i]);
int j;
for(i=1;i<20;i++)
{
	int temp=arr[i];
	for(j=i-1;j>=0;j--)
	{
	
		if (arr[j]>=temp)
			{
				arr[j+1]=arr[j];
				if(j==0)
				arr[j]=temp;
			}
		else
			{
				arr[j+1]=temp;
				break;
			}
	}
}

for(i=0;i<20;i++)
printf("%d ",arr[i]);

}
