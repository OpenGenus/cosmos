/* Part of Cosmos by OpenGenus Foundation */
#ifndef SUBSET_SUM
#define SUBSET_SUM

#include <iterator>

/*
 *  Check whether is possible to
 *  get value sum from a subset
 *  of the [begin:end)
 */

// complexity: time: O(sum * n), space: O(sum)
template<typename _BidirectionalIter,
         typename _ValueType = typename std::iterator_traits<_BidirectionalIter>::value_type>
bool
isSubsetSum(_BidirectionalIter begin, _BidirectionalIter end, _ValueType sum)
{
    auto sz = std::distance(begin, end);
    bool subset[2][sum + 1];

    for (int i = 0; i <= sz; i++)
    {
        auto x = begin;
        std::advance(x, i - 1);

        for (int j = 0; j <= sum; j++)
        {
            // A subset with sum 0 is always possible
            if (j == 0)
                subset[i % 2][j] = true;
            // If there exists no element
            // no sum is possible
            else if (i == 0)
                subset[i % 2][j] = false;
            else if (*x <= j)
                subset[i % 2][j] = subset[(i + 1) % 2][j - *x] || subset[(i + 1) % 2][j];
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j];
        }
    }

    return subset[sz % 2][sum];
}

/*
 * // complexity: time: O(sum * n), space: O(sum * n)
 * template<typename _BidirectionalIter,
 *       typename _ValueType = typename std::iterator_traits<_BidirectionalIter>::value_type>
 * bool
 * isSubsetSum(_BidirectionalIter begin, _BidirectionalIter end, _ValueType sum)
 * {
 *  auto sz = std::distance(begin, end);
 *  bool subset[sum + 1][sz + 1];
 *
 *  for (int i = 0; i <= sz; ++i)
 *      subset[0][i] = true;
 *
 *  for (int i = 1; i <= sum; ++i)
 *      subset[i][0] = false;
 *
 *  for (int i = 1; i <= sum; ++i)
 *      for (int j = 1; j <= sz; ++j)
 *      {
 *          auto x = begin;
 *          std::advance(x, j - 1);
 *
 *          subset[i][j] = subset[i][j - 1];
 *          if (i >= *x)
 *              subset[i][j] = subset[i][j] || subset[i - *x][j - 1];
 *      }
 *
 *  return subset[sum][sz];
 * }
 */
#endif // SUBSET_SUM
