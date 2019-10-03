# Python program to find minimum depth of a given Binary Tree
# Part of Cosmos by OpenGenus Foundation
# Tree node
class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


def minDepth(root):
    # Corner Case.Should never be hit unless the code is
    # called on root = NULL
    if root is None:
        return 0

    # Base Case : Leaf node.This acoounts for height = 1
    if root.left is None and root.right is None:
        return 1

    # If left subtree is Null, recur for right subtree
    if root.left is None:
        return minDepth(root.right) + 1

    # If right subtree is Null , recur for left subtree
    if root.right is None:
        return minDepth(root.left) + 1

    return min(minDepth(root.left), minDepth(root.right)) + 1


# Driver Program
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
print(minDepth(root))
