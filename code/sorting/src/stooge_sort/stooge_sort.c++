#include<iostream>

using namespace std;
//Function for Stooge sorting
void StoogeSort(int a[],int i, int j)
{
int t;
 if(j-i+1 > 2)
	{
		t = (j-i+1)/3;
		StoogeSort(a, i, j-t);
		StoogeSort(a, i+t, j);
		StoogeSort(a, i, j-t);
	}

// swapping the element at start and end.
 if(a[i] > a[j])
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

int main()
{
	int n, k;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int arr[n];
	for(k = 0; k < n; k++)
	{
		cout<<"Enter element "<<k+1<<": ";
		cin>>arr[k];
	}

	StoogeSort(arr, 0, n-1);

// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (k = 0; k < n; k++)
		cout<<"->"<<arr[k];

	return 0;
}
