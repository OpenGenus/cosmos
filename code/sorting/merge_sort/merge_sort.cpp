/*
 Part of Cosmos by OpenGenus Foundation

 merge sort synopsis

template<typename _Random_Acccess_Iter>
_Random_Acccess_Iter
advance(_Random_Acccess_Iter it, ptrdiff_t n);

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp);

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end);
 */

#include <vector>
#include <iterator>

namespace merge_sort {
template<typename _Random_Acccess_Iter>
_Random_Acccess_Iter
advance(_Random_Acccess_Iter it, ptrdiff_t n)
{
    std::advance(it, n);

    return it;
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void
mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end, _Compare comp)
{
    using std::distance;
    using std::vector;

    if (begin != end)
    {
        _Random_Acccess_Iter leftMin, leftMax, rightMin, rightMax;
        auto length = distance(begin, end);
        vector<_Tp> tmp(length);

        // bottom-up version
        for (auto i = 1; i < distance(begin, end); i *= 2)
        {
            auto last = end;
            advance(last, -1 * i);
            for (leftMin = begin; leftMin < last; leftMin = rightMax)
            {
                rightMin = leftMax = advance(leftMin, i);
                rightMax = advance(leftMax, i);

                // prevent overflow, if length is now 2^n
                if (rightMax > end)
                    rightMax = end;

                auto next = 0;
                while (leftMin < leftMax && rightMin < rightMax)
                    tmp[next++] = comp(*rightMin, *leftMin) ? *rightMin++ : *leftMin++;
                while (leftMin < leftMax)
                    *--rightMin = *--leftMax;
                while (next > 0)
                    *--rightMin = tmp[--next];
            }
        }
    }
}

template<typename _Random_Acccess_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Acccess_Iter>::value_type>
void
mergeSort(_Random_Acccess_Iter begin, _Random_Acccess_Iter end)
{
    mergeSort(begin, end, std::less<_Tp>());
}
}
