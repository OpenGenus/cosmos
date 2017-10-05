/* Part of Cosmos by OpenGenus Foundation */
#include <bits/stdc++.h>
using namespace std;
void heapify(int a[],int root,int n)
{
	int largest=root;  //initialize root as largest
	int left=2*root+1; //left-child
	int right=2*root+2;//right-child
	
	if(left<n && a[left]>a[largest]) //if left-child is larger
	   largest=left;
	if(right<n && a[right]>a[largest]) //if right-child is larger than the largest
	   largest=right;  
	if(largest != root) //if root is not the largest element
	{
		int temp=a[root];
		a[root]=a[largest];
		a[largest]=temp;
		heapify(a,largest,n);
	}
}
void buildMaxHeap(int a[],int n)
{   
	for(int i=floor(n/2)-1;i>=0;i--) //building heap
	{
	   heapify(a,i,n);	
	}
}
int main() {
	
	int a[] = {1,8,9,7,6,10};
	int n=sizeof(a)/sizeof(a[0]);
	buildMaxHeap(a,n);
	cout<<"The Max-Heap is:\n";
	for(int i=0;i<n;i++) //max-heap is stored in 1-D array
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
