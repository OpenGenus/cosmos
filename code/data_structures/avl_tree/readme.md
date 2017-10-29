# AVL Tree
Description
---------
It is a **self balancing** binary search tree, where the difference between heights of left and right subtrees cannot be more than one for all nodes. In other words, the **balance factor** for each node in an AVL tree cannot exceed 1.
Where, 

> balance factor = height of left subtree - height of right subtree


Thus, A binary tree is defined to be an AVL tree if the invariant

    BalanceFactor(N) belongs to {–1,0,+1} 
for every node in tree.


If at any time the balance factor exceeds one, rebalancing via rotation is done to restore this property.


Time Complexity
---------
As AVL trees remain balanced, so, they take **O(logn)** time for all the basic operations. 

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
