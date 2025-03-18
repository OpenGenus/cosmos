// Part of Cosmos by OpenGenus Foundation

/**
 * Implements factorial using dp
 */

#include <iostream>

using namespace std;

int main() 
{
	unsigned long long numberToFactorial; 
	cin >> numberToFactorial;
	if (numberToFactorial == 0 || numberToFactorial == 1)
		cout << 1 << endl;
	else
	{
		unsigned long long outcome = 1;
		for (unsigned long long i = 1; i <= numberToFactorial; i++)
			outcome = outcome * i;
		cout << outcome << endl;
	}
	return 0;
}
