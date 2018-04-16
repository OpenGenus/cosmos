/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * merge sort synopsis
 *
 * namespace merge_sort_impl {
 * template<typename _Random_Acccess_Iter>
 * _Random_Acccess_Iter
 * advance(_Random_Acccess_Iter it, std::ptrdiff_t n);
 * } // merge_sort_impl
 *
 * template<typename _Random_Acccess_Iter, typename _Compare>
 * void mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp);
 *
 * template<typename _Random_Acccess_Iter>
 * void mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end);
 */

#include <list>
#include <iterator>
#include <cstddef>

namespace merge_sort_impl {
template<typename _Random_Acccess_Iter>
_Random_Acccess_Iter
advance(_Random_Acccess_Iter it, std::ptrdiff_t n)
{
    std::advance(it, n);

    return it;
}

template<typename _Random_Acccess_Iter, typename _Compare>
void merge(_Random_Acccess_Iter begin,
           _Random_Acccess_Iter end,
           _Compare comp)
{
    using value_type = typename std::iterator_traits<_Random_Acccess_Iter>::value_type;
    auto end1 = begin;
    std::advance(end1, std::distance(begin, end) >> 1);

    auto begin1 = begin,
         begin2 = end1,
         end2 = end;

    std::list<value_type> tmp{};

    while (begin1 < end1 && begin2 < end2)
        tmp.push_back(comp(*begin1, *begin2) ? *begin1++ : *begin2++);
    while (begin1 < end1)
        *--begin2 = *--end1;
    while (!tmp.empty())
    {
        *--begin2 = tmp.back();
        tmp.pop_back();
    }
}
} // merge_sort_impl

template<typename _Random_Acccess_Iter, typename _Compare>
void
mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp)
{
    size_t dist = std::distance(begin, end);
    if (dist > 1)
    {
        auto mid = begin;
        std::advance(mid, dist >> 1);

        mergeSort(begin, mid, comp);
        mergeSort(mid, end, comp);

        merge_sort_impl::merge(begin, end, comp);
    }
}

template<typename _Random_Acccess_Iter>
void
mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end)
{
    using value_type = typename std::iterator_traits<_Random_Acccess_Iter>::value_type;

    mergeSort(begin, end, std::less<value_type>());
}
