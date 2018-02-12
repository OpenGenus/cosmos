## Breadth First Search

Breadth first search algorithm is used for traversing from a selected node and it traverses the graph layerwise and explores the neighbor nodes first before moving to next level of neighbors.

### Pseudocode
```c
BFS(G,s) //Here G is graph and s is sourcenode.
   Let q be queue
       q.enqueue(s)
   mark source node (s) as visited
   while(q is not empty)
       u = q.dequeue
       for all neighbors of v of u in graph G,
               if v is not visited 
                     q.enqueue(v)
                     mark v as visited
```
### This repository currently contains BFS in following language.
* [C](https://github.com/RN0311/cosmos/blob/master/code/graph_algorithms/src/breadth_first_search/bfs.c)
* [C++](https://github.com/RN0311/cosmos/blob/master/code/graph_algorithms/src/breadth_first_search/bfs.cpp)
* [Java](https://github.com/RN0311/cosmos/blob/master/code/graph_algorithms/src/breadth_first_search/Bfs.java)
* [Python](https://github.com/RN0311/cosmos/blob/master/code/graph_algorithms/src/breadth_first_search/breadth_first_search.py)
* [Ruby](https://github.com/RN0311/cosmos/blob/master/code/graph_algorithms/src/breadth_first_search/bfs.rb)
* [Swift](https://github.com/RN0311/cosmos/blob/master/code/graph_algorithms/src/breadth_first_search/breadth_first_search.swift)

Collaborative effort by [OpenGenus](https://github.com/opengenus)
