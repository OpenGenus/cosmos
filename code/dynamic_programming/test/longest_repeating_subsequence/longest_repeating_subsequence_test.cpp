/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <string>
#include <cassert>
#include "../../src/longest_repeating_subsequence/longest_repeating_subsequence.cpp"

int main()
{
    using namespace std;

    std::string s1 = "aab";
    assert(longestRepeatingSubsequence(s1) == 1);
}
