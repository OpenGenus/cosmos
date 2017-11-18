/*
 Part of Cosmos by OpenGenus Foundation

 quick sort synopsis

template<typename _Random_Acccess_Iter,
         typename _Compare
             = std::less<typename std::iterator_traits<_Random_Acccess_Iter>::value_type>>
_Random_Acccess_Iter
partition(_Random_Acccess_Iter first, _Random_Acccess_Iter last, _Compare comp);

template<typename _Random_Acccess_Iter,
         typename _Compare
             = std::less<typename std::iterator_traits<_Random_Acccess_Iter>::value_type>>
void
quickSortImpl(_Random_Acccess_Iter first,
              _Random_Acccess_Iter last,
              _Compare comp,
              std::random_access_iterator_tag);

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void
quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp);

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void
quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end);
 */

#include <stack>
#include <functional>

template<typename _Random_Acccess_Iter,
         typename _Compare
             = std::less<typename std::iterator_traits<_Random_Acccess_Iter>::value_type>>
_Random_Acccess_Iter
partition(_Random_Acccess_Iter first, _Random_Acccess_Iter last, _Compare comp)
{
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

    return j;
}

template<typename _Random_Acccess_Iter,
         typename _Compare
             = std::less<typename std::iterator_traits<_Random_Acccess_Iter>::value_type>>
void
quickSortImpl(_Random_Acccess_Iter first,
              _Random_Acccess_Iter last,
              _Compare comp,
              std::random_access_iterator_tag)
{
    if (first < last)
    {
        // first is pivot
        auto mid = ::partition(first, last, comp);
        quickSortImpl(first,
                      mid - 1,
                      comp,
                      std::random_access_iterator_tag());
        quickSortImpl(mid + 1,
                      last,
                      comp,
                      std::random_access_iterator_tag());
    }
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void
quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp)
{
    if (begin == end)
        return;
    --end;

    auto category = typename std::iterator_traits<_Random_Acccess_Iter>::iterator_category();

    return quickSortImpl(begin, end, comp, category);
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void
quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end)
{
    return quickSort(begin, end, std::less<_Tp>());
}
