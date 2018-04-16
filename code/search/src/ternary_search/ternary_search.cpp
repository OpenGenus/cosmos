/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * Ternary Search Uses Divide And Conquer Technique
 *
 * ternary search synopsis
 *
 * namespace ternary_search_impl
 * {
 * template<typename _RandomAccessIter,
 *          typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type,
 *          typename _Less>
 * _RandomAccessIter
 * ternarySearchImpl(_RandomAccessIter first,
 *                   _RandomAccessIter last,
 *                   const _RandomAccessIter &notFoundSentinel,
 *                   const _ValueType &find,
 *                   _Less less);
 * } // ternary_search_impl
 *
 * template<typename _RandomAccessIter,
 *          typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type,
 *          typename _Less>
 * _RandomAccessIter
 * ternarySearch(_RandomAccessIter begin, _RandomAccessIter end, const _ValueType &find, _Less less);
 *
 * template<typename _RandomAccessIter,
 *          typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type>
 * _RandomAccessIter
 * ternarySearch(_RandomAccessIter begin, _RandomAccessIter end, const _ValueType &find);
 */

#include <functional>

namespace ternary_search_impl
{
template<typename _RandomAccessIter,
         typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type,
         typename _Less>
_RandomAccessIter
ternarySearchImpl(_RandomAccessIter first,
                  _RandomAccessIter last,
                  const _RandomAccessIter &notFoundSentinel,
                  const _ValueType &find,
                  _Less less)
{
    if (first <= last)
    {
        auto dist = std::distance(first, last);

        auto leftMid = first + dist / 3, rightMid = last - dist / 3;

        auto lessThanLeftMid = less(find, *leftMid), greaterThanLeftMid = less(*leftMid, find),
             lessThanRightMid = less(find, *rightMid), greaterThanRightMid = less(*rightMid,
                                                                                  find);

        if (lessThanLeftMid == greaterThanLeftMid)
            return leftMid;

        if (lessThanRightMid == greaterThanRightMid)
            return rightMid;

        if (lessThanLeftMid)
            return ternarySearchImpl(first, leftMid - 1, notFoundSentinel, find, less);
        else if (greaterThanRightMid)
            return ternarySearchImpl(rightMid + 1, last, notFoundSentinel, find, less);
        else
            return ternarySearchImpl(leftMid + 1, rightMid - 1, notFoundSentinel, find, less);
    }

    return notFoundSentinel;
}
} // ternary_search_impl

template<typename _RandomAccessIter,
         typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type,
         typename _Less>
_RandomAccessIter
ternarySearch(_RandomAccessIter begin, _RandomAccessIter end, const _ValueType &find, _Less less)
{
    if (begin < end)
    {
        auto res = ternary_search_impl::ternarySearchImpl(begin, end - 1, end, find, less);

        return res == end ? end : res;
    }

    return end;
}

template<typename _RandomAccessIter,
         typename _ValueType = typename std::iterator_traits<_RandomAccessIter>::value_type>
_RandomAccessIter
ternarySearch(_RandomAccessIter begin, _RandomAccessIter end, const _ValueType &find)
{
    return ternarySearch(begin, end, find, std::less<_ValueType>());
}
