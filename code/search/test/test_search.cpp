/*
 * Part of Cosmos by OpenGenus Foundation
 */

#define CATCH_CONFIG_MAIN
#include "../../../test/c++/catch.hpp"
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include "../src/binary_search/binary_search.cpp"
#include "../src/exponential_search/exponential_search.cpp"
#include "../src/fibonacci_search/fibonacci_search.cpp"
#include "../src/interpolation_search/interpolation_search.cpp"
#include "../src/jump_search/jump_search.cpp"
#include "../src/linear_search/linear_search.cpp"
#include "../src/ternary_search/ternary_search.cpp"

// #define InputIterator
#define RandomAccessIterator
#define SearchFunc binarySearch

#ifdef InputIteratorContainer
#define Container list
#endif
#ifdef RandomAccessIterator
#define Container vector
#endif

using std::list;
using std::vector;

TEST_CASE("search algorithm")
{
    // common interface
    int *(*psf)(int *, int *, const int &);
    Container<int>::iterator (*vsf)(Container<int>::iterator,
                                    Container<int>::iterator,
                                    const int &);

    // substitute our search algorithm
    vsf = SearchFunc;
    psf = SearchFunc;

    auto testWithRandomValue = [&](size_t size)
                               {
                                   using std::rand;
                                   using std::sort;

                                   // size == 0: avoid division by 0
                                   int boundaryOfPossibleValue =
                                       static_cast<int>(size + (size == 0));

                                   // initial containers
                                   int *podPtr = new int[size];
                                   auto podPtrEnd = podPtr + size;
                                   Container<int> container(size);

                                   // initial random values for containers
                                   for (size_t i = 0; i < size; ++i)
                                   {
                                       int randomValue = rand() % boundaryOfPossibleValue;
                                       podPtr[i] = randomValue;
                                       container[i] = randomValue;
                                   }
                                   sort(podPtr, podPtrEnd);
                                   sort(container.begin(), container.end());

                                   // based standard search
                                   // if found then compare to value, else compare to pointer is end
                                   // range of random values is [0:boundOfPossibleValue]
                                   // +/-30 is test out of boundary
                                   for (int i = -30; i < boundaryOfPossibleValue + 30; ++i)
                                       if (std::binary_search(podPtr, podPtrEnd, i))
                                       {
                                           CHECK(*psf(podPtr, podPtrEnd, i) == i);
                                           CHECK(*vsf(container.begin(), container.end(), i) == i);
                                       }
                                       else
                                       {
                                           CHECK(psf(podPtr, podPtrEnd, i) == podPtrEnd);
                                           CHECK(vsf(container.begin(),
                                                     container.end(), i) == container.end());
                                       }

                                   delete[] podPtr;
                               };

    SECTION("empty")
    {
        testWithRandomValue(0);
    }

    SECTION("1 elem")
    {
        for (int i = 0; i < 1000; ++i)
            testWithRandomValue(1);
    }

    SECTION("2 elems")
    {
        for (int i = 0; i < 1000; ++i)
            testWithRandomValue(2);
    }

    SECTION("3 elems")
    {
        for (int i = 0; i < 1000; ++i)
            testWithRandomValue(3);
    }

    SECTION("random size")
    {
        for (int i = 0; i < 1000; ++i)
            testWithRandomValue(50 + std::rand() % 100);
    }

    SECTION("large size")
    {
        testWithRandomValue(1e6 + std::rand() % 10000);
    }
}
