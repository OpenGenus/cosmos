/* Part of Cosmos by OpenGenus Foundation */
#ifndef SUBSET_SUM
#define SUBSET_SUM

#include <iterator>

/*
 *  Check whether is possible to
 *  get value sum from a subset
 *  of the [begin:end)
 */

template<typename _BidirectionalIter,
         typename _ValueType = typename std::iterator_traits<_BidirectionalIter>::value_type>
bool
isSubsetSum(_BidirectionalIter begin, _BidirectionalIter end, _ValueType sum)
{
    auto sz = std::distance(begin, end);
    bool subset[sum + 1][sz + 1];

    for (int i = 0; i <= sz; ++i)
        subset[0][i] = true;

    for (int i = 1; i <= sum; ++i)
        subset[i][0] = false;

    for (int i = 1; i <= sum; ++i)
        for (int j = 1; j <= sz; ++j)
        {
            auto x = begin;
            std::advance(x, j - 1);

            subset[i][j] = subset[i][j - 1];
            if (i >= *x)
                subset[i][j] = subset[i][j] || subset[i - *x][j - 1];
        }

    return subset[sum][sz];
}

#endif // SUBSET_SUM
