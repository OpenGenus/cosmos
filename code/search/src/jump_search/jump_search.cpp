/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * jump search synopsis
 *
 * warning: in order to follow the convention of STL, the interface is [begin, end) !!!
 *
 * namespace jump_search_impl
 * {
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Compare>
 * _Random_Access_Iter
 * jumpSearchImpl(_Random_Access_Iter begin,
 *                _Random_Access_Iter end,
 *                _Tp const &find,
 *                _Compare comp,
 *                std::random_access_iterator_tag);
 * } // jump_search_impl
 *
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Compare>
 * _Random_Access_Iter
 * jumpSearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find, _Compare comp);
 *
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
 * _Random_Access_Iter
 * jumpSearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find);
 */

#include <functional>
#include <cmath>

namespace jump_search_impl
{
template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Compare>
_Random_Access_Iter
jumpSearchImpl(_Random_Access_Iter begin,
               _Random_Access_Iter end,
               _Tp const &find,
               _Compare comp,
               std::random_access_iterator_tag)
{
    if (begin != end)
    {
        auto dist = std::distance(begin, end);
        auto sqrtDist = static_cast<size_t>(std::sqrt(dist));
        auto curr = begin;

        // 1. Finding the block where element is
        while (curr < end && comp(*curr, find))
            std::advance(curr, sqrtDist);
        if (curr != begin)
            std::advance(curr, -sqrtDist);

        // 2. Doing a linear search for find in block
        while (curr < end && sqrtDist-- > 0 && comp(*curr, find))
            std::advance(curr, 1);

        // 3. If element is found
        if (!comp(*curr, find) && !comp(find, *curr))
            return curr;
    }

    return end;
}
} // jump_search_impl

template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Compare>
_Random_Access_Iter
jumpSearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find, _Compare comp)
{
    auto category = typename std::iterator_traits<_Random_Access_Iter>::iterator_category();

    return jump_search_impl::jumpSearchImpl(begin, end, find, comp, category);
}

template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
_Random_Access_Iter
jumpSearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find)
{
    return jumpSearch(begin, end, find, std::less<_Tp>());
}
