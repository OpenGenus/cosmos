#include <stdio.h>

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
    int num = 7; // Binary: 111
    int gray = binaryToGray(num);
    int binary = grayToBinary(gray);

    printf("Gray Code: %d\n", gray);   // Output: 4
    printf("Binary Code: %d\n", binary); // Output: 7

    return 0;
}
