// SATYAMEVA JAYATE
//				To find an element in increasing seq. of values
#include <bits/stdc++.h>
using namespace std;

int arr[100];
int binary(int l,int r,int key)
{
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(arr[mid] == key) // key is the element to find
		{
			return mid;
		}
		else if( arr[mid] > key)
		{
			r = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}
		return -1; // Not Found 
}
int main()
{
	int n,m,i;
	cin >> n; // Size of the array
	for(i=0;i<n;i++)
	{
		cin >> arr[i]; 
	}
	sort(arr,arr+n); // Hence the array is sorted
	cout<<"Enter the element to be searched\n";
	cin >> m;
	int x = binary(0,n,m);
	cout << x<<"\n";
	return 0;
}
