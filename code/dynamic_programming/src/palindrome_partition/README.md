# Palindrome Partitioning

## Description

Given a string `S`, determine the minimum number of cuts necessary to partition `S` in a set of palindromes. 

For example, for string `aaabbba`, minimum cuts needed is `1`, making `aa | abba`.

## Solution

First we need to know for each substring of `S`, whether it is a palindrome or not.
Let' denote by `isPalindrome(i, j)` if `S[i:j]` is palindrome.
This can be computed in `O(n^2)` by the following optimal substructure:

```
isPalindrome(i, j) = false, if i > j or S[i] != S[j]
                     true, if j - i <= 1 && S[i] == S[j]
                     isPalindrome(i+1, j-1), otherwise
```

Now let's denote by `minPartition(n)` the minimum number of partitions needed
to partition `S[0:n]` in a set of palindromes.

For each `i` such that `S[i+1:n]` is palindrome, we can partition at position `i`,
and the result for `minPartition(n)` would be `1 + minPartition(i)`. Based on this:

```
minPartition(n) = min( 1 + minPartition(i), 0 <= i < n && isPalindrome(i+1, n) )
```

## Complexity

The time complexity of `isPalindrome` is `O(n^2)`, as there are `n^2` stated that are
computed in `O(1)`. The time complexity of `minPartition` is also `O(n^2)`, as there
are `n` states that are computes in `O(n)`.

Therefore, the overall time complexity of such approach is `O(n^2)`.

---
<p align="center">
  A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
