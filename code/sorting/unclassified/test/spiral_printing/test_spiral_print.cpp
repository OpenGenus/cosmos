#include "../../src/spiral_print/spiral_print.cpp"
#include <cassert>

int main()
{
    using namespace std;
    vector<vector<int>> vec;

    // empty test
    assert("" == spiralPrint(vec, 0, 0));

    /* row test (even col)
     * 1  2  3  4  5  6
     * 7  8  9 10 11 12
     * 13 14 15 16 17 18
     * 19 20 21 22 23 24
     */
    vec.push_back({1, 2, 3, 4, 5, 6});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2 3 4 5 6");
    vec.push_back({7, 8, 9, 10, 11, 12});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2 3 4 5 6 12 11 10 9 8 7");
    vec.push_back({13, 14, 15, 16, 17, 18});
    assert(spiralPrint(vec, vec.size(),
                       vec[0].size()) == "1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11");
    vec.push_back({19, 20, 21, 22, 23, 24});
    assert(spiralPrint(vec, vec.size(),
                       vec[0].size()) ==
           "1 2 3 4 5 6 12 18 24 23 22 21 20 19 13 7 8 9 10 11 17 16 15 14");

    /* row test (odd col)
     * 1  2  3
     * 4  5  6
     * 7  8  9
     */
    vec.clear();
    vec.push_back({1, 2, 3});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2 3");
    vec.push_back({4, 5, 6});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2 3 6 5 4");
    vec.push_back({7, 8, 9});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2 3 6 9 8 7 4 5");

    /* col test
     * 1
     * 2
     * 3
     */
    vec.clear();
    vec.push_back({1});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1");
    vec.push_back({2});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2");
    vec.push_back({3});
    assert(spiralPrint(vec, vec.size(), vec[0].size()) == "1 2 3");

    return 0;
}
