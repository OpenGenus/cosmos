#include <iterator>
#include <type_traits>
#include <functional>

namespace palindrome_check {
template<typename _InputIter,
         typename _ValueNotEqualTo
             = std::not_equal_to<typename std::iterator_traits<_InputIter>::value_type>,
         typename _IterLess = std::less<_InputIter>>
bool
isPalindromeRecursive(_InputIter begin, _InputIter end)
{
    if (begin != end)
    {
        --end;
        if (_IterLess()(begin, end))
        {
            if (_ValueNotEqualTo()(*begin, *end))
                return false;

            return isPalindromeRecursive<_InputIter, _ValueNotEqualTo, _IterLess>(++begin, end);
        }
    }

    return true;
}

template<typename _InputIter,
         typename _ValueNotEqualTo
             = std::not_equal_to<typename std::iterator_traits<_InputIter>::value_type>,
         typename _IterLess = std::less<_InputIter>>
bool
isPalindromeIterative(_InputIter begin, _InputIter end)
{
    if (begin != end)
    {
        --end;
        while (_IterLess()(begin, end))
            if (_ValueNotEqualTo()(*begin++, *end--))
                return false;
    }

    return true;
}

template<typename _InputIter,
         typename _ValueNotEqualTo
             = std::not_equal_to<typename std::iterator_traits<_InputIter>::value_type>,
         typename _IterLess = std::less<_InputIter>>
inline bool
isPalindrome(_InputIter begin, _InputIter end)
{
    // default is iterative
    return isPalindromeIterative<_InputIter, _ValueNotEqualTo, _IterLess>(begin, end);
}
} // palindrome_check
