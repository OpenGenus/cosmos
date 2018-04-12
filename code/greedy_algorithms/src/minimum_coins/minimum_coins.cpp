/* Part of Cosmos by OpenGenus Foundation */

/* This file uses features only available on C++11.
 * Compile using -std=c++11 or -std=gnu++11 flag.  */

#include <iostream>
#include <vector>

std::vector<unsigned int> minimum_coins(int value, std::vector<unsigned int> denominations)
{
    std::vector<unsigned int> result;
    // Assuming denominations is sorted in descendig order
    for (int cur_denom : denominations)
        while (cur_denom <= value)
        {
            result.push_back(cur_denom);
            value -= cur_denom;
        }
    return result;
}

// Testing
int main()
{
    std::vector<unsigned int> result = minimum_coins(191, {100, 50, 25, 10, 5, 1});
    for (auto i = result.begin(); i != result.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    return 0;
}
