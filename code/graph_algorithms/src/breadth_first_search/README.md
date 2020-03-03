# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

# Breadth First Search Algorithm (BFS)
In this algorithm, we search for a target node among the neighbouring nodes at a level in the graph before moving to next level.
Thus, it is also called as level order traversal algorithm.

It is similar to the BFS algorithm for a tree. However, it is possible to have cycles in a graph.
Hence, we have to keep track of the visited nodes.

## Explanation
![A graph](https://github.com/Priya-Raut/cosmos/tree/master/code/graph_algorithms/src/breadth_first_search/graph_bfs.jpg)

> Image credits: (Tutorialspoint.com)

Applying BFS algorithm for above graph will give us following output:
S A B C D E F G

Take a look at this video for better understanding:
https://www.youtube.com/watch?v=0u78hx-66Xk

Read various articles about BFS algorithm here:
https://www.geeksforgeeks.org/tag/bfs/

## Complexity
Time complexity: O(V+E)
Each node is enqueued and dequeued at most once. Thus O(V) part is justified.
Finding all the adjacent nodes takes O(E) time.

Space complexity: O(V), worst case we need to store all the nodes in the queue.

V - number of nodes
E - number of edges

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---