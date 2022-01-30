# Part of Cosmos by OpenGenus Foundation


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Compute the HEIGHT of a tree
def height(node):
    if node is None:
        return 0
    else:
        # Compute the height of each subtree
        lh = height(node.left)
        rh = height(node.right)
    return max(lh, rh) + 1


root = Node(11)
root.left = Node(22)
root.right = Node(33)
root.left.left = Node(44)
root.left.right = Node(66)

print("Height of tree is %d" % (height(root)))
