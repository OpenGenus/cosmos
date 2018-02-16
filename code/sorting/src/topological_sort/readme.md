# Topological Sort

A topological sort is a simple algorithm that outputs the linear ordering of vertices/nodes of a DAG(Directed Acyclic Graph), where for each directed edge from node A to node B(A :arrow_right: B), node A appears before node B in ordering.

## Condition:
1. The graphs should be **directed**, otherwise for any two vertices a & b, there would be two paths from a to b & vice-versa, & hence they cannot be ordered.

2. The graphs should be **acyclic**, otherwise for any three vertices a,b,c on a cycle, there will not be any starting point, & hence, linear ordering can't be done.

> Note: Via this algorithm, multiple orderings are possible.

For example:

![visualization](http://faculty.simpson.edu/lydia.sinapova/www/cmsc250/LN250_Weiss/L20-TopSortFig01.jpg)

> Image Credits: Simpson College Computer Science Faculty 

Here, V1, V2, V3, V4 and V1, V3, V2, V4 are possible orderings.

## Time Complexity:
The time comlexity of this algorithm is : O(V+E) when we implement it using adjacency list with depth first search.
Where, V: No. of vertices & E: No. of edges.

---
A large scale collaboration of [OpenGenus](https://github.com/opengenus)
