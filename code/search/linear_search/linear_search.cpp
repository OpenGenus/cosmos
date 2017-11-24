/*
 Part of Cosmos by OpenGenus Foundation

 linear search synopsis

 warning: in order to follow the convention of STL, the interface is [begin, end) !!!

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
_Input_Iter
linearSearchImpl(_Input_Iter begin,
                 _Input_Iter end,
                 _Tp const &find,
                 _Compare comp,
                 std::input_iterator_tag);

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
_Input_Iter
linearSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find, _Compare comp);

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type>
_Input_Iter
linearSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find);
 */
#include <functional>

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
_Input_Iter
linearSearchImpl(_Input_Iter begin,
                 _Input_Iter end,
                 _Tp const &find,
                 _Compare comp,
                 std::input_iterator_tag)
{
    _Input_Iter current = begin;

    while (current != end)
    {
        if (comp(*current, find))
            break;
        ++current;
    }

    return current;
}

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type, typename _Compare>
_Input_Iter
linearSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find, _Compare comp)
{
    return linearSearchImpl(begin,
                            end,
                            find,
                            comp,
                            typename std::iterator_traits<_Input_Iter>::iterator_category());
}

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type>
_Input_Iter
linearSearch(_Input_Iter begin, _Input_Iter end, _Tp const &find)
{
    return linearSearch(begin, end, find, std::equal_to<_Tp>());
}