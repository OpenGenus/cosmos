#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
int count(int n){
	int c = 0;
	while (n) {
		c += (n & 1);
		n >>= 1;
	}
	return c;
}

int main() {
	
	int n;
	cin >> n;
	// manual
	cout<<count(n);
	// builtin
	// this is c++ builtin function very less people know about this.
    	std :: cout << __builtin_popcount(5); //will return 2
	// avalable in c, c++
	
	return 0;
}
