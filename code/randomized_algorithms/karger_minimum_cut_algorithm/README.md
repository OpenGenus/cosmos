# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

Collaborative effort by [OpenGenus](https://github.com/opengenus)

Below Karger’s algorithm can be implemented in O(E) = O(V^2) time

```
1)  Initialize contracted graph CG as copy of original graph
2)  While there are more than 2 vertices.
      a) Pick a random edge (u, v) in the contracted graph.
      b) Merge (or contract) u and v into a single vertex (update 
         the contracted graph).
      c) Remove self-loops
3) Return cut represented by two vertices.
```