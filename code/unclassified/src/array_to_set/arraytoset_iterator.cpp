#include <iostream>
#include <set>

// This program converts an array to a set in C++ using iterators
// See the corresponding article here: https://iq.opengenus.org/convert-array-to-set-cpp/

int main()
{
    int a[] = {4, 11, 5, 3, 1, 6};
    std::set<int> s(std::begin(a), std::end(a));
    for (int i : s) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
