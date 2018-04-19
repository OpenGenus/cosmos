# Tree Sort
Tree sort is a sorting algorithm that is based on Binary Search Tree data structure. It first creates a binary search tree from the elements of the input list or array and then performs an in-order traversal on the created binary search tree to get the elements in sorted order. 

 Its typical use is sorting elements online: after each insertion, the set of elements seen so far is available in sorted order.

## Explanation

The following flow chart explains the steps involved in performing tree sort by depicting how every element in a binary search tree is printed in ascending order.

![image](https://upload.wikimedia.org/wikipedia/commons/2/2b/Binary_tree_sort%282%29.png)

> Image credits: wikipedia

## Algorithm
```
structure BinaryTree
    BinaryTree:LeftSubTree
    Object:Node
    BinaryTree:RightSubTree

procedure Insert(BinaryTree:searchTree, Object:item)
    IF searchTree.Node IS NULL THEN
        SET searchTree.Node TO item
    ELSE
        IF item IS LESS THAN searchTree.Node THEN
            Insert(searchTree.LeftSubTree, item)
        ELSE
            Insert(searchTree.RightSubTree, item)

procedure InOrder(BinaryTree:searchTree)
    IF searchTree.Node IS NULL THEN
        EXIT procedure
    ELSE
        InOrder(searchTree.LeftSubTree)
        EMIT searchTree.Node
        InOrder(searchTree.RightSubTree)

procedure TreeSort(Collection:items)
    BinaryTree:searchTree
   
    FOR EACH individualItem IN items
        Insert(searchTree, individualItem)
   
    InOrder(searchTree)
```

## Complexity
**Time complexity**
- Worst Case: 
	- **O(n<sup>2</sup>)** (unbalanced)
	- **O(n logn)** (balanced)
- Average Case: **O(n logn)**
- Best Case: **O(n logn)**

**Space Complexity**: **O(n)** auxillary space

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---