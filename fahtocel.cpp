#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int minValue;
	int maxValue;
	cout << minValue;


	cin >> minValue;
	cin >> maxValue;

	int fah = minValue;
	while (fah <= maxValue) {
	//int cel = (5*(fah - 32))/9;
		int cel = (5.0/9)*(fah - 32);
		cout << fah << '\t' << cel << endl;
		fah = fah + 20;
	}
}
