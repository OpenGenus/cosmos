// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
	// store keys of cache
	list<int> dq;

	// store references of key in cache
	unordered_map<int, list<int>::iterator> ma;
	int csize; // maximum capacity of cache

public:
	LRUCache(int);
	void refer(int);
	void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
	csize = n;
}

// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
	// not present in cache
	if (ma.find(x) == ma.end()) {
		// cache is full
		if (dq.size() == csize) {
			// delete least recently used element
			int last = dq.back();

			// Pops the last element
			dq.pop_back();

			// Erase the last
			ma.erase(last);
		}
	}

	// present in cache
	else
		dq.erase(ma[x]);

	// update reference
	dq.push_front(x);
	ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display()
{

	// Iterate in the deque and print
	// all the elements in it
	for (auto it = dq.begin(); it != dq.end();
		it++)
		cout << (*it) << " ";

	cout << endl;
}

// Driver Code
int main()
{
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();

	return 0;
}
// This code is contributed by Satish Srinivas
