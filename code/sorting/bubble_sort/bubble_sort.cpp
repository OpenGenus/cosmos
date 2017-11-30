/*
 Part of Cosmos by OpenGenus Foundation

 bubble sort synopsis

template<typename _Bidirectional_Iter,
         typename _Tp = typename std::iterator_traits<_Bidirectional_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void
bubbleSort(_Bidirectional_Iter begin, _Bidirectional_Iter end, _Compare compare);

template<typename _Bidirectional_Iter,
         typename _Tp = typename std::iterator_traits<_Bidirectional_Iter>::value_type>
void
bubbleSort(_Bidirectional_Iter begin, _Bidirectional_Iter end);
 */

#include <functional>

template<typename _Bidirectional_Iter,
         typename _Tp = typename std::iterator_traits<_Bidirectional_Iter>::value_type,
         typename _Compare = std::less<_Tp>>
void
bubbleSort(_Bidirectional_Iter begin, _Bidirectional_Iter end, _Compare compare)
{
    if (begin != end)
    {
        auto frontOfSorted = end;

        for (--frontOfSorted; frontOfSorted != begin; --frontOfSorted)
        {
            bool swapped{};
            for (auto j = begin; j != frontOfSorted; ++j)
            {
                auto nextOfJ = j;
                if (compare(*++nextOfJ, *j))
                {
                    std::iter_swap(nextOfJ, j);
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
    }
}

template<typename _Bidirectional_Iter,
         typename _Tp = typename std::iterator_traits<_Bidirectional_Iter>::value_type>
void
bubbleSort(_Bidirectional_Iter begin, _Bidirectional_Iter end)
{
    bubbleSort(begin, end, std::less<_Tp>());
}
