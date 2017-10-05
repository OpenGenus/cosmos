#include <iostream>
using namespace std;

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
	cout<<count(n);
	
	return 0;
}
