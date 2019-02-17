# Cartesian tree

## Explaination
A treap is a height balanced binary tree. Treap is used to store a sequence in a tree, which allows for various applications like searching. A treap can is a combination of a tree and a heap, possessing properties of both:
* The nodes of the tree follow structure of binary search tree with respect to values.
* The nodes of tree follow heap property with respect to priority values.

A treap is expected to perform three major operations:
* Search
* Insert
* Delete
Inorder traversal of a treap would give the sorted sequence.

## Algorithm
* __Insert operation:__ Insert operation is done for the whole sequence to build the tree.
```
1. Create new node with the given key value x and random priority value.
2. Start from root and perform search for x by using key values to perform
    a binary search. When a leaf node is reached, insert new node at the
    leaf. This is basically a binary search tree insertion.
3. Rotate up to make sure heap property is satisfied with respect to
    priority values.
```

* __Search operation:__ Search operation is same as search in binary search tree since rotation maintains BST property.
```
1. Start from root to search for a key x.
2. Compare key of the node. If key is equal to x, return the node.
3. If key is less than x go to right child and repeat step 2.
4. If key is greater than x go to left child and repeat step 2.
5. If key is not equal to x and node has no children, then x is not
    present in tree.
```

* __Delete operation:__
```
1. Search for the node to be deleted.
2. If the node is at leaf, delete it directly.
3. Otherwise, set the node to lowest priority and perform rotations until
    heap property of tree is satisfied.
4. Delete the node when it is at leaf.
```

## Complexity
__Space complexity__ : O(N)

Worst case time complexities:
* __Search__ : O(log<sub>2</sub>N)
* __Insert__ : O(log<sub>2</sub>N)
* __Delete__ : O(log<sub>2</sub>N)


Where `N` is the size of sequence.

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---
