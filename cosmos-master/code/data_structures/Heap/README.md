# Min Heap 
Description
---
Heap is a special case of balanced binary tree data structure where the root-node key is compared with its children and arranged accordingly. If a has child node b then -

key(a) <= key(b)

As the value of parent is lesser than that of child, this property generates Min Heap.

Functions
---
- pop()
 --Removes top from the heap
- push()
--Adds an item to the heap
- getTop()
--Returns the top element of the heap (the minimum value)
- isEmpty()
--Returns true if the heap is empty

Time Complexity
---
pop() and push() take O(log n) and the others take O(1).
