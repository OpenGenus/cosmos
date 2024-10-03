// Reverse the bits of 32 bit unsigned integer
#include <cmath>
#include <cstdlib>
#include <iostream>

unsigned int reverseBits(unsigned int n) {
    int bit_pos = 31;
    int i = 0;
    unsigned int rev_num = 0;
    while (n) {
        int lsb = n % 2;
        rev_num = rev_num + lsb * pow(2, bit_pos);
        n /= 2;
        bit_pos--;
    }
    return rev_num;
}

int main() {
    unsigned int n;
    std::cout << "Enter the number : ";
    std::cin >> n;
    std::cout << "The reversed number is : " << reverseBits(n) << "\n";
    return 0;
}

/* Sample Input-Output
Enter the number : 3
The reversed number is : 3221225472

Explanation :
3 = 00000000000000000000000000000011 (binary)
reverseBits(3) = 11000000000000000000000000000000 (binary)
               = 3221225472 (decimal)
*/
