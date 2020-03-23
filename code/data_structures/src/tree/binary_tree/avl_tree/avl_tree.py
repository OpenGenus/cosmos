"""
AVL Node
"""


class avlnode:

    """
    Constructor
    """

    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return str(self.value)


"""
AVL Tree
"""


class avltree():

    """
    Constructor
    """

    def __init__(self):
        self.node = None
        self.height = -1
        self.balance = 0

    """
    Insert new value into AVL Tree
    """

    def insert(self, value):
        tree = self.node
        new_node = avlnode(value)

        if tree is None:
            self.node = new_node
            self.node.left = avltree()
            self.node.right = avltree()

        elif value < tree.value:
            self.node.left.insert(value)

        elif value > tree.value:
            self.node.right.insert(value)

        self.rebalance()

    def get_height(self):
        if self.node:
            return self.node.height
        else:
            return 0

    """
    Rotate left
    """

    def rotate_left(self):
        old_root = self.node
        new_root = self.node.right.node
        new_right_to_old_root = new_root.left.node

        self.node = new_root
        old_root.right.node = new_right_to_old_root
        new_root.left.node = old_root

    """
    Rotate right
    """

    def rotate_right(self):
        old_root = self.node
        new_root = self.node.left.node
        new_left_to_old_root = new_root.right.node

        self.node = new_root
        old_root.left.node = new_left_to_old_root
        new_root.right.node = old_root

    """
    Rebalance a tree after insertion or deletion of a node
    """

    def rebalance(self):

        self.recompute_height(recursive=False)
        self.update_balance(recursive=False)

        # For each node if balance is -1, 0 or 1 no rotation is required
        while self.balance < -1 or self.balance > 1:

            # Left subtree is bigger than right subtree
            if self.balance > 1:

                if self.node.left.balance < 0:

                    self.node.left.rotate_left()
                    self.recompute_height()
                    self.update_balance()

                self.rotate_right()
                self.recompute_height()
                self.update_balance()

            # Right subtree is bigger than left subtree
            if self.balance < -1:

                if self.node.right.balance > 0:

                    self.node.right.rotate_right()
                    self.recompute_height()
                    self.update_balance()

                self.rotate_left()
                self.recompute_height()
                self.update_balance()

    """
    Compute height - max of right or left subtree height
    """

    def recompute_height(self, recursive=True):
        # Height is max height of either left or right subtree =1 for root

        if self.node:
            if recursive:
                if self.node.left:
                    self.node.left.recompute_height()
                if self.node.right:
                    self.node.right.recompute_height()

            self.height = 1 + max(self.node.left.height,
                                  self.node.right.height)
        else:
            self.height = -1

    """
    Update balance - Balance = height (left subtee ) - height (right subtree)
    """

    def update_balance(self, recursive=True):

        if self.node:
            if recursive:
                if self.node.left:
                    self.node.left.update_balance()
                if self.node.right:
                    self.node.right.update_balance()

            self.balance = self.node.left.height - self.node.right.height
        else:
            self.balance = 0

    def inorder_traverse(self):
        """
        Left tree nodes , root , right tree nodes 
        """

        if not self.node:
            return []

        result = []
        left_nodes = self.node.left.inorder_traverse()
        for lnode in left_nodes:
            result.append(lnode)

        result.append(self.node.value)

        right_nodes = self.node.right.inorder_traverse()
        for rnode in right_nodes:
            result.append(rnode)

        return result

    def find_min_value(self):
        if not self.node:
            return []

        left_nodes = self.node.left.inorder_traverse()
        return left_nodes[0]

    def find_max_value(self):
        if not self.node:
            return []

        right_nodes = self.node.right.inorder_traverse()
        return right_nodes[-1]

    def pretty_print(self, node=None, level=0):
        if not node:
            node = self.node

        if node.right.node:
            self.pretty_print(node.right.node, level + 1)
            print(('\t' * level), ('    /'))

        print(('\t' * level), node.value)

        if node.left.node:
            print(('\t' * level), ('    \\'))
            self.pretty_print(node.left.node, level + 1)

    def lookup(self, value):
        if self.node:
            if self.node.value == value:
                return True
            elif self.node.value > value:
                return self.node.left.lookup(value)
            else:
                return self.node.right.lookup(value)

        return False

    def delete(self, value):

        if self.node:
            if self.node.value == value:
                # Value found
                # Check if leaf node - if yes then simply delete it
                if not self.node.left.node and not self.node.right.node:
                    self.node = None
                # contains only right sub tree
                elif not self.node.left.node:
                    self.node = self.node.right.node
                # contains only left sub tree
                elif not self.node.right.node:
                    self.node = self.node.left.node
                else:
                    # Find successor - smallest node in right subtree
                    # Can use predeccessor too - which is the largest node
                    # in the left subtree

                    successor = self.node.right.node
                    while successor and successor.left.node:
                        successor = successor.left.node

                    if successor:
                        self.node.value = successor.value

                        # delete the duplicate node value from the right
                        # subtree

                        self.node.right.delete(successor.value)

            elif self.node.value > value:
                self.node.left.delete(value)

            elif self.node.value < value:
                self.node.right.delete(value)

            self.rebalance()


if __name__ == "__main__":
    tree = avltree()
    data = [15, 50, 6, 4, 7, 23, 71, 5]

    for value in data:
        tree.insert(value)

    print('In order traverse ', tree.inorder_traverse())
    tree.pretty_print()

    # Expected value 4
    print('minimum value is ', tree.find_min_value())

    # Expected value 71
    print('maximum value is ', tree.find_max_value())

    # Expected to be true
    print('AVL Tree contains 15  ', tree.lookup(15))

    # Expected to be false
    print('AVL Tree contains 99  ', tree.lookup(99))

    # Leaf node deletion
    tree.delete(7)
    print('In order traverse after deleting 7 ', tree.inorder_traverse())
    tree.pretty_print()

    # Node with both sub trees deleted
    tree.delete(50)
    print('In order traverse after deleting 50 ', tree.inorder_traverse())
    tree.pretty_print()

    # Node with only left sub tree delete
    tree.delete(71)
    print('In order traverse after deleting 71 ', tree.inorder_traverse())
    tree.pretty_print()
