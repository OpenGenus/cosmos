# Priority Queue 
Description
---
A priority queue is an abstract data type which is like a regular queue 
or stack data structure, but where additionally each element has a "priority" or a score
associated with it. 

In a priority queue, an element with high priority 
is served before an element with low priority. 
If two elements have the same priority, 
they are served according to their order in the queue.

This folder contains some Priority Queue implementations using a heap

Priority Queue API
---
- **pop()**: Removes the top element from the queue
- **push()**: Inserts an item to the queue while maintaining the priority order
- **top()**: Returns the top element of the queue (the item with the top priority)
- **empty()**: Checks if the queue is empty

Time Complexity
---
pop() and push() take O(log n) and the others take O(1).
