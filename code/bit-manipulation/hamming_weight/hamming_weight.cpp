#include <iostream>
#include <cstddef>

int HammingWeight(std::uint32_t n);

int main() {
    uint32_t num;

    std::cout << "Enter number: ";
    std::cin >> num;

    std::cout << HammingWeight(num);

    return 0;
}

int HammingWeight(std::uint32_t n) {
    int bitCount = 0;

    while (n > 0) {
        bitCount += n & 1;

        n >>= 1;
    }
    return bitCount;
}
