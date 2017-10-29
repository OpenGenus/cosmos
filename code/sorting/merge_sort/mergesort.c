#include<stdio.h>

void merge(long long a1[], long long n, long long a2[], long long m, long long a[])
{
	long long i=0,j=0,k=0;
	while(i<n&&j<m)
	{
		if(a1[i]<=a2[j])a[k++]=a1[i++];
		else a[k++]=a2[j++];
	}
	while(i<n)a[k++]=a1[i++];
	while(j<m)a[k++]=a2[j++];
}

void mergesort(long long a[], long long n)
{
	if(n<=1)return;
	long long m=n/2;
	long long a1[m],a2[n-m],i;
	for(i=0;i<m;i++)a1[i]=a[i];
	for(i=m;i<n;i++)a2[i-m]=a[i];
	mergesort(a1, m);
	mergesort(a2, n-m);
	merge(a1, m, a2, n-m, a);
}

int main()
{
	long long n,i;
	printf("Enter the no of elements:");
	scanf("%lld",&n);
	printf("Enter the elements of the array:\n");
	long long arr[n];
	for(i=0;i<n;i++)scanf("%lld",&arr[i]);
	mergesort(arr, n);
	printf("Sorted array:\n");
	for(i=0;i<n;i++)printf("%lld ",arr[i]);
	printf("\n");
	return 0;
}
