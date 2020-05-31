// Implementation of begin() function 
#include <array> 
#include <iostream> 
using namespace std; 

int main() 
{ 
	// declaration of array container 
	array<int, 5> myarray{ 1, 2, 3, 4, 5 }; 

	// using begin() to print array 
	for (auto it = myarray.begin(); it! =myarray. end(); ++it) 
		cout << ' ' << *it; 

	return 0; 
}

// Implementation of end() function 
#include <array> 
#include <iostream> 
using namespace std; 

int main() 
{ 
	// declaration of array container 
	array<int, 5> myarray{ 10, 20, 30, 40, 50 }; 

	// using end() to print array 
	for (auto it = myarray.begin(); 
		it != myarray.end(); ++it) 
		cout << ' ' << *it; 
	return 0; 
} 
