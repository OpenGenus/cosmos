#include <iterator>
#include <type_traits>
#include <functional>

namespace palindrome_check{
template<typename _BidirectionalIter,
         typename _ValueNotEqualTo
             = std::not_equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>,
         typename _IterLess = std::less<_BidirectionalIter>>
bool
isPalindromeRecursive(_BidirectionalIter begin, _BidirectionalIter end)
{
    if (begin != end)
    {
        --end;
        if (_IterLess()(begin, end))
        {
            if (_ValueNotEqualTo()(*begin, *end))
                return false;

            return isPalindromeRecursive<_BidirectionalIter, _ValueNotEqualTo, _IterLess>(++begin, end);
        }
    }

    return true;
}

template<typename _BidirectionalIter,
         typename _ValueNotEqualTo
             = std::not_equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>,
         typename _IterLess = std::less<_BidirectionalIter>>
bool
isPalindromeIterative(_BidirectionalIter begin, _BidirectionalIter end)
{
    if (begin != end)
    {
        --end;
        while (_IterLess()(begin, end))
        {
            if (_ValueNotEqualTo()(*begin++, *end--))
                return false;
        }
    }

    return true;
}

template<typename _BidirectionalIter,
         typename _ValueNotEqualTo
             = std::not_equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>,
         typename _IterLess = std::less<_BidirectionalIter>>
inline bool
isPalindrome(_BidirectionalIter begin, _BidirectionalIter end)
{
    // default is iterative
    return isPalindromeIterative<_BidirectionalIter, _ValueNotEqualTo, _IterLess>(begin, end);
}
}
