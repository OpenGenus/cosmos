/*
    Part of Cosmos by OpenGenus Foundation

    quick sort synopsis

template<typename _Random_Acccess_Iter, typename _Compare>
void quicksort_impl(_Random_Acccess_Iter first, _Random_Acccess_Iter last, _Compare comp);

template<typename _Random_Acccess_Iter, typename _Compare>
void quicksort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp);

template<typename _Random_Acccess_Iter,
typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void quicksort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end);
*/

#include <functional>

template<typename _Random_Acccess_Iter, typename _Compare>
void quicksort_impl(_Random_Acccess_Iter first, _Random_Acccess_Iter last, _Compare comp) {
    if (first < last) {
        // first is pivot
        _Random_Acccess_Iter i = first, j = last + 1;
        while (true) {
            while (i + 1 <= last && comp(*++i, *first))
                ;
            while (j - 1 >= first && comp(*first, *--j))
                ;
            if (i >= j)
                break;
            std::swap(*i, *j);
        }
        std::swap(*first, *j);
        quicksort_impl(first, j - 1, comp);
        quicksort_impl(j + 1, last, comp);
    }
}

template<typename _Random_Acccess_Iter, typename _Compare>
void quicksort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp) {
    if (begin == end)
        return;
    --end;

    return quicksort_impl(begin, end, comp);
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void quicksort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end) {
    return quicksort(begin, end, std::less<_Tp>());
}

/*
// for test
 #include <iostream>
 #include <algorithm>
 #include <iomanip>
 #include <vector>
 #include <deque>
 #include <array>
 #include <string>

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

int main()
{
    using namespace std;

    vector<int> v, t;
    srand((unsigned)clock());

    int sz = 20 + rand() % 2;
    for (int i = 0; i < sz; i++)
        v.push_back(rand() % 10);
    t = v;

    quicksort(v.begin(), v.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < sz; ++i)
        if (v.at(i) != t.at(i))
            cout << "error" << endl;

    cout << endl;

    sz = 20 + rand() % 2;
    float a[sz], b[sz];
    for (int i = 0; i < sz; i++) {
        a[i] = rand() % 10;
        b[i] = a[i];
    }

    quicksort(a, a + sz);
    sort(b, b + sz);
    for (int i = 0; i < sz; ++i)
        if (a[i] != b[i])
            cout << "error" << endl;

    return 0;
}

// */
