"""Represents Node in this data structure"""


class Node:
    def __init__(self, value, color):
        self.value = value
        self.left = None
        self.right = None
        self.color = color


"""Red Black BST"""


class RedBlackBST:
    def __init__(self):
        self.root = None
        self.RED = True
        self.BLACK = False

    # comparing two values
    def compareTo(self, first, second):
        return first - second

    # check if the node is red
    def isRed(self, node):
        if node is None:
            return False
        return node.color == self.RED

    # if tree is not red left leaning
    # this function will rotate it to left
    def Rotateleft(self, h):
        assert self.isRed(h.right)
        x = h.right
        h.right = x.left
        x.left = h
        x.color = h.color
        h.color = self.RED
        return x

    # if there are two consecutives red nodes
    # this method will rotate one red node to
    # the right
    def Rotateright(self, h):
        assert self.isRed(h.left)
        x = h.left
        h.left = x.right
        x.right = h
        x.color = h.color
        h.color = self.RED
        return x

    # if both left and right edge are red
    # this method will flip the colors, making them
    # black
    def flipColors(self, h):
        assert self.isRed(h.left)
        assert self.isRed(h.right)
        h.left.color = self.BLACK
        h.right.color = self.BLACK
        h.color = self.RED

    # method for inserting into the tree
    # this method is called in insert method
    def Realinsert(self, x, value):
        if x is None:
            return Node(value, self.RED)
        cmp = self.compareTo(value, x.value)
        if cmp < 0:
            x.left = self.Realinsert(x.left, value)
        elif cmp > 0:
            x.right = self.Realinsert(x.right, value)
        else:
            x.value = value

        if self.isRed(x.right) and not self.isRed(x.left):
            x = self.Rotateleft(x)
        if self.isRed(x.left) and self.isRed(x.left.left):
            x = self.Rotateright(x)
        if self.isRed(x.left) and self.isRed(x.right):
            self.flipColors(x)

        return x

    # user calls this method for inserting
    # an element into the tree
    def insert(self, value):
        self.root = self.Realinsert(self.root, value)

    # this method searchs for an
    # element in the tree
    # returns the value if found
    def search(self, value):
        x = self.root
        while x is not None:
            cmp = self.compareTo(value, x.value)
            if cmp < 0:
                x = x.left
            elif cmp > 0:
                x = x.right
            else:
                return x.value
        return "{} doesn't exist".format(value)

    """Hibbard Deletion"""

    # user call this method to delete
    # an element from the tree
    def delete(self, value):
        self.root = self.Realdelete(self.root, value)

    # this method deletes the value from the tree.
    # Called inside the delete method
    # returns the node deleted
    def Realdelete(self, x, value):
        if x is None:
            return None
        cmp = self.compareTo(value, x.value)

        if cmp < 0:
            x.left = self.Realdelete(x.left, value)
        elif cmp > 0:
            x.right = self.Realdelete(x.right, value)
        else:
            if x.right is None:
                return x.left
            if x.left is None:
                return x.right

            t = x
            x = self.Min(t.right)
            x.right = self.deleteMin(t.right)
            x.left = t.left

        return x

    # method for deleting the minimum
    # element in the tree
    def deleteMin(self, x):
        if x.left is None:
            return x.right
        x.left = self.deleteMin(x.left)
        return x

    # returns the minimum element in the tree
    def Min(self, x):
        if x.left is None:
            return x
        return self.Min(x.left)

    # prints the elements in a
    # non-decreasing order
    def inorder(self):
        self.inorderRec(self.root)
        print("")

    def inorderRec(self, root):
        if root is not None:
            self.inorderRec(root.left)
            print(root.value, end=" ")
            self.inorderRec(root.right)


if __name__ == "__main__":
    """The class name is RedBlackBST()
    After creating an object of this class, the client can
    use the following methods:
    1.object.insert(value): insert the value given
    to the BST
    2.object.search(value): this method would return to you the
    value if it exists
    3. object.delete(value): this method will delete
    the provided value form the tree
    4.object.inorder(): this method will print all the values
    in the tree in a non-decreasing order"""

    # driver program

    bst = RedBlackBST()
    bst.insert(5)
    bst.insert(7)
    bst.insert(1)
    print(bst.search(5))
    print(bst.search(19))
    bst.insert(19)
    print(bst.search(19))
    bst.insert(3)
    bst.insert(2)
    bst.insert(9)
    bst.inorder()
    bst.delete(9)
    bst.inorder()
