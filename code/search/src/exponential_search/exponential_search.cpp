/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * jump search synopsis
 *
 * warning: in order to follow the convention of STL, the interface is [begin, end) !!!
 *
 * namespace exponenial_search_impl
 * {
 * template<typename _Random_Access_Iter, typename _Comp,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Difference = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
 * std::pair<_Random_Access_Iter, bool>
 * binarySearchImpl(_Random_Access_Iter first,
 *                  _Random_Access_Iter last,
 *                  _Tp const &find,
 *                  _Comp comp,
 *                  std::random_access_iterator_tag);
 *
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Compare>
 * _Random_Access_Iter
 * exponentialSearchImpl(_Random_Access_Iter begin,
 *                       _Random_Access_Iter end,
 *                       _Tp const &find,
 *                       _Compare comp,
 *                       std::random_access_iterator_tag);
 * } // exponenial_search_impl
 *
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Compare>
 * _Random_Access_Iter
 * exponentialSearch(_Random_Access_Iter begin,
 *                   _Random_Access_Iter end,
 *                   _Tp const &find,
 *                   _Compare comp);
 *
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
 * _Random_Access_Iter
 * exponentialSearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find);
 */

#include <functional>

namespace exponenial_search_impl
{
template<typename _Random_Access_Iter, typename _Comp,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Difference = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool>
binarySearchImpl(_Random_Access_Iter first,
                 _Random_Access_Iter last,
                 _Tp const &find,
                 _Comp comp,
                 std::random_access_iterator_tag)
{
    while (first <= last)
    {
        auto mid = first + (last - first) / 2;

        if (comp(*mid, find))
            first = mid + 1;
        else if (comp(find, *mid))
            last = mid - 1;
        else
            return std::make_pair(mid, true);
    }

    return std::make_pair(last, false);
}

template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Compare>
_Random_Access_Iter
exponentialSearchImpl(_Random_Access_Iter begin,
                      _Random_Access_Iter end,
                      _Tp const &find,
                      _Compare comp,
                      std::random_access_iterator_tag)
{
    if (begin != end)
    {
        if (!comp(*begin, find))
            return (!comp(find, *begin)) ? begin : end;

        auto blockBegin = begin;
        auto offset = 1;
        while (blockBegin < end && comp(*blockBegin, find))
        {
            std::advance(blockBegin, offset);
            offset *= 2;
        }

        auto blockEnd = blockBegin < end ? blockBegin : end;
        std::advance(blockBegin, -1 * (offset / 2));

        auto res = binarySearchImpl(blockBegin,
                                    blockEnd,
                                    find,
                                    comp,
                                    std::random_access_iterator_tag());
        if (res.second)
            return res.first;
    }

    return end;
}
} // exponenial_search_impl

template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Compare>
_Random_Access_Iter
exponentialSearch(_Random_Access_Iter begin,
                  _Random_Access_Iter end,
                  _Tp const &find,
                  _Compare comp)
{
    auto category = typename std::iterator_traits<_Random_Access_Iter>::iterator_category();

    return exponenial_search_impl::exponentialSearchImpl(begin, end, find, comp, category);
}

template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
_Random_Access_Iter
exponentialSearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find)
{
    return exponentialSearch(begin, end, find, std::less<_Tp>());
}
