#include<iostream>
#include<algorithm>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.

long long int interpolation_search(int arr[],int n,int x)
{
	int low=0,high=n-1;

	//Beacuse the array is sorted, element has to be present in range
	//made by corner i.e low and high

	while ((low<=high) and (x>=arr[low]) and (x<=arr[high]))
	{
		// Now we will enquire the position keeping in mind the uniform distribution in mind
		int pos=low+(((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));

        // If x is larger, x is in upper part
        if (arr[pos]<x)
            low=pos+1;

        // If x is smaller, x is in lower part
        else if(arr[pos]>x)
            high=pos-1;

        // Target found
        else
            return pos;
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Please enter the number of elements in array\n";
	cin>>n;
	int arr[n];

	cout<<"Please enter "<<n<<" numbers for arrays\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	// For Interpolation search we need to sort the array
	sort(arr,arr+n);

	cout<<"Enter the number you want to search\n";
	int x;// Target number
	cin>>x;

	 int index=interpolation_search(arr, n, x);

    // If element was found
    if (index != -1)
        cout<<"Element found at index "<<index<<" in sorted array\n";
    else
        cout<<"Element not found.\n";
    return 0;
}
