#include <iostream>
#include <algorithm>
#include <iomanip>  // for setw

// random access container
#include <vector>
#include <deque>
#include <array>
#include <string>

/*
    Part of Cosmos by OpenGenus Foundation
*/

/*
    quick sort synopsis

// [lo, hi], warning! 'hi' not 'end(next of latest element)'

// implementation for 'standard random access container'
template<typename _Compare, typename _Random_Acccess_Iter>
_Random_Acccess_Iter _partition(_Random_Acccess_Iter lo,
                                _Random_Acccess_Iter hi,
                                _Compare comp,
                                std::random_access_iterator_tag);

template<typename _Compare, typename _Random_Acccess_Iter>
void quicksort(_Random_Acccess_Iter lo,
               _Random_Acccess_Iter hi,
               _Compare comp,
               std::random_access_iterator_tag);

template<typename _Random_Acccess_Iter>
void quicksort(_Random_Acccess_Iter lo, _Random_Acccess_Iter hi);

// implementation for 'pointer of POD(Plain Old Data structure)'
// int* explicit specialization
template<typename _Compare>
int *_partition(int *lo, int *hi, _Compare comp);

template<typename _Compare>
void quicksort(int *lo, int *hi, _Compare comp);

void quicksort(int *lo, int *hi);
*/

// [lo, hi], warning! 'hi' not 'end(next of latest element)'
// implementation for 'standard random access container'
template<typename _Compare, typename _Random_Acccess_Iter>
_Random_Acccess_Iter _partition(_Random_Acccess_Iter lo,
                                _Random_Acccess_Iter hi,
                                _Compare comp,
                                std::random_access_iterator_tag) {
    _Random_Acccess_Iter pivot = hi;
    _Random_Acccess_Iter i = lo - 1;

    for (_Random_Acccess_Iter j = lo; j < hi; ++j)
        if (comp(*j, *pivot)) {
            ++i;
            std::swap(*i, *j);
        }

    std::swap(*(i + 1), *hi);

    return i + 1;
}

template<typename _Compare, typename _Random_Acccess_Iter>
void quicksort(_Random_Acccess_Iter lo,
               _Random_Acccess_Iter hi,
               _Compare comp,
               std::random_access_iterator_tag) {
    if (lo < hi) {
        _Random_Acccess_Iter pivot = _partition(lo, hi, comp, std::random_access_iterator_tag());

        quicksort(lo, pivot - 1, comp, std::random_access_iterator_tag());
        quicksort(pivot + 1, hi, comp, std::random_access_iterator_tag());
    }
}

template<typename _Random_Acccess_Iter>
void quicksort(_Random_Acccess_Iter lo, _Random_Acccess_Iter hi) {
    if (lo < hi) {
        typedef typename std::iterator_traits<_Random_Acccess_Iter>::iterator_category tag;
        typedef typename _Random_Acccess_Iter::value_type value_type;
        typedef typename std::less_equal<value_type> less;

        _Random_Acccess_Iter pivot = _partition(lo, hi, less(), tag());

        quicksort(lo, pivot - 1, less(), tag());
        quicksort(pivot + 1, hi, less(), tag());
    }
}

// implementation for 'pointer of POD(Plain Old Data structure)'
// int* explicit specialization
template<typename _Compare>
int *_partition(int *lo, int *hi, _Compare comp) {
    int *pivot = hi;
    int *i = lo - 1;

    for (int *j = lo; j < hi; ++j)
        if (comp(*j, *pivot)) {
            ++i;
            std::iter_swap(i, j);
        }

    std::swap(*(i + 1), *hi);

    return i + 1;
}

template<typename _Compare>
void quicksort(int *lo, int *hi, _Compare comp) {
    if (lo < hi) {
        int *pivot = _partition(lo, hi, comp);

        quicksort(lo, pivot - 1, comp);
        quicksort(pivot + 1, hi, comp);
    }
}

void quicksort(int *lo, int *hi) {
    if (lo < hi) {
        typedef typename std::less_equal<int> less;

        int *pivot = _partition(lo, hi, less());

        quicksort(lo, pivot - 1, less());
        quicksort(pivot + 1, hi, less());
    }
}

void print(std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl;
}

void print(int v[], size_t len) {
    for (size_t i = 0; i < len; ++i)
        std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl;
}

// Testing the quick sort implementation
int main()
{
    // STL Container (random access)
    std::vector<int> v;
    for (int i = -3; i < 5; i++) {
        v.push_back(i);
        v.push_back(i);
    }
    std::random_shuffle(v.begin(), v.end());

    print(v);
    quicksort(v.begin(), v.end() - 1);
    print(v);

    std::cout << std::endl;

    // POD, only implement int function template not allow partial specialization
    int a[] = {4, 1, 3, 2, 5, 2, 3, 1, 5};

    print(a, sizeof(a) / sizeof(a[0]));
    quicksort(a, &a[8]);
    print(a, sizeof(a) / sizeof(a[0]));

    return 0;
}