# Longest Bitonic Sequence

## Description

A bitonic sequence is a sequence of numbers which is first strictly increasing
then after a point strictly decreasing. Find the length of the longest bitonic
sequence in a given array `A`.

## Solution

This problem is a variation of the standard longest increasing subsequence problem.

We can denote `lis(n)` as the lenght of the longest increasing subsequence that ends
at `A[n]`, and `lds(n)` the lenght of the longest decreasing subsequence that starts
at `A[n]`.

That way, the value of `lis(n) + lds(n) - 1` gives us the longest bitonic
sequence in which `A[n]` is the highest value. So being `lbs(n)` the longest bitonic
sequence from `A[0]` to `A[n]`:

```
lbs(n) = max( lis(i) + lds(i) - 1, 0 <= i <= n )
```

The time complexity of above approach will be the same as of the algorithm
to find the longest increasing subsequence, that can be `O(n^2)` or `O(n log n)`.

---

<p align="center">
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
