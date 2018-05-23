/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * insertion sort synopsis
 *
 * template<typename _Bidirectional_Iter, typename _Compare>
 * void
 * insertionSort(_Bidirectional_Iter begin, _Bidirectional_Iter end, _Compare compare);
 *
 * template<typename _Bidirectional_Iter>
 * void
 * insertionSort(_Bidirectional_Iter begin, _Bidirectional_Iter end);
 */

#include <functional>

template<typename _Bidirectional_Iter, typename _Compare>
void
insertionSort(_Bidirectional_Iter begin, _Bidirectional_Iter end, _Compare compare)
{
    if (begin != end)
    {
        auto backOfBegin = begin;
        --backOfBegin;

        auto curr = begin;
        for (++curr; curr != end; ++curr)
        {
            auto pivot = *curr;
            auto backward = curr;
            auto nextOfBackward = curr;
            while (--backward != backOfBegin && compare(pivot, *backward))
            {
                *nextOfBackward = *backward;
                --nextOfBackward;
            }
            *nextOfBackward = pivot;
        }
    }
}

template<typename _Bidirectional_Iter>
void
insertionSort(_Bidirectional_Iter begin, _Bidirectional_Iter end)
{
    using value_type = typename std::iterator_traits<_Bidirectional_Iter>::value_type;

    insertionSort(begin, end, std::less<value_type>());
}
