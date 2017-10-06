#include <iostream>

using namespace std;

int main() {
	int n, , tmp = 0;
	cin >> n;

	while(n > 0) {
		d = n%10;
		if(d == 0)
			tmp = tmp * 10 + 5;
		else
			tmp = tmp * 10 + d;
		n = n/10;
	}	
	
	n = 0;
	
	while(tmp > 0) {
		d = tmp%10;
		n = n * 10 + d;
		tmp = tmp/10;
	}

	cout << n;
	return 0;
}