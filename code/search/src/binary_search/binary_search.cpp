/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * binary search synopsis
 *
 * warning: in order to follow the convention of STL, the interface is [begin, end) !!!
 *
 * namespace binary_search_impl
 * {
 * struct binary_search_tag {};
 * struct recursive_binary_search_tag :public binary_search_tag {};
 * struct iterative_binary_search_tag :public binary_search_tag {};
 *
 * // [first, last]
 * template<typename _Random_Access_Iter, typename _Comp,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Difference
 *              = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
 * std::pair<_Random_Access_Iter, bool>
 * binarySearchImpl(_Random_Access_Iter first,
 *                  _Random_Access_Iter last,
 *                  _Tp const &find,
 *                  _Comp comp,
 *                  std::random_access_iterator_tag,
 *                  recursive_binary_search_tag);
 *
 * // [first, last]
 * template<typename _Random_Access_Iter, typename _Comp,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename _Difference
 *              = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
 * std::pair<_Random_Access_Iter, bool>
 * binarySearchImpl(_Random_Access_Iter first,
 *                  _Random_Access_Iter last,
 *                  _Tp const &find,
 *                  _Comp comp,
 *                  std::random_access_iterator_tag,
 *                  iterative_binary_search_tag);
 * } // binary_search_impl
 *
 * // [begin, end)
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
 *          typename iterator_category
 *              = typename std::iterator_traits<_Random_Access_Iter>::iterator_category,
 *          typename _Comp>
 * _Random_Access_Iter
 * binarySearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find, _Comp comp);
 *
 * // [begin, end)
 * template<typename _Random_Access_Iter,
 *          typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
 * _Random_Access_Iter
 * binarySearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find);
 */

#include <functional>

namespace binary_search_impl
{
struct binary_search_tag {};
struct recursive_binary_search_tag : public binary_search_tag {};
struct iterative_binary_search_tag : public binary_search_tag {};

// [first, last]
template<typename _Random_Access_Iter, typename _Comp,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Difference
             = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool>
binarySearchImpl(_Random_Access_Iter first,
                 _Random_Access_Iter last,
                 _Tp const &find,
                 _Comp comp,
                 std::random_access_iterator_tag,
                 recursive_binary_search_tag)
{
     // verifying the base condition in order to proceed with the binary search               
    if (first <= last)
    {
             // calculating the middle most term
        _Random_Access_Iter mid = first + (last - first) / 2;
         // checking whether the term to be searched lies in the first half or second half of the series    

        if (comp(*mid, find))
            return binarySearchImpl(mid + 1,
                                    last,
                                    find,
                                    comp,
                                    std::random_access_iterator_tag(),
                                    recursive_binary_search_tag());
        else if (comp(find, *mid))
            return binarySearchImpl(first,
                                    mid - 1,
                                    find,
                                    comp,
                                    std::random_access_iterator_tag(),
                                    iterative_binary_search_tag());
        else
            return std::make_pair(mid, true);
    }

    return std::make_pair(last, false);
}

// [first, last]
template<typename _Random_Access_Iter, typename _Comp,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Difference
             = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool>
binarySearchImpl(_Random_Access_Iter first,
                 _Random_Access_Iter last,
                 _Tp const &find,
                 _Comp comp,
                 std::random_access_iterator_tag,
                 iterative_binary_search_tag)
{
    while (first <= last)
    {
        _Random_Access_Iter mid = first + (last - first) / 2;

        if (comp(*mid, find))
            first = mid + 1;
        else if (comp(find, *mid))
            last = mid - 1;
        else
            return std::make_pair(mid, true);
    }

    return std::make_pair(last, false);
}
} // binary_search_impl

// [begin, end)
template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Comp>
_Random_Access_Iter
binarySearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find, _Comp comp)
{
    if (begin >= end)
        return end;
    auto category = typename std::iterator_traits<_Random_Access_Iter>::iterator_category();
    auto tag = binary_search_impl::recursive_binary_search_tag();
    auto res = binary_search_impl::binarySearchImpl(begin, end - 1, find, comp, category, tag);
    if (res.second)
        return res.first;
    else
        return end;
}

// [begin, end)
template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
_Random_Access_Iter
binarySearch(_Random_Access_Iter begin, _Random_Access_Iter end, _Tp const &find)
{
    return binarySearch(begin, end, find, std::less<_Tp>());
}
