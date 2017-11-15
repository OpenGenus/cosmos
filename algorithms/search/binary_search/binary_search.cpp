/*
    Part of Cosmos by OpenGenus Foundation

    binary search synopsis

    warning: in order to follow the convention of STL, the interface is [begin, end) !!!

struct binary_search_tag {};
struct recursive_binary_search_tag :public binary_search_tag {};
struct iterative_binary_search_tag :public binary_search_tag {};

// [first, last]
template<typename _Random_Access_Iter, typename _Comp,
typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
typename _Difference = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool> binary_search_impl(_Random_Access_Iter first,
                                                        _Random_Access_Iter last,
                                                        _Tp const &find,
                                                        _Comp comp,
                                                        std::random_access_iterator_tag,
                                                        recursive_binary_search_tag);

// [first, last]
template<typename _Random_Access_Iter, typename _Comp,
typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
typename _Difference = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool> binary_search_impl(_Random_Access_Iter first,
                                                        _Random_Access_Iter last,
                                                        _Tp const &find,
                                                        _Comp comp,
                                                        std::random_access_iterator_tag,
                                                        iterative_binary_search_tag);

// [begin, end)
template<typename _Random_Access_Iter,
typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
typename iterator_category = typename std::iterator_traits<_Random_Access_Iter>::iterator_category,
typename _Comp>
_Random_Access_Iter binary_search(_Random_Access_Iter begin,
                                   _Random_Access_Iter end,
                                   _Tp const &find,
                                   _Comp comp);

// [begin, end)
template<typename _Random_Access_Iter,
typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
_Random_Access_Iter binary_search(_Random_Access_Iter begin,
                                   _Random_Access_Iter end,
                                   _Tp const &find);
*/

#include <functional>

struct binary_search_tag {};
struct recursive_binary_search_tag :public binary_search_tag {};
struct iterative_binary_search_tag :public binary_search_tag {};

// [first, last]
template<typename _Random_Access_Iter, typename _Comp,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Difference = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool> binary_search_impl(_Random_Access_Iter first,
                                                        _Random_Access_Iter last,
                                                        _Tp const &find,
                                                        _Comp comp,
                                                        std::random_access_iterator_tag,
                                                        recursive_binary_search_tag) {
    if (first <= last) {
        _Random_Access_Iter mid = first + (last - first) / 2;

        if (comp(*mid, find)) {
            return binary_search_impl(mid + 1,
                                      last,
                                      find,
                                      comp,
                                      std::random_access_iterator_tag(),
                                      recursive_binary_search_tag());
        } else if (comp(find, *mid)) {
            return binary_search_impl(first,
                                      mid - 1,
                                      find,
                                      comp,
                                      std::random_access_iterator_tag(),
                                      iterative_binary_search_tag());
        } else {
            return std::make_pair(mid, true);
        }
    }

    return std::make_pair(last, false);
}

// [first, last]
template<typename _Random_Access_Iter, typename _Comp,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename _Difference = typename std::iterator_traits<_Random_Access_Iter>::difference_type>
std::pair<_Random_Access_Iter, bool> binary_search_impl(_Random_Access_Iter first,
                                                        _Random_Access_Iter last,
                                                        _Tp const &find,
                                                        _Comp comp,
                                                        std::random_access_iterator_tag,
                                                        iterative_binary_search_tag) {
    while (first <= last) {
        _Random_Access_Iter mid = first + (last - first) / 2;

        if (comp(*mid, find)) {
            first = mid + 1;
        } else if (comp(find, *mid)) {
            last = mid - 1;
        } else {
            return std::make_pair(mid, true);
        }
    }

    return std::make_pair(last, false);
}

// [begin, end)
template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type,
         typename iterator_category = typename std::iterator_traits<_Random_Access_Iter>::iterator_category,
         typename _Comp>
_Random_Access_Iter binary_search(_Random_Access_Iter begin,
                                   _Random_Access_Iter end,
                                   _Tp const &find,
                                   _Comp comp) {
    if (begin >= end)
        return end;
    std::pair<_Random_Access_Iter, bool> res = binary_search_impl(begin,
                                                                  end - 1,
                                                                  find,
                                                                  comp,
                                                                  iterator_category(),
                                                                  recursive_binary_search_tag());
    if (res.second) {
        return res.first;
    } else {
        return end;
    }
}

// [begin, end)
template<typename _Random_Access_Iter,
         typename _Tp = typename std::iterator_traits<_Random_Access_Iter>::value_type>
_Random_Access_Iter binary_search(_Random_Access_Iter begin,
                                   _Random_Access_Iter end,
                                   _Tp const &find) {
    return binary_search(begin, end, find, std::less<_Tp>());
}

/*
// for test
#include <iostream>
#include <vector>
#include <set>
template<typename _Ty>
void my_assert(std::string message, _Ty a, _Ty b) {
    if (a != b)
        std::cout << message << std::endl;
}

template<class _Tp>
struct special_less :std::binary_function<_Tp, _Tp, bool> {
    bool operator()(std::pair<_Tp, _Tp> const &__x, std::pair<_Tp, _Tp> const &__y) const {
        return __x.first < __y.first && __x.second < __y.second;
    }
};

void test() {
    // plain data structure
    int plain_arr1[0];
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr1, plain_arr1, 3),
              plain_arr1);

    int plain_arr2[2];
    for (int i = 0; i < 2; ++i)
        plain_arr2[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr2, plain_arr2 + 2, 0),
              plain_arr2);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr2, plain_arr2 + 2, 1),
              plain_arr2 + 1);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr2, plain_arr2 + 2, -1),
              plain_arr2 + 2);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr2, plain_arr2 + 2, 2),
              plain_arr2 + 2);

    int plain_arr3[3];
    for (int i = 0; i < 3; ++i)
        plain_arr3[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr3, plain_arr3 + 3, 0),
              plain_arr3);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr3, plain_arr3 + 3, 2),
              plain_arr3 + 2);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr3, plain_arr3 + 3, -1),
              plain_arr3 + 3);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr3, plain_arr3 + 3, 3),
              plain_arr3 + 3);

    int plain_arr4[100];
    for (int i = 0; i < 100; ++i)
        plain_arr4[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr4, plain_arr4 + 100, 0),
              plain_arr4);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr4, plain_arr4 + 100, 99),
              plain_arr4 + 99);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr4, plain_arr4 + 100, -1),
              plain_arr4 + 100);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr4, plain_arr4 + 100, 100),
              plain_arr4 + 100);

    int plain_arr5[101];
    for (int i = 0; i < 101; ++i)
        plain_arr5[i] = i;
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr5, plain_arr5 + 101, 0),
              plain_arr5);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr5, plain_arr5 + 101, 100),
              plain_arr5 + 100);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr5, plain_arr5 + 101, -1),
              plain_arr5 + 101);
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr5, plain_arr5 + 101, 101),
              plain_arr5 + 101);

    int plain_arr6[] = {1, 2, 2};
    my_assert("error line at: " + std::to_string(__LINE__),
              binary_search(plain_arr6, plain_arr6 + 3, 2),
              plain_arr6 + 1);

    // ADT

    std::vector<int> vec_arr1{};
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr1.begin(), vec_arr1.end(), 3),
              vec_arr1.end());

    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr1.begin(), vec_arr1.end(), 3),
              vec_arr1.end());

    std::vector<int> vec_arr2(2);
    for (int i = 0; i < 2; ++i)
        vec_arr2[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr2.begin(), vec_arr2.end(), 0),
              vec_arr2.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr2.begin(), vec_arr2.end(), 1),
              vec_arr2.begin() + 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr2.begin(), vec_arr2.end(), -1),
              vec_arr2.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr2.begin(), vec_arr2.end(), 2),
              vec_arr2.end());

    std::vector<int> vec_arr3(3);
    for (int i = 0; i < 3; ++i)
        vec_arr3[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr3.begin(), vec_arr3.end(), 0),
              vec_arr3.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr3.begin(), vec_arr3.end(), 2),
              vec_arr3.end() - 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr3.begin(), vec_arr3.end(), -1),
              vec_arr3.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr3.begin(), vec_arr3.end(), 3),
              vec_arr3.end());

    std::vector<int> vec_arr4(100);
    for (int i = 0; i < 100; ++i)
        vec_arr4[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr4.begin(), vec_arr4.end(), 0),
              vec_arr4.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr4.begin(), vec_arr4.end(), 99),
              vec_arr4.end() - 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr4.begin(), vec_arr4.end(), -1),
              vec_arr4.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr4.begin(), vec_arr4.end(), 100),
              vec_arr4.end());

    std::vector<int> vec_arr5(101);
    for (int i = 0; i < 101; ++i)
        vec_arr5[i] = i;
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr5.begin(), vec_arr5.end(), 0),
              vec_arr5.begin());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr5.begin(), vec_arr5.end(), 100),
              vec_arr5.end() - 1);
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr5.begin(), vec_arr5.end(), -1),
              vec_arr5.end());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr5.begin(), vec_arr5.end(), 101),
              vec_arr5.end());

    std::vector<int> vec_arr6;
    vec_arr6.push_back(1);
    vec_arr6.push_back(2);
    vec_arr6.push_back(2);
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_arr6.begin(), vec_arr6.end(), 2),
              vec_arr6.begin() + 1);

    std::vector<std::pair<int, int> > vec_du_arr8;
    vec_du_arr8.push_back(std::make_pair(1, 2));
    vec_du_arr8.push_back(std::make_pair(3, 4));
    vec_du_arr8.push_back(std::make_pair(0, 7));
    std::sort(vec_du_arr8.begin(), vec_du_arr8.end(), special_less<int>());
    my_assert("error at line: " + std::to_string(__LINE__),
              binary_search(vec_du_arr8.begin(),
                             vec_du_arr8.end(),
                             std::make_pair(4, 3),
                             special_less<int>()),
              vec_du_arr8.begin() + 1);
}

int main(void)
{
    test();

    return 0;
}

// */
