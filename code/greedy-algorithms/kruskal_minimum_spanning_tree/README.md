# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

Collaborative effort by [OpenGenus](https://github.com/opengenus)

Below are the steps for finding MST using Kruskal’s algorithm

```
1. Sort all the edges in non-decreasing order of their weight.

2. Pick the smallest edge. Check if it forms a cycle with the spanning tree 
formed so far. If cycle is not formed, include this edge. Else, discard it.  

3. Repeat step#2 until there are (V-1) edges in the spanning tree.
```