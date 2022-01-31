#include <iostream>
using namespace std;

void output_min_max(int* positions, int numPeople);

int main()
{
	int testCases, numPeople, input;
	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		cin >> numPeople;
		int* positions = new int[numPeople];
		for (int j = 0; j < numPeople; j++)
		{
			cin >> input;
			positions[j] = input;
		}
		output_min_max(positions, numPeople);
	}
}

void output_min_max(int* positions, int numPeople)
{
	int current_chain = 1;
	int min_chain = numPeople;
	int max_chain = 0;
	for (int i = 1; i < numPeople; i++)
	{
		if (positions[i] - positions[i - 1] <= 2)
			current_chain++;
		else
		{
			if (current_chain < min_chain)
				min_chain = current_chain;
			if (current_chain > max_chain)
				max_chain = current_chain;
			current_chain = 1;
		}
	}
	if (current_chain < min_chain)
		min_chain = current_chain;
	if (current_chain > max_chain)
		max_chain = current_chain;
	cout << min_chain << ' ' << max_chain << endl;
}

