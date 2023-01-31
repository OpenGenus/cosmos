// C++ program to demonstrate that array elements
// are stored contiguous locations

#include <iostream>
using namespace std;

int main()
{
	// an array of 10 integers.
	// If arr[0] is stored at
	// address x, then arr[1] is
	// stored at x + sizeof(int)
	// arr[2] is stored at x +
	// sizeof(int) + sizeof(int)
	// and so on.
	int arr[5], i;

	cout << "Size of integer in this compiler is "
		<< sizeof(int) << "\n";

	for (i = 0; i < 5; i++)
		// The use of '&' before a variable name, yields
		// address of variable.
		cout << "Address arr[" << i << "] is " << &arr[i]
			<< "\n";

	return 0;
}
