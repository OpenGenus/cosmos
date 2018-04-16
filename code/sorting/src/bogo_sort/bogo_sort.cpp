/* Part of Cosmos by OpenGenus Foundation */
// C++ implementation of BogoSort by ldaw

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isSorted(const std::vector<int> &v)
{
    int i = v.size();
    while (--i > 0)
        if (v[i] < v[i - 1])
            return false;
    return true;
}

void shuffle(std::vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
        std::swap( v[i], v[ rand() % v.size() ] );
}

void bogoSort(std::vector<int> &v)
{
    while (!isSorted(v) )
        shuffle(v);
}

int main()
{
    std::srand(time(NULL));
    std::vector<int> v = {2, 4, 1, 3, 6, 7, 8, 5};
    // Please note, initializer lists are a C++11 feature

    bogoSort(v);

    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";

    return 0;
}
