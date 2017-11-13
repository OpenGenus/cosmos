#include <iterator>
#include <type_traits>
#include <functional>

namespace palindrom_check {
    template<typename _InputIter,
             typename _ValueNotEqualTo = std::not_equal_to<typename _InputIter::value_type>,
             typename _IterLess = std::less<_InputIter>>
    bool isPalindromeRecursive(_InputIter begin, _InputIter end)
    {
        --end;
        if (_IterLess()(begin, end)) {
            if (_ValueNotEqualTo()(*begin, *end)) return false;
            return isPalindromeRecursive<_InputIter,
                                         _ValueNotEqualTo,
                                         _IterLess>(++begin, end);
        }
        return true;
    }
    
    template<typename _POD>
    bool isPalindromeRecursive(_POD* begin, _POD* end)
    {
        --end;
        if (begin < end) {
            if (*begin != *end) return false;
            return isPalindromeRecursive<_POD>(++begin, end);
        }
        return true;
    }
    
    template<typename _InputIter,
    typename _ValueNotEqualTo = std::not_equal_to<typename _InputIter::value_type>,
    typename _IterLess = std::less<_InputIter>>
    bool isPalindromeIterative(_InputIter begin, _InputIter end)
    {
        --end;
        while (_IterLess()(begin, end)) {
            if (_ValueNotEqualTo()(*begin++, *end--))
                return false;
        }
        return true;
    }
    
    template<typename _POD>
    bool isPalindromeIterative(_POD* begin, _POD* end)
    {
        --end;
        while (begin < end) {
            if (*begin++ != *end--)
                return false;
        }
        return true;
    }
    
    template<typename _InputIter,
    typename _ValueNotEqualTo = std::not_equal_to<typename _InputIter::value_type>,
    typename _IterLess = std::less<_InputIter>>
    inline bool isPalindrome(_InputIter begin, _InputIter end)
    {
        // default is iterative
        return isPalindromeIterative<_InputIter, _ValueNotEqualTo, _IterLess>(begin, end);
    }
    
    template<typename _POD>
    inline bool isPalindrome(_POD* begin, _POD* end)
    {
        // default is iterative
        return isPalindromeIterative<_POD>(begin, end);
    }
}