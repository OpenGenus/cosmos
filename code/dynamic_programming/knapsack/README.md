# 0-1 Knapsack

## Description

Given `n` items, in which the `i`th item has weight `w[i]` and value `v[i]`,
find the maximum total value that can be put in a knapsack of capacity `W`.
You cannot break an item, either pick the complete the item, or don't pick it.

## Solution

This is a dynamic programming algorithm.
We first start by building a table consisting of rows of weights and columns of values.
Starting from the first row and column, we keep on filling the table till the desired value is obtained.

Let the table be represented as M[n,w] where n is the number of objects included
and w is the left over space in the bag.

For every object, there can be two possibilities. 

If the object's weight is greater than the leftover space in the bag, 
then M[n,w] = M[n-1,w]
Else,
The object might be taken or left out.
If it is taken, the total value of the bag becomes,
M[n,w] = Vn + M[n-1,w-wn]           // where Vn is value of the nth object and wn is its weight.

Or if the object is not included,
M[n,w] = M[n-1,w]

The value of M[n,w] is the maximum of both these cases.

---

<p align="center">
    A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
