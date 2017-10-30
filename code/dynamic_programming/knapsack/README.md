# 0-1 Knapsack

## Description

Given `n` items, in which the `i`th item has weight `wi` and value `vi`,
find the maximum total value that can be put in a knapsack of capacity `W`.
You cannot break an item, either pick the complete item, or don't pick it.

## Solution

This is a dynamic programming algorithm.
We first start by building a table consisting of rows of weights and columns of values.
Starting from the first row and column, we keep on filling the table till the desired value is obtained.

Let the table be represented as `M[n, w]` where `n` is the number of objects included
and `w` is the left over space in the bag.

For every object, there can be two possibilities: 

- If the object's weight is greater than the leftover space in the bag, 
then `M[n, w]` = `M[n - 1, w]`
- Else,
the object might be taken or left out.
    - If it is taken, the total value of the bag becomes
    `M[n, w]` = `vn` + `M[n - 1, w - wn]`, where `vn` is value of the `n`th object and `wn` is its weight.
    - Or if the object is not included,
    `M[n, w]` = `M[n - 1, w]`
    
The value of `M[n,w]` is the maximum of both these cases.

In short, the optimal substructure to compute `M[n, w]` is:
```
M[n, w] = M[n-1, w], if wn > w
          max( M[n-1, w], vn + M[n-1, w - wn] ), otherwise
```

The complexity of above algorithm is `O(n*W)`, as there are `n*W` states and each state is computed in `O(1)`.

---

<p align="center">
    A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
