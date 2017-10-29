#include <iostream>
using namespace std;

int main()
{
	int array[] = {0,2,8,46,48,88,102,105};
	int k = 0, n, x;
	n = sizeof(array)/sizeof(array[0]);
	cin>>x;
	for (int b = n/2; b >= 1; b /= 2) {
		while (k+b < n && array[k+b] <= x) k += b;
	}
	if (array[k] == x) {
		cout<<"Element found at index = "<<k<<endl;
	}
	else
	{
		cout<<"Element not found"<<endl;
	}
	return 0;
}
