#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high)
{
	int pivot=a[high]; 		
	int i=low,j;  			
	for(j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			swap(a[i],a[j]); 		
			i++;
		}
	}
	swap(a[i],a[high]);
	return i;
}



void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(a,low,high);   		
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
}

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
