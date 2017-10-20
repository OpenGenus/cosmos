# Union Find
Description
---
In computer science, a disjoint-set data structure, also called a union find data structure or merge
find set, is a data structure that keeps track of a set of elements partitioned into a number of disjoint
(non-overlapping) subsets. It provides near-constant-time operations (bounded by the inverse Ackermann function)
to add new sets, to merge existing sets, and to determine whether elements are in the same set.

In addition to many other uses (see the Applications section), disjoint-sets play a key role in
Kruskal's algorithm for finding the minimum spanning tree of a graph.

Union-Find API
---
- union(a, b): Add connection between a and b.
- connected(a, b): Return true if a and b are in the same connected component.
- find(a): Find id or root of a

