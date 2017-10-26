/*
 Part of Cosmos by OpenGenus Foundation

 linear search synopsis

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type,
         typename _Compare>
_Input_Iter _linear_search(_Input_Iter begin,
                           _Input_Iter end,
                           _Tp const &find,
                           _Compare comp,
                           std::input_iterator_tag);

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type,
         typename _Compare>
_Input_Iter linear_search(_Input_Iter begin, _Input_Iter end, _Tp const &find, _Compare comp);

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type>
_Input_Iter linear_search(_Input_Iter begin, _Input_Iter end, _Tp const &find);
 */

#include <functional>

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type,
         typename _Compare>
_Input_Iter _linear_search(_Input_Iter begin,
                           _Input_Iter end,
                           _Tp const &find,
                           _Compare comp,
                           std::input_iterator_tag) {
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
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type,
         typename _Compare>
_Input_Iter linear_search(_Input_Iter begin, _Input_Iter end, _Tp const &find, _Compare comp) {
    return _linear_search(begin,
                          end,
                          find,
                          comp,
                          typename std::iterator_traits<_Input_Iter>::iterator_category());
}

template<typename _Input_Iter,
         typename _Tp = typename std::iterator_traits<_Input_Iter>::value_type>
_Input_Iter linear_search(_Input_Iter begin, _Input_Iter end, _Tp const &find) {
    return linear_search(begin, end, find, std::equal_to<_Tp>());
}

/*
// for test
#include <iostream>
#include <vector>
#include <list>
#include <set>
template<typename _Ty>
void my_assert(std::string message, _Ty a, _Ty b) {
    if (a != b)
        std::cout << message << std::endl;
}

template<class _Tp>
struct special_equal_to :std::binary_function<_Tp, _Tp, bool> {
    bool operator()(std::pair<_Tp, _Tp> const &__x, std::pair<_Tp, _Tp> const &__y) const {
        return __x.first == __y.second && __x.second == __y.first;
    }
};

void test() {
    // plain data structure
    int plain_arr1[0];
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr1, plain_arr1, 3),
              plain_arr1);

    int plain_arr2[2];
    for (int i = 0; i < 2; ++i)
        plain_arr2[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr2, plain_arr2 + 2, 0),
              plain_arr2);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr2, plain_arr2 + 2, 1),
              plain_arr2 + 1);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr2, plain_arr2 + 2, -1),
              plain_arr2 + 2);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr2, plain_arr2 + 2, 2),
              plain_arr2 + 2);

    int plain_arr3[3];
    for (int i = 0; i < 3; ++i)
        plain_arr3[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr3, plain_arr3 + 3, 0),
              plain_arr3);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr3, plain_arr3 + 3, 2),
              plain_arr3 + 2);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr3, plain_arr3 + 3, -1),
              plain_arr3 + 3);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr3, plain_arr3 + 3, 3),
              plain_arr3 + 3);

    int plain_arr4[100];
    for (int i = 0; i < 100; ++i)
        plain_arr4[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr4, plain_arr4 + 100, 0),
              plain_arr4);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr4, plain_arr4 + 100, 99),
              plain_arr4 + 99);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr4, plain_arr4 + 100, -1),
              plain_arr4 + 100);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr4, plain_arr4 + 100, 100),
              plain_arr4 + 100);

    int plain_arr5[101];
    for (int i = 0; i < 101; ++i)
        plain_arr5[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr5, plain_arr5 + 101, 0),
              plain_arr5);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr5, plain_arr5 + 101, 100),
              plain_arr5 + 100);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr5, plain_arr5 + 101, -1),
              plain_arr5 + 101);
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr5, plain_arr5 + 101, 101),
              plain_arr5 + 101);

    int plain_arr6[] = {1, 2, 2};
    my_assert("error line at: " + std::to_string(__LINE__),
              linear_search(plain_arr6, plain_arr6 + 3, 2),
              plain_arr6 + 1);

    // ADT

    std::vector<int> vec_arr1{};
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr1.begin(), vec_arr1.end(), 3),
              vec_arr1.end());

    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr1.begin(), vec_arr1.end(), 3),
              vec_arr1.end());

    std::vector<int> vec_arr2(2);
    for (int i = 0; i < 2; ++i)
        vec_arr2[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr2.begin(), vec_arr2.end(), 0),
              vec_arr2.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr2.begin(), vec_arr2.end(), 1),
              vec_arr2.begin() + 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr2.begin(), vec_arr2.end(), -1),
              vec_arr2.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr2.begin(), vec_arr2.end(), 2),
              vec_arr2.end());

    std::vector<int> vec_arr3(3);
    for (int i = 0; i < 3; ++i)
        vec_arr3[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr3.begin(), vec_arr3.end(), 0),
              vec_arr3.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr3.begin(), vec_arr3.end(), 2),
              vec_arr3.end() - 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr3.begin(), vec_arr3.end(), -1),
              vec_arr3.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr3.begin(), vec_arr3.end(), 3),
              vec_arr3.end());

    std::vector<int> vec_arr4(100);
    for (int i = 0; i < 100; ++i)
        vec_arr4[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr4.begin(), vec_arr4.end(), 0),
              vec_arr4.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr4.begin(), vec_arr4.end(), 99),
              vec_arr4.end() - 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr4.begin(), vec_arr4.end(), -1),
              vec_arr4.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr4.begin(), vec_arr4.end(), 100),
              vec_arr4.end());

    std::vector<int> vec_arr5(101);
    for (int i = 0; i < 101; ++i)
        vec_arr5[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr5.begin(), vec_arr5.end(), 0),
              vec_arr5.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr5.begin(), vec_arr5.end(), 100),
              vec_arr5.end() - 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr5.begin(), vec_arr5.end(), -1),
              vec_arr5.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr5.begin(), vec_arr5.end(), 101),
              vec_arr5.end());

    std::list<int> vec_arr6;
    vec_arr6.push_back(1);
    vec_arr6.push_back(2);
    vec_arr6.push_back(2);
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_arr6.begin(), vec_arr6.end(), 2),
              ++vec_arr6.begin());

    std::set<int> set_arr7;
    set_arr7.insert(1);
    set_arr7.insert(2);
    set_arr7.insert(2);
    auto set_it = set_arr7.begin();
    ++set_it;
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(set_arr7.begin(), set_arr7.end(), 2),
              set_it);

    std::vector<std::pair<int, int> > vec_du_arr8;

    vec_du_arr8.push_back(std::make_pair(1, 2));
    vec_du_arr8.push_back(std::make_pair(3, 4));
    vec_du_arr8.push_back(std::make_pair(0, 7));
    my_assert("error at line: " + std::to_string(__LINE__),
              linear_search(vec_du_arr8.begin(),
                            vec_du_arr8.end(),
                            std::make_pair(4, 3),
                            special_equal_to<int>()),
              vec_du_arr8.begin() + 1);
}

int main()
{
    test();

    return 0;
}
// */
