/* Part of Cosmos by OpenGenus Foundation */

#ifndef LONGEST_REPEATING_SUBSEQUENCE_TEST
#define LONGEST_REPEATING_SUBSEQUENCE_TEST

#include <iostream>
#include <string>
#include <cassert>
#include "../../src/longest_repeating_subsequence/longest_repeating_subsequence.cpp"

int main()
{
    using namespace std;

    std :: string s1 = "aab";
    assert(longestRepeatingSubsequence(s1) == 1);
}
