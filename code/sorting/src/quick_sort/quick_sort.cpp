/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * quick sort synopsis
 *
 * namespace quick_sort_impl {
 * struct quick_sort_tag {};
 * struct iterative_quick_sort_tag :quick_sort_tag {};
 * struct recursive_quick_sort_tag :quick_sort_tag {};
 *
 * template<typename _Random_Acccess_Iter, typename _Compare>
 * _Random_Acccess_Iter
 * partition(_Random_Acccess_Iter first, _Random_Acccess_Iter last, _Compare comp);
 *
 * template<typename _Random_Acccess_Iter, typename _Compare>
 * void
 * quickSortImpl(_Random_Acccess_Iter first,
 *               _Random_Acccess_Iter last,
 *               _Compare comp,
 *               std::random_access_iterator_tag,
 *               recursive_quick_sort_tag);
 *
 * template<typename _Random_Acccess_Iter, typename _Compare>
 * void
 * quickSortImpl(_Random_Acccess_Iter first,
 *               _Random_Acccess_Iter last,
 *               _Compare comp,
 *               std::random_access_iterator_tag,
 *               iterative_quick_sort_tag);
 * } // quick_sort_impl
 *
 * template<typename _Random_Acccess_Iter, typename _Compare>
 * void
 * quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp);
 *
 * template<typename _Random_Acccess_Iter>
 * void
 * quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end);
 */

#include <stack>
#include <functional>

namespace quick_sort_impl {
struct quick_sort_tag {};
struct iterative_quick_sort_tag : quick_sort_tag {};
struct recursive_quick_sort_tag : quick_sort_tag {};

template<typename _Random_Acccess_Iter, typename _Compare>
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

template<typename _Random_Acccess_Iter, typename _Compare>
void
quickSortImpl(_Random_Acccess_Iter first,
              _Random_Acccess_Iter last,
              _Compare comp,
              std::random_access_iterator_tag,
              recursive_quick_sort_tag)
{
    if (first < last)
    {
        // first is pivot
        auto mid = quick_sort_impl::partition(first, last, comp);
        quickSortImpl(first,
                      mid - 1,
                      comp,
                      std::random_access_iterator_tag(),
                      recursive_quick_sort_tag());
        quickSortImpl(mid + 1,
                      last,
                      comp,
                      std::random_access_iterator_tag(),
                      recursive_quick_sort_tag());
    }
}

template<typename _Random_Acccess_Iter, typename _Compare>
void
quickSortImpl(_Random_Acccess_Iter first,
              _Random_Acccess_Iter last,
              _Compare comp,
              std::random_access_iterator_tag,
              iterative_quick_sort_tag)
{
    if (first < last)
    {
        std::stack<std::pair<_Random_Acccess_Iter, _Random_Acccess_Iter>> st;
        st.push(std::make_pair(first, last));

        while (!st.empty())
        {
            _Random_Acccess_Iter left, right, i, j;
            left = st.top().first;
            right = st.top().second;
            st.pop();

            // ignore if only one elem
            if (left >= right)
                continue;
            auto mid = quick_sort_impl::partition(left, right, comp);
            st.push(std::make_pair(left, mid - 1));
            st.push(std::make_pair(mid + 1, right));
        }
    }
}
} // quick_sort_impl

template<typename _Random_Acccess_Iter, typename _Compare>
void
quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp)
{
    using namespace quick_sort_impl;

    if (begin == end)
        return;
    --end;

    auto category = typename std::iterator_traits<_Random_Acccess_Iter>::iterator_category();

    return quickSortImpl(begin, end, comp, category, iterative_quick_sort_tag());
}

template<typename _Random_Acccess_Iter>
void
quickSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end)
{
    using value_type = typename std::iterator_traits<_Random_Acccess_Iter>::value_type;

    return quickSort(begin, end, std::less<value_type>());
}
