# Part of Cosmos by OpenGenus Foundation
class node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


def post_order(root):
    if root is not None:
        post_order(root.left)
        post_order(root.right)
        print(root.data, end=" ")


if __name__ == '__main__':
    root = node(1)
    root.left = node(2)
    root.right = node(3)
    root.left.left = node(4)
    root.left.right = node(5)
    root.right.left = node(6)
    root.right.right = node(7)

    print("Post order traversal of tree is:", end=" ")
    post_order(root)
