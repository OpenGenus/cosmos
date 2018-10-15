/*
 * Part of Cosmos by OpenGenus Foundation
 */

/*
 * guide
 *
 * 1. substitute iterator (col:28)
 * 2. substitute sort algorithm (col: 70)
 * 3. run
 */

#define CATCH_CONFIG_MAIN
#ifndef SORT_TEST
#define SORT_TEST
#include "../../../test/c++/catch.hpp"
#include <forward_list>
#include <list>
#include <deque>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "../src/merge_sort/merge_sort.cpp"
#include "../src/quick_sort/quick_sort.cpp"
#include "../src/insertion_sort/insertion_sort.cpp"
#include "../src/selection_sort/selection_sort.cpp"
#include "../src/bubble_sort/bubble_sort.cpp"

// substitute iterator
// #define AT_LEAST_INPUT_ITERATOR
// #define AT_LEAST_BIDIRECTIONAL_ITERATOR
#define AT_LEAST_RANDOM_ITERATOR

#ifdef AT_LEAST_INPUT_ITERATOR
template<typename _T>
using ContainerType = std::forward_list<_T>;
#endif

#ifdef AT_LEAST_BIDIRECTIONAL_ITERATOR
template<typename _T>
using ContainerType = std::list<_T>;
#endif

#ifdef AT_LEAST_RANDOM_ITERATOR
template<typename _T>
using ContainerType = std::deque<_T>;
#endif

template<typename _Iter1,
         typename _Iter2,
         typename _Tp = typename std::iterator_traits<_Iter1>::value_type>
bool
isSame(_Iter1 aBegin, _Iter1 aEnd, _Iter2 bBegin)
{
    auto aIt = aBegin;
    auto bIt = bBegin;
    for (; aIt != aEnd; ++aIt, ++bIt)
        if (*aIt != *bIt)
            return false;

    return true;
}

TEST_CASE("sort algorithm")
{
    srand(static_cast<unsigned int>(clock()));

    void (*psf)(int *, int *);
    void (*vsf)(ContainerType<int>::iterator, ContainerType<int>::iterator);

    // substitute sort algorithm
    vsf = mergeSort;
    psf = mergeSort;
//    vsf = bubbleSort;
//    psf = bubbleSort;
//    vsf = insertionSort;
//    psf = insertionSort;
//    vsf = selectionSort;
//    psf = selectionSort;
//    vsf = quickSort;
//    psf = quickSort;

    auto stdSort = [](ContainerType<int>&expectStdContainer)
                   {
#ifdef AT_LEAST_RANDOM_ITERATOR
                       std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
                       expectStdContainer.sort();
#endif
                   };

    auto testSTLContainer = [&](int sz)
                            {
                                ContainerType<int> actualStdContainer, expectStdContainer;

                                // randomize elems
                                for (int i = 0; i < sz; ++i)
                                {
                                    int randomValue = std::rand() % (sz / 2 + 1);
                                    actualStdContainer.push_front(randomValue);
                                    expectStdContainer.push_front(randomValue);
                                }

                                stdSort(expectStdContainer);
                                vsf(actualStdContainer.begin(), actualStdContainer.end());

                                CHECK(isSame(actualStdContainer.begin(),
                                             actualStdContainer.end(),
                                             expectStdContainer.begin()));
                            };

    auto testPODPtr = [&](int sz)
                      {
                          int *actualDynamicArray = new int[sz];
                          int *actualDynamicArrayEnd = actualDynamicArray + sz;
                          ContainerType<int> expectStdContainer;

                          // randomize elems
                          for (int i = 0; i < sz; ++i)
                          {
                              int randomValue = std::rand() % (sz / 2 + 1);
                              actualDynamicArray[i] = randomValue;
                              expectStdContainer.push_front(randomValue);
                          }

                          stdSort(expectStdContainer);
                          psf(actualDynamicArray, actualDynamicArrayEnd);

                          CHECK(isSame(actualDynamicArray,
                                       actualDynamicArrayEnd,
                                       expectStdContainer.begin()));
                          delete[] actualDynamicArray;
                      };

    SECTION("empty")
    {
        testPODPtr(0);
        testSTLContainer(0);
    };

    SECTION("1 elem")
    {
        testPODPtr(1);
        testSTLContainer(1);
    }

    SECTION("2 elems")
    {
        for (int i = 0; i < 1000; ++i)
        {
            testPODPtr(2);
            testSTLContainer(2);
        }
    }

    SECTION("3 elems") {
        for (int i = 0; i < 1000; ++i)
        {
            testPODPtr(3);
            testSTLContainer(3);
        }
    }

    SECTION("large size")
    {
        testPODPtr(1e6);
        testSTLContainer(1e6);
    }

    SECTION("multiple random size")
    {
        for (int i = 0; i < 10000; ++i)
        {
            testPODPtr(100 + std::rand() % 50);
            testSTLContainer(100 + std::rand() % 50);
        }
    }
}
#endif // SORT_TEST
