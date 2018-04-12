#include <iostream>
#include <bitset>


//Part of Cosmos by OpenGenus Foundation
int invertBit(int n, int numBit)
{
    n ^= 1 << numBit;
    return n;
}

int main()
{
    int numeric, numberBit, res;
    std::cout << "Enter numeric: " << std::endl;
    std::cin >> numeric;
    std::bitset<32> bs(numeric);
    std::cout << bs << '\n';
    std::cout << "Enter number bit: " << std::endl;
    std::cin >> numberBit;
    res = invertBit(numeric, numberBit);
    std::bitset<32> bsRes(res);
    std::cout << res << std::endl;
    std::cout << bsRes << std::endl;
    return 0;
}
