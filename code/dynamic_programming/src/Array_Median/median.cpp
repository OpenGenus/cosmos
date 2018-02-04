#include<iostream>
#include<algorithm>
using namespace std;

float median(int n, int arr[n])
{
	if (n % 2 != 0)
		return (float)arr[n / 2];

	return ((float)(arr[(n - 1) / 2] + arr[n / 2]) / 2);
}

int main()
{
	int n;
	cout<<"Enter size of the Array";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" integers";
	for (int i = 0; i < n; i++)
		cin>>arr[i];
	sort(arr,arr+n);
	cout<<"Median= "<<median(n,arr);
	return 0;
}