#include <array>
#include <iostream>
#include <iterator>
#include <random>

// Part of Cosmos by OpenGenus Foundation
template<class It, class RNG>
void shuffle_an_array(It first, It last, RNG &&rng)
{
    std::uniform_int_distribution<> dist;
    using ptype = std::uniform_int_distribution<>::param_type;
    using std::swap;

    for (; first != last; ++first)
        swap(*first, *(first + dist(rng, ptype(0, last - first - 1))));
}

int main()
{
    std::array<int, 10> values{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::minstd_rand rng(std::random_device{} ());
    shuffle_an_array(values.begin(), values.end(), rng);

    for (size_t i = 0; i < values.size(); ++i)
        std::cout << (i > 0 ? ", " : "") << values[i];
    std::cout << std::endl;
}
