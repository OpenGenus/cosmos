#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include "../../../src/palindrome/palindrome_check/palindrome_check.cpp"
using namespace std;
using namespace palindrome_check;

// for test
struct MapValueEqual
{
    bool operator()(std::pair<int, int> const &a, std::pair<int, int> const &b) const
    {
        return a.second != b.second;
    }
};

template<typename _Type>
struct GreaterEqual
{
    bool operator()(typename _Type::iterator a, typename _Type::iterator b) const
    {
        return (*a).first < (*b).first;
    }
};

void
testTrueRecursive()
{
    string sz = "";
    assert(isPalindromeRecursive(sz.begin(), sz.end()));

    string s = "1221";
    assert(isPalindromeRecursive(s.begin(), s.end()));
    string s2 = "12321";
    assert(isPalindromeRecursive(s2.begin(), s2.end()));

    vector<int> v = {1, 2, 2, 1};
    assert(isPalindromeRecursive(v.begin(), v.end()));
    vector<int> v2 = {1, 2, 3, 2, 1};
    assert(isPalindromeRecursive(v2.begin(), v2.end()));

    int *ivz = nullptr;
    assert(isPalindromeRecursive(ivz, ivz));

    int *iv = new int(4);
    *iv = 1;
    *(iv + 1) = 2;
    *(iv + 2) = 2;
    *(iv + 3) = 1;
    assert(isPalindromeRecursive(iv, iv + 4));
    int *iv2 = new int(5);
    *iv2 = 1;
    *(iv2 + 1) = 2;
    *(iv2 + 2) = 3;
    *(iv2 + 3) = 2;
    *(iv2 + 4) = 1;
    assert(isPalindromeRecursive(iv2, iv2 + 5));

    int ivaz[0];
    assert(isPalindromeRecursive(ivaz, ivaz));

    int iva[4] = {1, 2, 2, 1};
    assert(isPalindromeRecursive(iva, iva + 4));
    int iva2[5] = {1, 2, 3, 2, 1};
    assert(isPalindromeRecursive(iva2, iva2 + 5));

    map<int, int> se;
    se[1] = 1; se[2] = 2; se[4] = 2; se[5] = 1;
    assert((isPalindromeRecursive<map<int, int>::iterator,
                                  MapValueEqual,
                                  GreaterEqual<map<int, int>>>(se.begin(), se.end())));
    se[3] = 3;
    assert((isPalindromeRecursive<map<int, int>::iterator,
                                  MapValueEqual,
                                  GreaterEqual<map<int, int>>>(se.begin(), se.end())));
}

void
testFalseRecursive()
{
    string s = "1231";
    assert(!isPalindromeRecursive(s.begin(), s.end()));
    string s2 = "12331";
    assert(!isPalindromeRecursive(s2.begin(), s2.end()));

    vector<int> v = {1, 2, 3, 1};
    assert(!isPalindromeRecursive(v.begin(), v.end()));
    vector<int> v2 = {1, 2, 3, 3, 1};
    assert(!isPalindromeRecursive(v2.begin(), v2.end()));

    int *iv = new int(4);
    *iv = 1;
    *(iv + 1) = 2;
    *(iv + 2) = 3;
    *(iv + 3) = 1;
    assert(!isPalindromeRecursive(iv, iv + 4));
    int *iv2 = new int(5);
    *iv2 = 1;
    *(iv2 + 1) = 2;
    *(iv2 + 2) = 3;
    *(iv2 + 3) = 3;
    *(iv2 + 4) = 1;
    assert(!isPalindromeRecursive(iv2, iv2 + 5));

    int iva[4] = {1, 2, 3, 1};
    assert(!isPalindromeRecursive(iva, iva + 4));
    int iva2[5] = {1, 2, 3, 3, 1};
    assert(!isPalindromeRecursive(iva2, iva2 + 5));

    map<int, int> se;
    se[1] = 1; se[2] = 2; se[4] = 3; se[5] = 1;
    assert(!(isPalindromeRecursive<map<int, int>::iterator,
                                   MapValueEqual,
                                   GreaterEqual<map<int, int>>>(se.begin(), se.end())));
    se[3] = 3;
    assert(!(isPalindromeRecursive<map<int, int>::iterator,
                                   MapValueEqual,
                                   GreaterEqual<map<int, int>>>(se.begin(), se.end())));
}

void
testTrueIterative()
{
    string sz = "";
    assert(isPalindrome(sz.begin(), sz.end()));

    string s = "1221";
    assert(isPalindrome(s.begin(), s.end()));
    string s2 = "12321";
    assert(isPalindrome(s2.begin(), s2.end()));

    vector<int> v = {1, 2, 2, 1};
    assert(isPalindrome(v.begin(), v.end()));
    vector<int> v2 = {1, 2, 3, 2, 1};
    assert(isPalindrome(v2.begin(), v2.end()));

    int *ivz = nullptr;
    assert(isPalindrome(ivz, ivz));

    int *iv = new int(4);
    *iv = 1;
    *(iv + 1) = 2;
    *(iv + 2) = 2;
    *(iv + 3) = 1;
    assert(isPalindrome(iv, iv + 4));
    int *iv2 = new int(5);
    *iv2 = 1;
    *(iv2 + 1) = 2;
    *(iv2 + 2) = 3;
    *(iv2 + 3) = 2;
    *(iv2 + 4) = 1;
    assert(isPalindrome(iv2, iv2 + 5));

    int ivaz[0];
    assert(isPalindrome(ivaz, ivaz));

    int iva[4] = {1, 2, 2, 1};
    assert(isPalindrome(iva, iva + 4));
    int iva2[5] = {1, 2, 3, 2, 1};
    assert(isPalindrome(iva2, iva2 + 5));

    map<int, int> se;
    se[1] = 1; se[2] = 2; se[4] = 2; se[5] = 1;
    assert((isPalindrome<map<int, int>::iterator,
                         MapValueEqual,
                         GreaterEqual<map<int, int>>>(se.begin(), se.end())));
    se[3] = 3;
    assert((isPalindrome<map<int, int>::iterator,
                         MapValueEqual,
                         GreaterEqual<map<int, int>>>(se.begin(), se.end())));
}

void
testFalseIterative()
{
    string s = "1231";
    assert(!isPalindrome(s.begin(), s.end()));
    string s2 = "12331";
    assert(!isPalindrome(s2.begin(), s2.end()));

    vector<int> v = {1, 2, 3, 1};
    assert(!isPalindrome(v.begin(), v.end()));
    vector<int> v2 = {1, 2, 3, 3, 1};
    assert(!isPalindrome(v2.begin(), v2.end()));

    int *iv = new int(4);
    *iv = 1;
    *(iv + 1) = 2;
    *(iv + 2) = 3;
    *(iv + 3) = 1;
    assert(!isPalindrome(iv, iv + 4));
    int *iv2 = new int(5);
    *iv2 = 1;
    *(iv2 + 1) = 2;
    *(iv2 + 2) = 3;
    *(iv2 + 3) = 3;
    *(iv2 + 4) = 1;
    assert(!isPalindrome(iv2, iv2 + 5));

    int iva[4] = {1, 2, 3, 1};
    assert(!isPalindrome(iva, iva + 4));
    int iva2[5] = {1, 2, 3, 3, 1};
    assert(!isPalindrome(iva2, iva2 + 5));

    map<int, int> se;
    se[1] = 1; se[2] = 2; se[4] = 3; se[5] = 1;
    assert(!(isPalindrome<map<int, int>::iterator,
                          MapValueEqual,
                          GreaterEqual<map<int, int>>>(se.begin(), se.end())));
    se[3] = 3;
    assert(!(isPalindrome<map<int, int>::iterator,
                          MapValueEqual,
                          GreaterEqual<map<int, int>>>(se.begin(), se.end())));
}

int
main()
{
    testTrueRecursive();
    testFalseRecursive();
    testTrueIterative();
    testFalseIterative();

    return 0;
}
// */
