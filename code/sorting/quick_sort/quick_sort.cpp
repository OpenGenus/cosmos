/*
 Part of Cosmos by OpenGenus Foundation

 quick sort synopsis

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void _quickSort(_Random_Acccess_Iter first,
                _Random_Acccess_Iter last,
                _Compare comp,
                std::random_access_iterator_tag);

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp);

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end);
 */

#include <functional>

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void _quickSort(_Random_Acccess_Iter first,
                _Random_Acccess_Iter last,
                _Compare comp,
                std::random_access_iterator_tag) {
    if (first < last)
    {
        // first is pivot
        _Random_Acccess_Iter i = first, j = last + 1;
        while (true)
        {
            while (i + 1 <= last && comp(*++i, *first))
                ;
            while (j - 1 >= first && comp(*first, *--j))
                ;
            if (i >= j)
                break;
            std::swap(*i, *j);
        }
        std::swap(*first, *j);
        _quickSort(first, j - 1, comp, std::random_access_iterator_tag());
        _quickSort(j + 1, last, comp, std::random_access_iterator_tag());
    }
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp) {
    if (begin == end)
        return;
    --end;

    return _quickSort(begin,
                      end,
                      comp,
                      typename std::iterator_traits<_Random_Acccess_Iter>::iterator_category());
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end) {
    return quickSort(begin, end, std::less<_Tp>());
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

    quickSort(v.begin(), v.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < sz; ++i)
        if (v.at(i) != t.at(i))
            cout << "error" << endl;

    sz = 20 + rand() % 2;
    float a[sz], b[sz];
    for (int i = 0; i < sz; i++)
    {
        a[i] = rand() % 10;
        b[i] = a[i];
    }

    quickSort(a, a + sz);
    sort(b, b + sz);
    for (int i = 0; i < sz; ++i)
        if (a[i] != b[i])
            cout << "error" << endl;

    return 0;
}

// */
