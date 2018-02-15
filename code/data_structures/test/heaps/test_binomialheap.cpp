//============================================================================
// Name        : bheap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <limits>
#include <stdlib.h>
#include <time.h>
#include "../../src/heaps/binomial_heap/binomial_heap.hpp"


int main() {
	binomialHeap<long long> heap;
	clock_t now;
	srand(time(0));
	int x;
	long long n = 3500000;
	std::cout << "\nInserting...";
	std::flush(std::cout);
	now = clock();
	for(int i=0; i < n; i++)
	{
		x= rand()%999999+1; //1-100 values
		heap.insert(x);
	}
	std::cout << "\nInserted " << n << " items in " << std::setprecision(5)  << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";
	std::fstream outFile;
	outFile.open("heap.txt",std::fstream::out);
	outFile.clear();
	outFile <<"Count: " << heap.size()
			<< "\nMinimum:" << heap.getMin();
	heap.print(outFile);
	outFile.close();
	int num  = 0, num2 = 0;
	int control = 0;
	while(control != -1)
	{
		std::cout << "\nKeys are from [ 1 - 999999]"
					"\nDelete   Key: 1 <key>"
				     "\nDecrease Key: 2 <key> <newKey>\n:"
				     "\nExit        :-1 <key> <newKey>\n";
		if(!(std::cin >> control))
		{
			std::cin.clear();
		}

		if(control == 2) // decrease
		{
			if(!(std::cin >> num >> num2))
			{
				std::cin.clear();
			}

			now = clock();
			if(heap.decreaseKey(num, num2))
				std::cout << "\n\nDecreased " << num << " -> " << num2 << " in " << std::setprecision(5) << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";
			else
				std::cout << "\nCould not decrease!";
		}
		else if (control == 1)
		{
			if(!(std::cin >> num))
			{
				std::cin.clear();
			}
			now = clock();
			if(heap.deleteKey(num))
				std::cout << "\n\nDeleted " << num  << " in "<< std::setprecision(5)  << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";
			else
				std::cout << "\nCould not delete!";
		}
		if (control != -1)
			std::cin.get();
	}
	std::cout << "\nCalling Remove Min on all keys...\n";
	std::flush(std::cout);
	int j = 0;
	now = clock();
	while(!heap.isEmpty())
	{
		j++;
		heap.extractMin();

	}
	std::cout << "Removed " << j << " items in " << std::setprecision(5) << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...";
	std::cout << "\nEnter to exit!\n";
	std::cin.get();
	return 0;
}
