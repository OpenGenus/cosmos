/* Memoized fibonacci Series */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long Fibonacci (int N) {
    static long long fib[100] = {}; // initialises the array with all elements as 0
    fib[1] = 0; fib[2] = 1;
	if (N == 1) return fib[1];
	else if (N == 2) return fib[2];
	else if (fib[N] != 0) return fib[N];
	else {
	    fib[N] = Fibonacci (N - 1) + Fibonacci (N - 2);
	    return fib[N];
	}
}

int main () {
	int n;
	cout << "Enter number of terms: ";
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cout << Fibonacci (i) << " ";
	return 0;
}