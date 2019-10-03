# Stack
Description
---
Stacks are an abstract data type (ADT) that function to store and manipulate data. Their order is last-in-first-out (LIFO). To implement a stack, an array or [linked list](../../linked_list) can be used. A stack is similar to a [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) in that the first object pushed onto the stack cannot be removed until every other object pushed on top of it has also been removed. It is also similar to a stack of plates in a cafeteria, where the bottom plate cannot be removed until all of the plates above it have been removed as well.

Functions
---
- Pop()
 --Removes an item from the stack
- Push()
--Adds an item to the stack
- Peek()
--Returns the top element of the stack
- isEmpty()
--Returns true if the stack is empty

Time Complexity
---
All the functions are O(1).

![visualization](https://ssodelta.files.wordpress.com/2014/10/stack.png)
