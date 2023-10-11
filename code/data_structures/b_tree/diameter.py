"""
Diameter of the tree
"""

maxDiameter = 0

def diameter(root):
    global maxDiameter
    
    if root == None:
        return 0

    left = diameter(root.left)
    right = diameter(root.right)

    if left + right + 1 > maxDiameter:
        maxDiameter = left + right + 1

    return max(left + right) + 1
