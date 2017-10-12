#include <iostream>
#include <vector>
#include <set>

/*
 * Part of Cosmos by OpenGenus Foundation
 */

template<typename _Forward_Iter, typename _Compare>
_Forward_Iter linear_search(const _Forward_Iter& begin
                     , const _Forward_Iter& end
                     , const typename _Forward_Iter::value_type& find
                     , _Compare comp) {
    _Forward_Iter current = begin;

    while (current != end) {
        if (comp(*current, find))
            break;
        ++current;
    }
    
    return current;
}

template<typename _Forward_Iter>
_Forward_Iter linear_search(const _Forward_Iter& begin
                     , const _Forward_Iter& end
                     , const typename _Forward_Iter::value_type& find) {
    return linear_search(begin, end, find, std::equal_to<typename _Forward_Iter::value_type>());
}

template<typename _Value_Type, typename _Compare>
ptrdiff_t linear_search(_Value_Type const * const arr
                        , const size_t& sz
                        , const _Value_Type& find
                        , _Compare comp) {
    size_t current{};
    
    while (current != sz) {
        if (comp(*(arr + current), find))
            break;
        ++current;
    }
    
    return current == sz ? -1 : current;
}

template<typename _Value_Type>
ptrdiff_t linear_search(_Value_Type const * const arr
                        , const size_t& sz
                        , const _Value_Type& find) {
    return linear_search(arr, sz, find, std::equal_to<_Value_Type>());
}

template<typename _Ty>
void my_assert(std::string message
               , _Ty a
               , _Ty b) {
    if (a != b)
        std::cout << message << std::endl;
}

template <class _Tp>
struct special_equal_to : std::binary_function<_Tp, _Tp, bool>
{
    bool operator()(const std::pair<_Tp, _Tp>& __x
                    , const std::pair<_Tp, _Tp>& __y) const {
        return __x.first == __y.second && __x.second == __y.first;
    }
};

void test() {
    //plain data structure
    int plain_arr1[0];
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr1, 0, 3)
              , (ptrdiff_t)-1);
    
    int plain_arr2[2];
    for (int i = 0; i < 2; ++i) plain_arr2[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , 1)
              , (ptrdiff_t)1);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr2
                             , sizeof(plain_arr2) / sizeof(plain_arr2[0])
                             , 2)
              , (ptrdiff_t)-1);
    
    int plain_arr3[3];
    for (int i = 0; i < 3; ++i) plain_arr3[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , 2)
              , (ptrdiff_t)2);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr3
                             , sizeof(plain_arr3) / sizeof(plain_arr3[0])
                             , 3)
              , (ptrdiff_t)-1);
    
    int plain_arr4[100];
    for (int i = 0; i < 100; ++i) plain_arr4[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , 99)
              , (ptrdiff_t)99);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr4
                             , sizeof(plain_arr4) / sizeof(plain_arr4[0])
                             , 100)
              , (ptrdiff_t)-1);
    
    int plain_arr5[101];
    for (int i = 0; i < 101; ++i) plain_arr5[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , 0)
              , (ptrdiff_t)0);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , 100)
              , (ptrdiff_t)100);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , -1)
              , (ptrdiff_t)-1);
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr5
                             , sizeof(plain_arr5) / sizeof(plain_arr5[0])
                             , 101)
              , (ptrdiff_t)-1);
    
    int plain_arr6[] = {1, 2, 2};
    my_assert("error line at: " + std::to_string(__LINE__)
              , linear_search(plain_arr6
                       , sizeof(plain_arr6) / sizeof(plain_arr6[0])
                       , 2)
              , (ptrdiff_t)1);
    
    //ADT
    
    std::vector<int> vec_arr1{};
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr1.begin(), vec_arr1.end(), 3)
              , vec_arr1.end());
    
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr1.begin(), vec_arr1.end(), 3)
              , vec_arr1.end());
    
    std::vector<int> vec_arr2(2);
    for (int i = 0; i < 2; ++i) vec_arr2[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr2.begin(), vec_arr2.end(), 0)
              , vec_arr2.begin());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr2.begin(), vec_arr2.end(), 1)
              , vec_arr2.begin()+1);
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr2.begin(), vec_arr2.end(), -1)
              , vec_arr2.end());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr2.begin(), vec_arr2.end(), 2)
              , vec_arr2.end());
    
    std::vector<int> vec_arr3(3);
    for (int i = 0; i < 3; ++i) vec_arr3[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr3.begin(), vec_arr3.end(), 0)
              , vec_arr3.begin());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr3.begin(), vec_arr3.end(), 2)
              , vec_arr3.end()-1);
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr3.begin(), vec_arr3.end(), -1)
              , vec_arr3.end());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr3.begin(), vec_arr3.end(), 3)
              , vec_arr3.end());
    
    std::vector<int> vec_arr4(100);
    for (int i = 0; i < 100; ++i) vec_arr4[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr4.begin(), vec_arr4.end(), 0)
              , vec_arr4.begin());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr4.begin(), vec_arr4.end(), 99)
              , vec_arr4.end()-1);
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr4.begin(), vec_arr4.end(), -1)
              , vec_arr4.end());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr4.begin(), vec_arr4.end(), 100)
              , vec_arr4.end());
    
    std::vector<int> vec_arr5(101);
    for (int i = 0; i < 101; ++i) vec_arr5[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr5.begin(), vec_arr5.end(), 0)
              , vec_arr5.begin());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr5.begin(), vec_arr5.end(), 100)
              , vec_arr5.end()-1);
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr5.begin(), vec_arr5.end(), -1)
              , vec_arr5.end());
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr5.begin(), vec_arr5.end(), 101)
              , vec_arr5.end());
    
    std::vector<int> vec_arr6;
    vec_arr6.push_back(1);
    vec_arr6.push_back(2);
    vec_arr6.push_back(2);
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_arr6.begin(), vec_arr6.end(), 2)
              , vec_arr6.begin()+1);
    
    
    std::set<int> set_arr7;
    set_arr7.insert(1);
    set_arr7.insert(2);
    set_arr7.insert(2);
    auto set_it = set_arr7.begin();
    ++set_it;
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(set_arr7.begin(), set_arr7.end(), 2)
              , set_it);
    
    std::vector<std::pair<int, int>> vec_du_arr8;
    
    vec_du_arr8.push_back(std::make_pair(1, 2));
    vec_du_arr8.push_back(std::make_pair(3, 4));
    vec_du_arr8.push_back(std::make_pair(0, 7));
    my_assert("error at line: " + std::to_string(__LINE__)
              , linear_search(vec_du_arr8.begin(), vec_du_arr8.end(), std::make_pair(4, 3), special_equal_to<int>())
              , vec_du_arr8.begin()+1);
}

int main()
{
    test();
    
    return 0;
}