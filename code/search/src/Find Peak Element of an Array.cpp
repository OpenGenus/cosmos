#include<iostream>
 
using namespace std;
 
// A function implementing Binary search approach to find a peak.
int PeakSearch(int a[], int start, int end)
{
	int i, mid;
	// Assigning middle of the array.
	mid = (end+start+1)/2;
	// If mid is at boundary index of the array sub-part, and higher than its only neighbor the mid is the peak of array. 
	if((a[mid] > a[mid+1] && mid == start)||(a[mid] > a[mid-1] && mid == end))
	{
		return a[mid];
	}
	// If mid is higher than its neighbors then it is the peak element.
	else if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
	{
		return a[mid];
	}
	// If right neighbor is higher then right subpart must have a peak.
	else if(a[mid] <= a[mid+1])
	{
		return PeakSearch(a, mid+1, end);
	}
	// If left neighbor is higher then left subpart must have a peak.
	else if(a[mid] <= a[mid-1])
	{
		return PeakSearch(a, start,mid-1);
	}
}
 
int main()
{
	int n, i, peak;
	cout<<"\nEnter the number of data element: ";
	cin>>n;
 
	int arr[n];
	// Take data input.
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	// Get the peak of the array.	
	peak = PeakSearch(arr, 0, n-1);
 
	// Print the result.
	cout<<"\nThe peak element of the given array is: "<<peak;
 
    return 0;
}
