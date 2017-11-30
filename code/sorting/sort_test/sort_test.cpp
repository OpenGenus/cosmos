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
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include "insertion_sort.cpp"
#include "selection_sort.cpp"
#include "bubble_sort.cpp"

#include <iostream>
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
bool isSame(_Iter1 aBegin, _Iter1 aEnd, _Iter2 bBegin, _Iter2 bEnd) {
    auto aIt = aBegin;
    auto bIt = bBegin;
    for (; aIt != aEnd; ++aIt, ++bIt)
        if (*aIt != *bIt)
            return false;

    return true;
}

TEST_CASE("sort algorithm") {
    void (*psf)(int*, int*);
    void (*vsf)(ContainerType<int>::iterator, ContainerType<int>::iterator);
    
    // substitute search algorithm
    vsf = merge_sort::mergeSort;
    psf = merge_sort::mergeSort;
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
        int *arr = new int[sz];
        int *arr_end = arr+sz;
        ContainerType<int> stdContainer(sz);
        
        psf(arr, arr_end);
        vsf(stdContainer.begin(), stdContainer.end());
    }
    
    SECTION("test has 1 elem") {
        const int sz = 1;
        int *arr = new int[sz];
        int *arr_end = arr+sz;
        ContainerType<int> stdContainer{1};
        
        psf(arr, arr_end);
        vsf(stdContainer.begin(), stdContainer.end());
        
        CHECK(arr[0] == 1);
        CHECK(*stdContainer.begin() == 1);
    }
    
    SECTION("test has 2 elems") {
        const int sz = 2;
        int *arr = new int[sz]{3, 1};
        int *arr_end = arr+sz;
        ContainerType<int> stdContainer{3, 1};
        
        psf(arr, arr_end);
        vsf(stdContainer.begin(), stdContainer.end());
        
        CHECK(arr[0] == 1);
        CHECK(arr[1] == 3);
        CHECK(*stdContainer.begin() == 1);
        CHECK(*++stdContainer.begin() == 3);
    }
    
    SECTION("test has random size elems and random value") {
        srand((int)clock());
        for (int t = 0; t < 5000; ++t) {
            // random size
            int rand = 75 + std::rand()%50;

            int *actualDynamicArray = new int[rand];
            ContainerType<int> actualStdContainer{}, expectStdContainer{};

            // randomize elems
            std::back_insert_iterator<ContainerType<int>> actualIt(actualStdContainer), expectIt(expectStdContainer);
            for (int i = 0; i < rand; ++i, ++actualIt, ++expectIt) {
                int rv = std::rand()%100;
                actualDynamicArray[i] = rv;
                actualStdContainer.push_front(rv);
                expectStdContainer.push_front(rv);
            }

            // based on standard sort
#ifdef AT_LEAST_RANDOM_ITERATOR
            std::sort(expectStdContainer.begin(), expectStdContainer.end());
#else
            expectStdContainer.sort();
#endif

            psf(actualDynamicArray, actualDynamicArray+rand);
            vsf(actualStdContainer.begin(), actualStdContainer.end());

            CHECK(isSame(actualDynamicArray, actualDynamicArray+rand, expectStdContainer.begin(), expectStdContainer.end()));
            CHECK(isSame(actualStdContainer.begin(), actualStdContainer.end(), expectStdContainer.begin(), expectStdContainer.end()));
        }
    }
}
#endif // SORT_TEST
