# Square Root Decomposition

__Problem:__ Given an Array `A[0..N-1]` of length `N` and `Q` queries over intervals `[L_i...R_i)`.
Answer all queries. For example, calculate the sum in each intervals `[L_i, R_i)`.

__Runtime Naive:__ `O(Q * N)` to compute `Q` queries of max. length `N` independently.

Square Root Decomposition is a technique to optimize queries over intervals
of an array by factor $$`\Theta(sqrt(n))`$$.


## Mo's Algorithm

A specific algorithm that uses Square Root Decomposition.


__Runtime:__

- Mo's Algorithm: `O((Q + N) * sqrt(N) * F)` where `F` is the time to calculate
  query `[L, R)` from `[L, R-1)` etc.


__See also:__

- [hackerrank](https://www.hackerrank.com/topics/mos-algorithm)
- [hackerearth](https://www.hackerearth.com/practice/notes/mos-algorithm/)
