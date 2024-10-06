#include <iostream>
using namespace std;

// Function to convert a number to Gray code
int binaryToGray(int n) {
    return n ^ (n >> 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int grayCode = binaryToGray(n);
    cout << "Gray code of " << n << " is: " << grayCode << endl;

    return 0;
}
