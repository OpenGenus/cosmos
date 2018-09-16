// Part of Cosmos by OpenGenus Foundation
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

// I'm not crazy, I generated this lookup table with a Ruby script ;)
const unsigned bits[] = {
    0, // 0
    1, // 1
    1, // 10
    2, // 11
    1, // 100
    2, // 101
    2, // 110
    3, // 111
    1, // 1000
    2, // 1001
    2, // 1010
    3, // 1011
    2, // 1100
    3, // 1101
    3, // 1110
    4, // 1111
    1, // 10000
    2, // 10001
    2, // 10010
    3, // 10011
    2, // 10100
    3, // 10101
    3, // 10110
    4, // 10111
    2, // 11000
    3, // 11001
    3, // 11010
    4, // 11011
    3, // 11100
    4, // 11101
    4, // 11110
    5, // 11111
    1, // 100000
    2, // 100001
    2, // 100010
    3, // 100011
    2, // 100100
    3, // 100101
    3, // 100110
    4, // 100111
    2, // 101000
    3, // 101001
    3, // 101010
    4, // 101011
    3, // 101100
    4, // 101101
    4, // 101110
    5, // 101111
    2, // 110000
    3, // 110001
    3, // 110010
    4, // 110011
    3, // 110100
    4, // 110101
    4, // 110110
    5, // 110111
    3, // 111000
    4, // 111001
    4, // 111010
    5, // 111011
    4, // 111100
    5, // 111101
    5, // 111110
    6, // 111111
    1, // 1000000
    2, // 1000001
    2, // 1000010
    3, // 1000011
    2, // 1000100
    3, // 1000101
    3, // 1000110
    4, // 1000111
    2, // 1001000
    3, // 1001001
    3, // 1001010
    4, // 1001011
    3, // 1001100
    4, // 1001101
    4, // 1001110
    5, // 1001111
    2, // 1010000
    3, // 1010001
    3, // 1010010
    4, // 1010011
    3, // 1010100
    4, // 1010101
    4, // 1010110
    5, // 1010111
    3, // 1011000
    4, // 1011001
    4, // 1011010
    5, // 1011011
    4, // 1011100
    5, // 1011101
    5, // 1011110
    6, // 1011111
    2, // 1100000
    3, // 1100001
    3, // 1100010
    4, // 1100011
    3, // 1100100
    4, // 1100101
    4, // 1100110
    5, // 1100111
    3, // 1101000
    4, // 1101001
    4, // 1101010
    5, // 1101011
    4, // 1101100
    5, // 1101101
    5, // 1101110
    6, // 1101111
    3, // 1110000
    4, // 1110001
    4, // 1110010
    5, // 1110011
    4, // 1110100
    5, // 1110101
    5, // 1110110
    6, // 1110111
    4, // 1111000
    5, // 1111001
    5, // 1111010
    6, // 1111011
    5, // 1111100
    6, // 1111101
    6, // 1111110
    7, // 1111111
    1, // 10000000
    2, // 10000001
    2, // 10000010
    3, // 10000011
    2, // 10000100
    3, // 10000101
    3, // 10000110
    4, // 10000111
    2, // 10001000
    3, // 10001001
    3, // 10001010
    4, // 10001011
    3, // 10001100
    4, // 10001101
    4, // 10001110
    5, // 10001111
    2, // 10010000
    3, // 10010001
    3, // 10010010
    4, // 10010011
    3, // 10010100
    4, // 10010101
    4, // 10010110
    5, // 10010111
    3, // 10011000
    4, // 10011001
    4, // 10011010
    5, // 10011011
    4, // 10011100
    5, // 10011101
    5, // 10011110
    6, // 10011111
    2, // 10100000
    3, // 10100001
    3, // 10100010
    4, // 10100011
    3, // 10100100
    4, // 10100101
    4, // 10100110
    5, // 10100111
    3, // 10101000
    4, // 10101001
    4, // 10101010
    5, // 10101011
    4, // 10101100
    5, // 10101101
    5, // 10101110
    6, // 10101111
    3, // 10110000
    4, // 10110001
    4, // 10110010
    5, // 10110011
    4, // 10110100
    5, // 10110101
    5, // 10110110
    6, // 10110111
    4, // 10111000
    5, // 10111001
    5, // 10111010
    6, // 10111011
    5, // 10111100
    6, // 10111101
    6, // 10111110
    7, // 10111111
    2, // 11000000
    3, // 11000001
    3, // 11000010
    4, // 11000011
    3, // 11000100
    4, // 11000101
    4, // 11000110
    5, // 11000111
    3, // 11001000
    4, // 11001001
    4, // 11001010
    5, // 11001011
    4, // 11001100
    5, // 11001101
    5, // 11001110
    6, // 11001111
    3, // 11010000
    4, // 11010001
    4, // 11010010
    5, // 11010011
    4, // 11010100
    5, // 11010101
    5, // 11010110
    6, // 11010111
    4, // 11011000
    5, // 11011001
    5, // 11011010
    6, // 11011011
    5, // 11011100
    6, // 11011101
    6, // 11011110
    7, // 11011111
    3, // 11100000
    4, // 11100001
    4, // 11100010
    5, // 11100011
    4, // 11100100
    5, // 11100101
    5, // 11100110
    6, // 11100111
    4, // 11101000
    5, // 11101001
    5, // 11101010
    6, // 11101011
    5, // 11101100
    6, // 11101101
    6, // 11101110
    7, // 11101111
    4, // 11110000
    5, // 11110001
    5, // 11110010
    6, // 11110011
    5, // 11110100
    6, // 11110101
    6, // 11110110
    7, // 11110111
    5, // 11111000
    6, // 11111001
    6, // 11111010
    7, // 11111011
    6, // 11111100
    7, // 11111101
    7, // 11111110
    8, // 11111111
};

unsigned long long popcount_naive(unsigned size, uint16_t* data)
{
    unsigned long long acc = 0;

    for (unsigned i = 0; i < size; ++i)
    {
        uint16_t num = data[i];
        while (num)
        {
            // Naive approach: Get the last bit and shift the number
            acc += num & 1;
            num = num >> 1;
        }
    }

    return acc;
}

unsigned long long popcount_lookup_table(unsigned size, uint8_t* data)
{
    unsigned long long acc = 0;

    for (unsigned i = 0; i < size; ++i)
        // Look it up!
        acc += bits[data[i]];

    return acc;
}

unsigned long long popcount_builtin(unsigned size, uint64_t* data)
{
    unsigned long long acc = 0;

    for (unsigned i = 0; i < size; ++i)
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        // This is really fast if your CPU has a dedicated instruction (and it should)
        acc += __builtin_popcountll(data[i]);

    return acc;
}

// Usage:
//   ./count_set_bits_lookup_table <amount of random numbers>, e.g:
//   ./count_set_bits_lookup_table 2017
//   -> Naive approach: 7962 in 107μs
//   -> Lookup table: 7962 in 20μs
//   -> GCC builtin: 7962 in 5μs

int main(int argc, char* argv[])
{
    if (argc < 2)
        return -1;

    unsigned amount;
    std::stringstream ss;
    ss << argv[1];
    ss >> amount;

    // we want length divisible by 4
    unsigned length = amount + (-amount) % 4;

    uint16_t* numbers = new uint16_t[length];

    std::default_random_engine generator;
    std::uniform_int_distribution<uint16_t> dist(0, 255);

    for (unsigned n = 0; n < amount; ++n)
        numbers[n] = dist(generator);
    // pad with zeros
    for (unsigned n = amount; n < length; ++n)
        numbers[n] = 0;

    unsigned long long count;

    std::chrono::high_resolution_clock a_clock;
    auto start = a_clock.now();
    count = popcount_naive(amount, numbers);
    auto end = a_clock.now();
    std::cout << "Naive approach: " << count << " in " <<
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs" <<
        std::endl;

    start = a_clock.now();
    count = popcount_lookup_table(2 * amount, (uint8_t*)(numbers));
    end = a_clock.now();
    std::cout << "Lookup table: " << count << " in " <<
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs" <<
        std::endl;

    start = a_clock.now();
    count = popcount_builtin(length / 4, (uint64_t*)(numbers));
    end = a_clock.now();
    std::cout << "GCC builtin: " << count << " in " <<
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs" <<
        std::endl;
}
