# Topological Sort

A topological sort is a simple algorithm that outputs the linear ordering of vertices/nodes of a DAG(Directed Acyclic Graph), where for each directed edge from node A to node B(A :arrow_right: B), node A appears before node B in ordering.

## Explanation:
There are two conditions for this algorithm to work:
1. The graphs should be **directed**, otherwise for any two vertices a & b, there would be two paths from a to b & vice-versa, & hence they cannot be ordered.

2. The graphs should be **acyclic**, otherwise for any three vertices a,b,c on a cycle, there will not be any starting point, & hence, linear ordering can't be done.

> Note: Via this algorithm, multiple orderings are possible.

For example:

![visualization](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L20-TopSortFig01.jpg)

> Image Credits: Simpson College Computer Science Faculty 

Here, V1, V2, V3, V4 and V1, V3, V2, V4 are possible orderings.

## Algorithm
```
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edge
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)
```

## Complexity:
**Time complexity**
`O(V+E)` when we implement it using adjacency list with depth first search.
Where, **V**: No. of vertices & **E**: No. of edges.

---
A large scale collaboration of [OpenGenus](https://github.com/opengenus)
