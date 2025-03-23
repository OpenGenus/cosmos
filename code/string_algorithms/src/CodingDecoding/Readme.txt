We start from root and do following until a leaf is found.
If current bit is 0, we move to left node of the tree.
If the bit is 1, we move to right node of the tree.
If during traversal, we encounter a leaf node, we print character of that particular leaf node and then again continue the iteration of the encoded data starting from step 1.