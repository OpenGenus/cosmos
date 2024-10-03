# Post Order traversal of Binary Tree

 To traverse a binary tree in postorder,
 we visit all its nodes exactly once and recursively process all the left subtrees first, then the right subtrees and then, finally processing the root node.
 
## Example
In following binary tree, the post order traversal will give: 4 5 2 6 7 3 1

![visualization](https://i0.wp.com/algorithms.tutorialhorizon.com/files/2015/12/Tree-Traversals-Postorder.png)
 
 
## Algorithm
postorder(tree)
1. Traverse the left subtree, i.e., call post_order(left_subtree)
2. Traverse the right subtree, i.e., call post_order(right_subtree)
3. Visit the root.
 
## Complexity
The time complexity of depth first postorder traversal of binary tree is `O(n)` because we traverse each node exactly once.
