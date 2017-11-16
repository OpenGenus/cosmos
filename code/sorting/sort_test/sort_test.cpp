/*
 Part of Cosmos by OpenGenus Foundation
 */

#ifndef SORT_TEST
#define SORT_TEST
#include "catch.hpp"
#include <vector>
#include <iterator>
#include "quick_sort.cpp"
#include "merge_sort.cpp"

#include <iostream>

using std::vector;

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
bool isSame(_Random_Acccess_Iter aBegin,
            _Random_Acccess_Iter aEnd,
            _Random_Acccess_Iter bBegin,
            _Random_Acccess_Iter bEnd) {
    for (auto aIt = aBegin, bIt = bBegin; aIt != aEnd; ++aIt, ++bIt) {
        if (*aIt != *bIt)
            return false;
    }
    return true;
}

using namespace std;
TEST_CASE("sort algorithm") {
    void (*psf)(int*, int*);
    void (*vsf)(vector<int>::iterator, vector<int>::iterator);
    
    // substitute search algorithm
    vsf = merge_sort::mergeSort;
    psf = merge_sort::mergeSort;
    
    SECTION("test empty") {
        const int sz = 0;
        int *arr = new int[sz];
        int *arr_end = arr+sz;
        vector<int> vec(sz);
        
        psf(arr, arr_end);
        vsf(vec.begin(), vec.end());
    }
    
    SECTION("test has 1 elem") {
        const int sz = 1;
        int *arr = new int[sz];
        int *arr_end = arr+sz;
        vector<int> vec(sz);
        arr[0] = 1;
        vec[0] = 1;
        
        psf(arr, arr_end);
        vsf(vec.begin(), vec.end());
        
        CHECK(arr[0] == 1);
        CHECK(vec[0] == 1);
    }
    
    SECTION("test has 2 elems") {
        const int sz = 2;
        int *arr = new int[sz]{3, 1};
        int *arr_end = arr+sz;
        vector<int> vec(sz);
        vec[0] = 3;
        vec[1] = 1;
        
        psf(arr, arr_end);
        vsf(vec.begin(), vec.end());
        
        CHECK(arr[0] == 1);
        CHECK(arr[1] == 3);
        CHECK(vec[0] == 1);
        CHECK(vec[1] == 3);
    }
    
    SECTION("test has random size elems and random value") {
        srand((int)clock());
        for (int t = 0; t < 5000; ++t) {
            // random size
            int rand = 75 + std::rand()%50;
            int *actualArr = new int[rand], *expectArr = new int[rand];
            vector<int> actualVec(rand), expectVec(rand);

            // random elems
            auto actualIt = actualVec.begin(), expectIt = expectVec.begin();
            for (int i = 0; i < rand; ++i, ++actualIt, ++expectIt) {
                int rv = std::rand()%100;
                expectArr[i] = rv;
                actualArr[i] = rv;
                *expectIt = rv;
                *actualIt = rv;
            }

            // based standard search
            // if found then compare to value, else compare to pointer is end
            psf(actualArr, actualArr+rand);
            vsf(actualVec.begin(), actualVec.end());
            std::sort(expectArr, expectArr+rand);
            std::sort(expectVec.begin(), expectVec.end());

            CHECK(isSame(actualArr, actualArr+rand, expectArr, expectArr+rand));
            CHECK(isSame(actualVec.begin(), actualVec.end(), expectVec.begin(), expectVec.end()));
        }
    }
}
#endif // SORT_TEST
