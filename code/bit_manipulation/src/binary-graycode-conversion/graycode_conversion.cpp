#include <iostream>

using namespace std;

// Binary to Gray
int binaryToGray(int n) {
    return n ^ (n >> 1);
}

// Gray to Binary
int grayToBinary(int n) {
    int binary = n;
    while (n > 0) {
        n >>= 1;
        binary ^= n;
    }
    return binary;
}

int main() {
    int num = 7;
    cout << "Gray Code: " << binaryToGray(num) << endl; // Output: 4
    cout << "Binary Code: " << grayToBinary(binaryToGray(num)) << endl; // Output: 7
    return 0;
}
