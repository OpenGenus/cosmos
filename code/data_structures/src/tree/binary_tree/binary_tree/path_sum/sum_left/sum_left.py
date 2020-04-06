# Sum of left leaves in a binary tree

# Class for individual nodes
class Node(object):
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class BinaryTree(object):
    def __init__(self):
        self.head = None

    def insert(self, item):
        if self.head == None:
            self.head = Node(item)
        else:
            self.add(self.head, item)

    def add(self, node, val):
        # Compare parent's value with new value
        if val < node.data:
            if node.left == None:
                node.left = Node(val)
            else:
                self.add(node.left, val)
        else:
            if node.right == None:
                node.right = Node(val)
            else:
                self.add(node.right, val)


def preorder(hash_map, level, head):
    if head != None:
        if level not in hash_map.keys():
            hash_map[level] = head.data
        preorder(hash_map, level + 1, head.left)
        preorder(hash_map, level + 1, head.right)


if __name__ == "__main__":
    print("Enter number of nodes: ")
    num = int(input())
    root = BinaryTree()
    for _ in range(num):
        print("Enter element #{}:".format(_ + 1))
        item = int(input())
        root.insert(item)
    left_elements = dict()
    preorder(left_elements, 0, root.head)
    print(sum([*left_elements.values()]))
