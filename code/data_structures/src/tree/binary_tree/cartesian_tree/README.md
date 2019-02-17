# Cartesian tree

## Explaination
A Cartesian tree is a binary rooted tree data structure that follows following properties:
* The Cartesian tree formed from a sequence has a node for each number in that sequence.
* An inorder traversal of the tree would give the original sequence used to form the tree.
* Follows the heap property, i.e. each node has value greater than its parent (min heap) or each node has value smaller than its parent (max heap).

Cartesian tree is generally used as binary search tree for an ordered sequence and for answering range based queries.

## Algorithm
* __Building the Cartesian tree:__ Below is linear algorithm to build Cartesian tree following min heap property.
```
1. Traverse the sequence from left to right.
2. For every node x, repeat steps 3 to 5.
3. Start at the node representing value before x, call it y. Check all nodes in path
    the path from y to root of the tree (including y) until you reach a node with
    value less than x, say z.
4. If z is found, set the z's right child to be new node, and z's previous child
    to be left child of x.
5. If z is not found, set x to be root and set x's left child to be previous tree.

To create a tree with max heap property, in step 3, search for the first node
    with value greater than x.
```

* __Sorting the sequence:__
```
1. Create a priority queue, initially having only the root of Cartesian tree.
2. Pop the minimum value x from the priority queue
3. Add x to the output sequence
4. Push the left child of x from Cartesian tree into priority queue.
5. Push the right child of x from Cartesian tree into priority queue.
6. If priority queue is not empty, goto step 2.
```

## Complexity
__Space complexity__ : O(N)

Worst case time complexities:
* __Build__ : O(N)
* __Sort__ : Worst case O(Nlog<sub>2</sub>(N))
             Best case O(N)

Where `N` is the size of sequence.

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---
