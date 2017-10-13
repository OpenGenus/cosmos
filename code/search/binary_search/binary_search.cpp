#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct binary_search_tag {};
struct recursive_binary_search_tag : public binary_search_tag {};
struct iterative_binary_search_tag : public binary_search_tag {};

template<typename _Container>
ptrdiff_t binarySearch(const _Container& arr
                       , ptrdiff_t l
                       , ptrdiff_t r
                       , const typename _Container::value_type& find
                       , random_access_iterator_tag
                       , recursive_binary_search_tag) {
    if (r >= l)
    {
        ptrdiff_t mid = l + (r - l)/2;
        
        if (arr[mid] == find)
            return mid;
        
        if (arr[mid] > find)
            return binarySearch(arr, l, mid - 1, find
                                , random_access_iterator_tag()
                                , recursive_binary_search_tag());
        else
            return binarySearch(arr, mid + 1, r, find
                                , random_access_iterator_tag()
                                , recursive_binary_search_tag());
    }
    return -1;
}

template<typename _Container>
ptrdiff_t binarySearch(const _Container& arr
                       , ptrdiff_t l
                       , ptrdiff_t r
                       , const typename _Container::value_type& find
                       , random_access_iterator_tag
                       , iterative_binary_search_tag) {
    while (l <= r)
    {
        ptrdiff_t mid = l + (r-l)/2;
        
        if (arr[mid] == find)
            return mid;
        
        if (arr[mid] > find)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

template<typename _Container>
ptrdiff_t binarySearch(const _Container& arr
                       , const typename _Container::value_type& find) {
    if (arr.empty())
        return -1;
    
    typedef recursive_binary_search_tag binary_search_category;
    typedef typename _Container::iterator _Container_Iter;
    typedef typename iterator_traits<_Container_Iter>::iterator_category tag;
    
    return binarySearch(arr, 0, arr.size(), find, tag()
                        , binary_search_category());
}

template<typename _Ty>
ptrdiff_t binarySearch(const _Ty* arr
                       , const size_t& sz
                       , const _Ty& find) {
    if (sz == 0)
        return -1;
    
    return binarySearch(deque<_Ty>{arr, arr + sz}, find);
}

template<typename _Ty>
void my_assert(string message, _Ty a, _Ty b) {
    if (a != b) cout << message << endl;
}

void test() {
    int plain_arr1[0];
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr1, 0, 3)
              , (ptrdiff_t)-1);
    
    int plain_arr2[2];
    for (int i = 0; i < 2; ++i) plain_arr2[i] = i;
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , 1)
              , (ptrdiff_t)1);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , 2)
              , (ptrdiff_t)-1);
    
    int plain_arr3[3];
    for (int i = 0; i < 3; ++i) plain_arr3[i] = i;
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , 2)
              , (ptrdiff_t)2);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , 3)
              , (ptrdiff_t)-1);
    
    int plain_arr4[100];
    for (int i = 0; i < 100; ++i) plain_arr4[i] = i;
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , 99)
              , (ptrdiff_t)99);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , 100)
              , (ptrdiff_t)-1);
    
    int plain_arr5[101];
    for (int i = 0; i < 101; ++i) plain_arr5[i] = i;
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , 100)
              , (ptrdiff_t)100);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("empty plain array error :" + to_string(__LINE__)
              , binarySearch(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , 101)
              , (ptrdiff_t)-1);
}

int main(void)
{
    test();
    
    return 0;
}