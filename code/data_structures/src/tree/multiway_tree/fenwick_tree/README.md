# Fenwick Tree

## Explaination
Fenwick Tree / Binary indexed tree is a data structure used to process interval/range based queries. Compared to segment tree data structure, Fenwick tree uses less space and is simpler to implement.

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
function query(b):
  while b &gt; 0:
      # process appropriately
      ...

      b = b - LSB(b)
  return ...
```
* update(pos, value) -- Updates index `pos` with `value`.
```
function update(pos, value):
    while pos &lt;= n:
        # Update array[pos] and FenwickTree[[pos] appropriately.
        ...
        
        pos = pos + LSB(pos)
```

## Complexity
__Space complexity__ : O(n)

__Time complexity__ :
* __Update__ : O(log<sub>2</sub>(n))
* __Query__ : O(log<sub>2</sub>(n))

Where n is the length of array.

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
