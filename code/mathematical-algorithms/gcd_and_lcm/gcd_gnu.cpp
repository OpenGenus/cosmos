#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	cout << "GCD: " << __gcd(a, b) << endl;
    cout << "LCM: " << a / __gcd(a, b) * b << endl;
    return 0;
}