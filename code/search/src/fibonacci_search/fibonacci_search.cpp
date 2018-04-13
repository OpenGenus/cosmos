/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * fibonacci search synopsis
 *
 * warning: in order to follow the convention of STL, the interface is [begin, end) !!!
 *
 * namespace fibonacci_search_impl
 * {
 * template<typename _Input_Iter,
 *          typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
 * _Input_Iter
 * fibonacciSearchImpl(_Input_Iter begin,
 *                     _Input_Iter end,
 *                     _Tp const &find,
 *                     _Compare comp,
 *                     std::input_iterator_tag);
 * } // fibonacci_search_impl
 *
 * template<typename _Input_Iter,
 *          typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
 * _Input_Iter
 * fibonacciSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find, _Compare comp);
 *
 * template<typename _Input_Iter,
 *          typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type>
 * _Input_Iter
 * fibonacciSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find);
 */

#include <functional>

namespace fibonacci_search_impl
{
template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type,
         typename _Compare>
_Input_Iter
fibonacciSearchImpl(_Input_Iter begin,
                    _Input_Iter end,
                    _Tp const &find,
                    _Compare comp,
                    std::input_iterator_tag)
{
    if (begin == end)
        return end;

    size_t dist = std::distance(begin, end);
    size_t fibMMm2 = 0;     // (m-2)'th Fibonacci No.
    size_t fibMMm1 = 1;     // (m-1)'th Fibonacci No.
    size_t fibM = fibMMm2 + fibMMm1;

    while (fibM < dist)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    size_t offset = -1;
    auto it = begin;

    while (fibM > 1)
    {
        // prevent overflow
        size_t i = std::min(offset + fibMMm2, dist - 1);
        it = begin;
        std::advance(it, i);

        if (comp(*it, find))
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (comp(find, *it))
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return it;
    }

    // comparing the last element with find
    it = begin;
    std::advance(it, offset + 1);
    if (fibMMm1 && *it == find)
        return it;

    return end;
}
} // fibonacci_search_impl

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
_Input_Iter
fibonacciSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find, _Compare comp)
{
    auto category = typename std::iterator_traits<_Input_Iter>::iterator_category();

    return fibonacci_search_impl::fibonacciSearchImpl(begin, end, find, comp, category);
}

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type>
_Input_Iter
fibonacciSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find)
{
    return fibonacciSearch(begin, end, find, std::less<_Tp>());
}
