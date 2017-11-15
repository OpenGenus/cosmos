/*
 Part of Cosmos by OpenGenus Foundation
 */

#include "catch.hpp"
#include <vector>
#include <iterator>
#include "binary_search.cpp"
#include "linear_search.cpp"
using std::vector;

TEST_CASE("search algorithm") {
    // common interface
    int* (*psf)(int*, int*, int const&);
    vector<int>::iterator (*vsf)(vector<int>::iterator, vector<int>::iterator, int const&);

    // substitute our search algorithm
    vsf = linear_search;
    psf = linear_search;

    SECTION("test empty") {
        int *arr = new int[0];
        vector<int> vec{};

        CHECK(psf(arr, arr+sizeof(arr)/sizeof(int), 0) == arr);
        CHECK(vsf(vec.begin(), vec.end(), 0) == vec.end());
    }

    SECTION("test has 1 elem") {
        int *arr = new int[1]{1};
        int *arr_end = arr+1;
        vector<int> vec{1};

        CHECK(psf(arr, arr_end, 0) == arr_end);
        CHECK(vsf(vec.begin(), vec.end(), 0) == vec.end());

        CHECK(psf(arr, arr_end, 1) == arr);
        CHECK(vsf(vec.begin(), vec.end(), 1) == vec.begin());

        CHECK(psf(arr, arr_end, 2) == arr_end);
        CHECK(vsf(vec.begin(), vec.end(), 2) == vec.end());
    }

    SECTION("test has 2 elems") {
        int *arr = new int[2]{1, 3};
        int *arr_end = arr+2;
        vector<int> vec{1, 3};

        CHECK(psf(arr, arr_end, 0) == arr_end);
        CHECK(vsf(vec.begin(), vec.end(), 0) == vec.end());

        CHECK(psf(arr, arr_end, 1) == arr);
        CHECK(vsf(vec.begin(), vec.end(), 1) == vec.begin());

        CHECK(psf(arr, arr_end, 2) == arr_end);
        CHECK(vsf(vec.begin(), vec.end(), 2) == vec.end());

        CHECK(psf(arr, arr_end, 3) == arr+1);
        CHECK(vsf(vec.begin(), vec.end(), 3) == vec.begin()+1);

        CHECK(psf(arr, arr_end, 4) == arr_end);
        CHECK(vsf(vec.begin(), vec.end(), 4) == vec.end());
    }

    SECTION("test has random size elems and random value") {
        srand((int)clock());
        for (int t = 0; t < 30; ++t) {
            // random size
            int rand = 50 + std::rand()%100;
            int *arr = new int[rand];
            vector<int> vec(rand);

            // random elems
            for (int i = 0; i < rand; ++i) {
                int rv = std::rand()%100;
                arr[i] = rv;
            }
            std::sort(arr, arr+rand);
            for (int i = 0; i < rand; ++i) {
                vec[i] = arr[i];
            }

            // based standard search
            // if found then compare to value, else compare to pointer is end
            for (int i = 0; i < rand*10; ++i) {
                int rv = std::rand()%100;
                if (std::binary_search(arr, arr+rand, rv)) {
                    CHECK(*psf(arr, arr+rand, rv) == rv);
                    CHECK(*vsf(vec.begin(), vec.end(), rv) == rv);
                } else {
                    CHECK(psf(arr, arr+rand, rv) == arr+rand);
                    CHECK(vsf(vec.begin(), vec.end(), rv) == vec.end());
                }
            }
        }
    }
}
