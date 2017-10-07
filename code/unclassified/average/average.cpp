/// Part of Cosmos by OpenGenus Foundation
/// Find of average of numbers in an array
/// Contributed by: Pranav Gupta (foobar98)

#include <iostream>
using namespace std;

int main()
{
	// Size of array
	int n;
	cout << "Enter size of array: ";
	cin >> n;

	// Declaring an array of size n
	int *a = new int[n];

	cout << "Enter array elements: ";
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	double avg = double(sum)/n;
	cout << "Average of numbers: " << avg << endl;
	
	// Deallocate array
	delete [] a;
}
