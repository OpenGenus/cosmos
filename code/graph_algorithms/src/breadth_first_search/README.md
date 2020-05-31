# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

# Breadth First Search Algorithm (BFS)
In this algorithm, we search for a target node among the neighbouring nodes at a level in the graph before moving to next level.
Thus, it is also called as level order traversal algorithm.

It is similar to the BFS algorithm for a tree. However, it is possible to have cycles in a graph.
Hence, we have to keep track of the visited nodes. We use a boolean visited for this purpose.

## Explanation
```				
          S  ------ level 0
        / | \
       /  |  \
      A   B   C --- level 1
      |   |   |
      |   |   |
      D   E   F --- level 2
       \  |  /
        \ | /
          G  ------ level 3
```
Applying BFS algorithm for above graph will give us following output:
S A B C D E F G

## Complexity
Time complexity: O(V+E)
Each node is enqueued and dequeued at most once. Thus O(V) part is justified.
Finding all the adjacent nodes takes O(E) time.

Space complexity: O(V), worst case we need to store all the nodes in the queue.

V - number of nodes
E - number of edges

Collaborative effort by [OpenGenus](https://github.com/opengenus)
