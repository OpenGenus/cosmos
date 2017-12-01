/*
 Part of Cosmos by OpenGenus Foundation
 */

/*
 guide

 1. substitute iterator (col:26)
 2. substitute sort algorithm (col: 63)
 3. run
 */

#ifndef SORT_TEST
#define SORT_TEST
#include "catch.hpp"
#include <forward_list>
#include <list>
#include <deque>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include "insertion_sort.cpp"
#include "selection_sort.cpp"
#include "bubble_sort.cpp"

// substitute iterator
//#define AT_LEAST_INPUT_ITERATOR
#define AT_LEAST_BIDIRECTIONAL_ITERATOR
//#define AT_LEAST_RANDOM_ITERATOR

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
isSame(_Iter1 aBegin, _Iter1 aEnd, _Iter2 bBegin, _Iter2 bEnd)
{
    auto aIt = aBegin;
    auto bIt = bBegin;
    for (; aIt != aEnd; ++aIt, ++bIt)
        if (*aIt != *bIt)
            return false;

    return true;
}

TEST_CASE("sort algorithm") {
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

    SECTION("test empty") {
        const int sz = 0;
        int *actualDynamicArray = new int[sz];
        int *actualDynamicArrayEnd = actualDynamicArray + sz;
        ContainerType<int> actualStdContainer(sz), expectStdContainer;

        // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
        std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
        expectStdContainer.sort();
#endif

        psf(actualDynamicArray, actualDynamicArrayEnd);
        vsf(actualStdContainer.begin(), actualStdContainer.end());
        delete[] actualDynamicArray;
    }

    SECTION("test has 1 elem") {
        const int sz = 1;
        int *actualDynamicArray = new int[sz] {1};
        int *actualDynamicArrayEnd = actualDynamicArray + sz;
        ContainerType<int> actualStdContainer{1}, expectStdContainer{1};

        // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
        std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
        expectStdContainer.sort();
#endif

        psf(actualDynamicArray, actualDynamicArrayEnd);
        vsf(actualStdContainer.begin(), actualStdContainer.end());

        CHECK(isSame(actualDynamicArray,
                     actualDynamicArrayEnd,
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        CHECK(isSame(actualStdContainer.begin(),
                     actualStdContainer.end(),
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        delete[] actualDynamicArray;
    }

    SECTION("test has 2 elems") {
        const int sz = 2;
        int *actualDynamicArray = new int[sz] {3, 1};
        int *actualDynamicArrayEnd = actualDynamicArray + sz;
        ContainerType<int> actualStdContainer{3, 1}, expectStdContainer{3, 1};

        // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
        std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
        expectStdContainer.sort();
#endif

        psf(actualDynamicArray, actualDynamicArrayEnd);
        vsf(actualStdContainer.begin(), actualStdContainer.end());

        CHECK(isSame(actualDynamicArray,
                     actualDynamicArrayEnd,
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        CHECK(isSame(actualStdContainer.begin(),
                     actualStdContainer.end(),
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        delete[] actualDynamicArray;
    }

    SECTION("test has 3 elems") {
        const int sz = 3;
        int *actualDynamicArray = new int[sz] {2, 3, 1};
        int *actualDynamicArrayEnd = actualDynamicArray + sz;
        ContainerType<int> actualStdContainer{2, 3, 1}, expectStdContainer{2, 3, 1};

        // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
        std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
        expectStdContainer.sort();
#endif

        psf(actualDynamicArray, actualDynamicArrayEnd);
        vsf(actualStdContainer.begin(), actualStdContainer.end());

        CHECK(isSame(actualDynamicArray,
                     actualDynamicArrayEnd,
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        CHECK(isSame(actualStdContainer.begin(),
                     actualStdContainer.end(),
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        delete[] actualDynamicArray;
    }

    SECTION("large size")
    {
        size_t sz = 1e6;
        int *actualDynamicArray = new int[sz];
        int *actualDynamicArrayEnd = actualDynamicArray + sz;
        ContainerType<int> actualStdContainer{}, expectStdContainer{};

        // randomize elems
        std::back_insert_iterator<ContainerType<int>> actualIt(actualStdContainer),
                                                      expectIt(expectStdContainer);
        for (size_t i = sz; i > 0; --i, ++actualIt, ++expectIt)
        {
            int randomValue = std::rand();
            actualDynamicArray[i - 1] = randomValue;
            actualStdContainer.push_front(randomValue);
            expectStdContainer.push_front(randomValue);
        }

        // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
        std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
        expectStdContainer.sort();
#endif

        psf(actualDynamicArray, actualDynamicArray + sz);
        vsf(actualStdContainer.begin(), actualStdContainer.end());

        CHECK(isSame(actualDynamicArray,
                     actualDynamicArrayEnd,
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        CHECK(isSame(actualStdContainer.begin(),
                     actualStdContainer.end(),
                     expectStdContainer.begin(),
                     expectStdContainer.end()));
        delete[] actualDynamicArray;
    }

    SECTION("test has random size elems and random value") {
        srand((int)clock());
        for (int t = 0; t < 5000; ++t)
        {
            // randomize size
            int sz = 75 + std::rand() % 50;

            int *actualDynamicArray = new int[sz];
            int *actualDynamicArrayEnd = actualDynamicArray + sz;
            ContainerType<int> actualStdContainer{}, expectStdContainer{};

            // randomize elems
            std::back_insert_iterator<ContainerType<int>> actualIt(actualStdContainer),
                                                          expectIt(expectStdContainer);
            for (int i = 0; i < sz; ++i, ++actualIt, ++expectIt)
            {
                int randomValue = std::rand() % 100;
                actualDynamicArray[i] = randomValue;
                actualStdContainer.push_front(randomValue);
                expectStdContainer.push_front(randomValue);
            }

            // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
            std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
            expectStdContainer.sort();
#endif

            psf(actualDynamicArray, actualDynamicArray + sz);
            vsf(actualStdContainer.begin(), actualStdContainer.end());

            CHECK(isSame(actualDynamicArray,
                         actualDynamicArrayEnd,
                         expectStdContainer.begin(),
                         expectStdContainer.end()));
            CHECK(isSame(actualStdContainer.begin(),
                         actualStdContainer.end(),
                         expectStdContainer.begin(),
                         expectStdContainer.end()));
            delete[] actualDynamicArray;
        }
    }
}
#endif // SORT_TEST
