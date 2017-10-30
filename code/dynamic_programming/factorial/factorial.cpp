// factorial.cpp

#include <iostream>

using namespace std;

long long factorial(long long current) {
	if (current == 0) {
		return 1;
	}
	else {
		return (current * factorial(current - 1));
	}
}

int main() {
	long long n, result;
	cin >> n;
	result = factorial(n);
	cout << "The factorial of " << n << " is " << result;
	return 0;
}
