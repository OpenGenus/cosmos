# Longest Increasing Subsequence

## Description

Given an array of integers `A`, find the length of the longest subsequence such
that all the elements in the subsequence are sorted in increasing order.

Examples:

The lenght of LIS for `{3, 10, 2, 1, 20}` is 3, that is `{3, 10, 20}`.

The lenght of LIS for `{10, 22, 9, 33, 21, 50, 41, 60, 80}` is 6,
that is `{10, 22, 33, 50, 60, 80}`.

## Solution

Let's define a function `f(n)` as the longest increasing subsequence that can be
obtained ending in `A[n]`.

For each `i` such that `i < n`, if `A[i] < A[n]`, we can add
`A[n]` to the longest incresing subsequence that ends in `A[i]`, generating a 
subsequence of size `1 + f(i)`. This gives us the following optimal substructure:

```
f(0) = 1 // base case
f(n) = max(1 + f(i), i < n && A[i] < A[n])
```

Using memoization or tabulation to store the results of the subproblems,
the time complexity of above approach is `O(n^2)`.

---

<p align="center">
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
