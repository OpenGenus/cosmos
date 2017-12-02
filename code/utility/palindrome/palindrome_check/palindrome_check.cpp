#include <iterator>
#include <type_traits>
#include <functional>

namespace palindrome_check{
template<typename _BidirectionalIter, typename _EqualTo>
bool
isPalindromeRecursive(_BidirectionalIter begin, _BidirectionalIter end, _EqualTo equalTo)
{
    if (begin != end)
    {
        --end;
        if (begin != end)
        {
            if (equalTo(*begin, *end) == false)
                return false;

// avoid even length of iters
// _: other elem, b: begin, e: end
//               (++begin)
// even: _ b e _ _  =>  _ e   b _ _     => error: begin >  end
// odd : _ b _ e _  =>  _ b/e _ _ _     => ok, will be detected begin == end
            return isPalindromeRecursive<_BidirectionalIter, _EqualTo>(++begin, end, equalTo);
        }
    }

    return true;
}

template<typename _BidirectionalIter, typename _EqualTo>
bool
isPalindromeIterative(_BidirectionalIter begin, _BidirectionalIter end, _EqualTo equalTo)
{
    if (begin != end)
    {
        --end;
        while (begin != end)
        {
            if (equalTo(*begin, *end) == false)
                return false;

// avoid even length of iters
// _: other elem, b: begin, e: end
//               (++begin)
// even: _ b e _ _  =>  _ e   b _ _     => error: begin >  end
// odd : _ b _ e _  =>  _ b/e _ _ _     => ok, will be detected begin == end
            if (++begin == end--)
                break;
        }
    }

    return true;
}

template<typename _BidirectionalIter>
inline bool
isPalindrome(_BidirectionalIter begin, _BidirectionalIter end)
{
    // default is iterative
    using EqualTo = std::equal_to<typename std::iterator_traits<_BidirectionalIter>::value_type>;

    return isPalindromeIterative<_BidirectionalIter>(begin, end, EqualTo());
}
}
