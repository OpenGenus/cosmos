# Queue

Description
---
A queue or FIFO (first in, first out) is an abstract data type that serves as a collection of elements, with two principal operations: enqueue, the process of adding an element to the collection.(The element is added from the rear side) and dequeue, the process of removing the first element that was added. (The element is removed from the front side). It can be implemented by using both array and linked list.

Functions
---
- dequeue
--Removes an item from the queue
- enqueue()
--Adds an item to the queue
- front()
--Returns the front element from the queue
- size()
--Returns the size of the queue

## Time Complexity
- Enqueue - O(1)
- Dequeue - O(1)
- size    - O(1)
- front - O(n)
