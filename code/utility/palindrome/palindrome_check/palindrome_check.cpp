#include <iterator>
#include <type_traits>
#include <functional>

namespace palindrome_check{
template<typename _BidirectionalIter,
         typename _EqualTo
             = std::equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>,
         typename _IterLess = std::less<_BidirectionalIter>>
bool
isPalindromeRecursive(_BidirectionalIter begin, _BidirectionalIter end)
{
    if (begin != end)
    {
        --end;
        if (_IterLess()(begin, end))
        {
            if (_EqualTo()(*begin, *end) == false)
                return false;

            return isPalindromeRecursive<_BidirectionalIter, _EqualTo, _IterLess>(++begin, end);
        }
    }

    return true;
}

template<typename _BidirectionalIter,
         typename _EqualTo
             = std::equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>,
         typename _IterLess = std::less<_BidirectionalIter>>
bool
isPalindromeIterative(_BidirectionalIter begin, _BidirectionalIter end)
{
    if (begin != end)
    {
        --end;
        while (_IterLess()(begin, end))
        {
            if (_EqualTo()(*begin++, *end--) == false)
                return false;
        }
    }

    return true;
}

template<typename _BidirectionalIter,
         typename _EqualTo
             = std::equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>,
         typename _IterLess = std::less<_BidirectionalIter>>
inline bool
isPalindrome(_BidirectionalIter begin, _BidirectionalIter end)
{
    // default is iterative
    return isPalindromeIterative<_BidirectionalIter, _EqualTo, _IterLess>(begin, end);
}
}
