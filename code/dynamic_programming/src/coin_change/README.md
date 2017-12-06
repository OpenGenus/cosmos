# Coin Change

## Description

Given a set of coins `S` with values `{ S1, S2, ..., Sm }`,
find the number of ways of making the change to a certain value `N`.
There is an infinite quantity of coins and the order of the coins doesn't matter.

For example:

For `S = {1, 2, 3}` and `N = 4`, the number of possibilities is 4, that are:
`{1,1,1,1}`, `{1,1,2}`, `{2,2}` and `{1,3}`. Note that the sets `{1,2,1}`, `{2,1,1}`
and `{3,1}` don't count to solution as they are permutations of the other ones.

## Solution

For each set of coins, there are two possibilities for each coin:
- The coin is not present in the set.
- At least one coin is present.

So, being `f(S[], i, N)` the number of possibilities of making change to `N`
with coins from `S[0]` to `S[i]`, it can be computed by summing the number
of possibilities of getting `N` without using `S[i]`, that is `f(S[], i-1, N)`,
and the number of possibilities that uses `S[i]`, that is `f(S[], i, N - S[i])`.

So, we can compute `f(S[], i, N)` by doing the following:

```
f(S[], i, 0) = 1 // if N reaches 0, than we found a valid solution

f(S[], i, N) = 0, if i < 0 or N < 0
               f(S[], i-1, N) + f(S[], i, N - S[i]), otherwise
```

Applying memoization to above solution, the time complexity of the algorithm
becomes O(N * m), where m is the number of elements in `S`.

---

<p align="center">
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
