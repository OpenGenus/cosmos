# BinomialHeap
#### Structure
* Node
  - Foundational data element in binomial heap
  - Contains a value, and references to a sibling, child, and parent
* Head
  - Points to first node in node list
  - Each node in the list is a root to a binary heap
  - No two roots have the same order and are in 
    increasing order from head
* Sibling
  - Node that shares same parent as self
  - Sibling's order is greater than equal self's order
* Child
  - Node that is the head of a heap list of children
  - All child nodes in list have a value greater than self's value
* Parent
  - Node with reference to the child list the self is in
* Order
  - Number of node's children
 
Operation | Time Complexity 
----------|-------
getMin    | Θ(logn)
extractMin| Θ(logn)
insert    | Θ(1)
decreseKey| Θ(logn)
union     | O(logn)
   
#### Insert 13 87 50 61
![](images/insert_example.png)
