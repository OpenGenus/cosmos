// C++ program for finding the unique number in a list
#include <bits/stdc++.h> 
using namespace std; 

bool compare(double a, double b) 
{ 
	return ((int)a == (int)b); 
} 

int main() 
{ 
	list<double> list = { 2.55, 3.15, 4.16, 4.16, 
						4.77, 12.65, 12.65, 13.59 }; 

	cout << "List is: "; 

	// unique operation on list with no parameters 
	list.unique(); 

	// starts from the first element 
	// of the list to the last 
	for (auto it = list.begin(); it != list.end(); ++it) 
		cout << *it << " "; 

	// unique operation on list with parameter 
	list.unique(compare); 

	cout << "\nList is: "; 

	// starts from the first element 
	// of the list to the last 
	for (auto it = list.begin(); it != list.end(); ++it) 
		cout << *it << " "; 

	return 0; 
} 
