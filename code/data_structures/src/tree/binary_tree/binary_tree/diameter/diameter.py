# Time:  O(n)
# Space: O(h)

# Given a binary tree, you need to compute the length of the diameter of the tree.
# The diameter of a binary tree is the length of the longest path between
# any two nodes in a tree. This path may or may not pass through the root.
#
# Example:
# Given a binary tree
#           1
#          / \
#         2   3
#       / \
#       4   5
# Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
#
# Note: The length of path between two nodes is represented by the number of edges between them.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# The function diameter_height returns the diameter and the height of the tree.
# And the function find_tree_diameter uses it to just compute the diameter (by discarding the height).
class Solution:
    def diameter_height(node):
        if node is None:
            return 0, 0
        ld, lh = diameter_height(node.left)
        rd, rh = diameter_height(node.right)
        return max(lh + rh + 1, ld, rd), 1 + max(lh, rh)

    def find_tree_diameter(node):
        d, _ = diameter_height(node)
        return d


diameter = Solution()
