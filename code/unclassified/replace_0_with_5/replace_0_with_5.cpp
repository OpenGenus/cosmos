#include <iostream>

using namespace std;

int main() {
	int n, t = 0, d;
	cin >> n;

	while(n > 0) {
		d = n%10;
		if(d == 0)
			t = t*10 + 5;
		else
			t = t*10 + d;
		n = n / 10;
	}
	
	n = 0;
	
	while(t > 0) {
		d = t%10;
		n = n*10 + d;
		t = t/10;
	}

	cout << n << endl;
	return 0;
}