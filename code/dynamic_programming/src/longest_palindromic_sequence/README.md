# Longest Palindromic Sequence

## Description

Given a string `S`, find the length of the longest subsequence of `S` that is also a palindrome.

Examples:

The length of the longest palindromic sequence of `bbabcbcab` is 7 (`babcbab` or `bacbcab`).

The length of the longest palindromic sequence of `abbaab` is 4 (`abba` or `baab`).

## Solution

We can model the state of our function as being the start and the end of the string.
So let `f(i,j)` be the longest palindromic sequence presented in `S[i:j]`.

Comparing the start and the end of `S`, we have two possibilities:

- **The characters are equal:**
So these characters will make part of the solution and then we
will have to find the longest palindrome in `S[i+1:j-1]`. So,
the result is `f(i+1, j-1)` added by 1 or 2, depending if `i == j`.
- **The characters are different:**
In this case, we will have to discard at least one of them.
If we discard `S[i]`, the result will be `f(i+1, j)`, and
analogously, if we discard `S[j]`, the result will be `f(i, j-1)`.
As we want the longest sequence, we take the maximum of these
possibilities, resulting in `max( f(i+1, j), f(i, j-1) )`.

Following is a general recursive approach:

```
if (i > j) f(i, j) = 0 // invalid range

if (S[i] == S[j]) f(i, j) = f(i+1, j-1) + (1 if i == j else 2)

else f(i, j) = max( f(i+1, j), f(i, j-1) )
```

Using memoization to store the subproblems, the time complexity of this algorithm is O(n^2), being n the length of `S`.

---

<p align="center">
  A massive collaborative effort by <a href=https://github.com/OpenGenus/cosmos>OpenGenus Foundation</a>
</p>

---
