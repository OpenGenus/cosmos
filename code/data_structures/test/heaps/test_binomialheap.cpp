/*
g++ -std=c++11 test_binomialheap.cpp -o test_binomialheap
*/

#include <limits>
#include <stdlib.h>
#include <time.h>
#include "../../src/heaps/binomial_heap/binomial_heap.hpp"


int main() {
	BinomialHeap<long long> heap;
	clock_t now;
	srand(time(0));
	int x;
	long long n = 500000;
	
	std::cout << "\nInserting...";
	std::flush(std::cout);
	now = clock();
	for(int i=0; i < n; i++)
	{
		x= rand()%999999+1; //1-100 values
		heap.insert(x);
	}
	std::cout << "\nInserted " << n << " items in " << std::setprecision(5)  << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";
	std::cout << "\nCopying Heaps\n";
	BinomialHeap<long long> heapCopy = heap, heapAssign;

	heapAssign = heapCopy;

	int num  = 0, num2 = 0;
	int control = 0;
	while(control != -1)
	{
		std::cout << "\nKeys are from [ 1 - 999999]\n"
					 "\nDelete Key    : 1 <key>"
				     "\nDecrease Key  : 2 <key> <newKey>"
				     "\nClear Keys    : 3"
				     "\nExit          :-1 <key> <newKey>\n>";
		if(!(std::cin >> control))
		{
			std::cin.clear();
		}
		if(control == 3)
		{
			int n = heap.size();
			now = clock();
			heap.clear();
			std::cout << "\n\nCleared " << n << " keys in " << std::setprecision(5) << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";
		}
		else if(control == 2) // decrease
		{
			if(!(std::cin >> num >> num2))
			{
				std::cin.clear();
			}

			now = clock();
			try
			{
				heap.decreaseKey(num, num2);
				std::cout 	<< "\n\nDecreased " << num << " -> " << num2 << " in " << std::setprecision(5) 
							<< (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";
			}
			catch(BinomialHeap<long long>::Exception &e)
			{
				std::cout << e.what();
			}
		}
		else if (control == 1)
		{
			if(!(std::cin >> num))
			{
				std::cin.clear();
			}
			now = clock();
			try
			{
				heap.deleteKey(num);
				std::cout 	<< "\n\nDeleted " << num << " in " << std::setprecision(5) 
							<< (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...\n";

			}
			catch(BinomialHeap<long long>::Exception &e)
			{
				std::cout << e.what();
			}
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
		++j;
		heap.extractMin();

	}
	std::cout << "Removed " << j << " items in " << std::setprecision(5) << (clock() - now)/(double)CLOCKS_PER_SEC << " seconds...";
	std::cout << "\nEnter to exit!\n";
	std::cin.get();
}
