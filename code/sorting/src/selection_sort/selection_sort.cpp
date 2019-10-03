/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * selection sort synopsis
 *
 * template<typename _Input_Iter, typename _Compare>
 * void
 * selectionSort(_Input_Iter begin, _Input_Iter end, _Compare compare);
 *
 * template<typename _Input_Iter>
 * void
 * selectionSort(_Input_Iter begin, _Input_Iter end);
 */

#include <functional>

template<typename _Input_Iter, typename _Compare>
void
selectionSort(_Input_Iter begin, _Input_Iter end, _Compare compare)
{
    if (begin != end)
        for (auto curr = begin; curr != end; ++curr)
        {
            auto minimum = curr;
            auto forward = curr;
            while (++forward != end)
                if (compare(*forward, *minimum))
                    minimum = forward;

            std::iter_swap(minimum, curr);
        }
}

template<typename _Input_Iter>
void
selectionSort(_Input_Iter begin, _Input_Iter end)
{
    using value_type = typename std::iterator_traits<_Input_Iter>::value_type;

    selectionSort(begin, end, std::less<value_type>());
}
