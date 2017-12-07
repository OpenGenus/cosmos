# Heap 
Description
---
Heap is a special case of balanced binary tree data structure where the root-node key is 
compared with its children and arranged accordingly. 

If a has child node b then -

key(a) <= key(b)

If the value of parent is lesser than that of child, this property generates **Min Heap** 
otherwise it generates a **Max Heap**

Heap API
---
- **extractTop()**: Removes top element from the heap
- **insert()**: Inserts an item to the heap
- **top()**: Returns the top element of the heap (the minimum or maximum value)
- **empty()**: Checks if the heap is empty

Time Complexity
---
extractTop() and insert() take O(log n) and the others take O(1).

Example folders
---
**max_heap**: Various implementations of a Max Heap.
**min_heap**: Various implementations of a Min Heap
**priority_queue**: Priority Queue implementations using a heap
