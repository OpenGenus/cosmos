# 2D Fenwick Tree

## Explaination
**2D Fenwick tree** is used to answer sub-matrix queries, i.e. range-queries in 2 dimensions.Like 1D Fenwick tree, 2D Fenwick tree also requires the **operation to be invertible**. Compared to segment tree data structure, Fenwick tree uses less space and is simpler to implement.

One disadvantage of Fenwick tree is that it can be only used with an operation that is invertible. For example, addition is invertible so range sum queries can be processed, but max() is a non-invertible operation so range max queries can't be processed.

## Algorithm
LeastSignificantBit operation is critical for working of Fenwick tree and is hidden within implementation details:
```
function LSB(i):
        return i & (-i)
```
A Fenwick tree preforms two functions:
* query(b) -- Queries for the range `[1, b]`. query(b) - query(a - 1) queries for range `[a, b]`.
```
function query(x, y):
    sum = 0
    while x > 0:
        # cannot directly use y since y becomes 0 after single loop
        y' = y
        while y > 0:
            # Process appropriately
            sum = sum + ft[x][y]
            y' = y' + LSB(y')
        x = x + LSB(x)
    return sum
```
* update(pos, value) -- Updates index `pos` with `value`.
```
function update(x, y, value):
    while x <= m:
        # cannot directly use y since y becomes 0 after single loop
        y' = y
        while y' <= n:
            ft[x][y'] = ft[x][y'] + val
            y' = y' + LSB(y')
        x = x + LSB(x)
```

## Complexity
__Space complexity__ : O(MN)

Worst case time complexities:
* __Update__ : O(log<sub>2</sub>(MN))
* __Query__ : O(log<sub>2</sub>(MN))
Where the matrix is of size `M x N`

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---
