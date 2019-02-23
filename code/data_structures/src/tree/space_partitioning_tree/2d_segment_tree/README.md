# 2D Segment Tree

## Explaination
Segment Tree is used to answer range queries in an array. The data structure can be extended to 2 dimensions to answer sub-matrix queries in logarithmic time. Some examples of these queries are :
* Maximum/minimum element in sub-matrix.
* Sum of elements in sub-matrix.
* XOR of elements is sub-matrix.

The process to build a 2D segment tree is similar to process of building a 1D segment tree. Only difference is that every node in a 2D segment tree is a 1D segment tree in itself, so it can be called a segment tree of segment trees.

## Complexity
__Space complexity__ : O(4\*M \*N)

Worst case time complexities:
* __Build__ : O(4\*M \*N)
* __Query__ : O(log<sub>2</sub>(M) \* log<sub>2</sub>(N))
Where the matrix is of size `M x N`

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---
