# Egg Dropping Puzzle

## Description

For a `H`-floor building, we want to know which floors are
safe to drop eggs from without broking them and which floors
aren't. There are a few assumptions:

- An egg that survives a fall can be used again.
- A broken egg must be discarded.
- The effect of a fall is the same for all eggs.
- If an egg breaks when dropped, then it would break if dropped from a higher window.
- If an egg survives a fall, then it would survive a shorter fall.
- It is not ruled out that the first-floor windows break eggs,
nor is it ruled out that eggs can survive the Hth-floor windows.

Having `N` eggs available, what is the **minimum** number of egg drops needed
to find the critical floor in the **worst case**?

## Solution

We can define the state of the dynamic programming model as being a pair `(n, k)`,
where `n` is the number of eggs available and `k` is the number of consecutive floors
that need to be tested.

Let `f(n,k)` be the minimum number of attempts needed to find the critical floor in the
worst case with `n` eggs available and with `k` consecutive floors to be tested.

Attempting to drop an egg for each floor `x` leads to two possibilities:

- The egg breaks from floor `x`: then we lose an egg but have to check only the floors
lower than `x`, reducing the problem to `n-1` eggs and `x-1` floors.
- The egg does not break: then we continue with `n` eggs at our disposal and have to
check only the floors higher than `x`, reducing the problem to `n` eggs and `k-x` floors.

As we want to know the number of trials in the *worst case*, we consider the maximum of the
two possibilities, that is `max( f(n-1, x-1), f(n, k-x) )`.
And as we want to know the *minimum* number of trials, we choose the floor that leads to
the minimum number of attempts. So:
```
f(n, k) = 1 + min( max( f(n-1, x-1), f(n, k-x) ) , 1 <= x <= h )
```

And the base cases are:
```
f(n, 0) = 0  // if there is no floor, no attempt is necessary
f(n, 1) = 1  // if there is only one floor, just one attempt is necessary
f(1, k) = k  // with only one egg, k attempts are necessary
```

By using memoization or tabulation, the complexity of the algorithm becomes `O(n * k^2)`, as the number of states is `n*k` and the cost of computing a state is `O(k)`.

---

<p align=center>
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
