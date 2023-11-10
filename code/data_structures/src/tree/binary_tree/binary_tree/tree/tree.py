## BST operation
## functionalities included are:
"""
*insert node
*delete node
*find successor of a node
*find minimum in BST
*find maximum in BST
*traverse in BST(level order traversal)
*find height of the BST
*search in BST
*get node path in BST
*find Lowest Common Ancestor in BST(LCA)
"""


## class for node creation
class Node(object):
    def __init__(self, data=None):
        self.left = None
        self.right = None
        self.data = data

    def __str__(self):
        return str(self.data)


## the Binary Search Tree class
class BST(object):
    def __init__(self):
        self.root = None

    def insert(self, val):
        if self.root == None:
            print("root!")
            self.root = Node(val)
        else:
            root = self.root
            while True:
                if val < root.data:
                    if not root.left:
                        print("left")
                        root.left = Node(val)
                        break
                    else:
                        print("left")
                        root = root.left
                else:
                    if not root.right:
                        print("right")
                        root.right = Node(val)
                        break
                    else:
                        print("right")
                        root = root.right

    def insert_recursive(self, root, val):
        if root == None:
            return Node(val)
        else:
            if val < root.data:
                node = self.insert_recursive(root.left, val)
                root.left = node
            else:
                node = self.insert_recursive(root.right, val)
                root.right = node

    def traverse(self):  ## level order traversals
        nodes = []
        nodes.append(self.root)
        print("\n\nBST representation")
        while nodes:
            current = nodes.pop(0)
            print(current.data)
            if current.left:
                nodes.append(current.left)
            if current.right:
                nodes.append(current.right)

    def find_max(self):
        if self.root is None:
            return None
        else:
            current = self.root
            while True:
                if current.right is not None:
                    current = current.right
                else:
                    break
            return current.data

    def find_min(self):
        if self.root is None:
            return None
        else:
            current = self.root
            while True:
                if current.left is not None:
                    current = current.left
                else:
                    break
            return current.data

    def height_(self, root):  ## the height driver function
        if root == None:
            return 0
        else:
            max_left_subtree_height = self.height_(root.left)
            max_right_subtree_height = self.height_(root.right)
            max_height = max(max_left_subtree_height, max_right_subtree_height) + 1
            return max_height

    ## height of the first node is 0 not 1
    def height(self):
        depth = self.height_(self.root)
        return depth - 1

    def search(self, val):
        if self.root is None:
            return False
        else:
            current = self.root
            while True:
                if val < current.data:
                    if current.left:
                        current = current.left
                    else:
                        break
                elif val > current.data:
                    if current.right:
                        current = current.right
                    else:
                        break
                if val == current.data:
                    return True
            return False

    def get_node_path(self, val):
        if self.search(val):
            path = []
            current = self.root
            while True:
                if current is None:
                    break
                else:
                    if val == current.data:
                        path.append(current.data)
                        break
                    elif val < current.data:
                        if current.left:
                            path.append(current.data)
                            current = current.left
                        else:
                            break
                    elif val > current.data:
                        if current.right:
                            path.append(current.data)
                            current = current.right
                        else:
                            break
            return path
        return None

    def LCA(self, val1, val2):
        path1 = self.get_node_path(val1)
        path2 = self.get_node_path(val2)
        try:
            store = None
            if len(path1) != len(path2):
                min_list = min(path1, path2, key=len)
                max_list = max(path1, path2, key=len)
            min_list, max_list = path1, path2
            for lca1 in min_list:
                for lca2 in max_list:
                    if lca1 == lca2:
                        store = lca1
            return store
        except:
            return None

    def successor(self, root):
        current = root.right
        while True:
            if current.left:
                current = current.left
            else:
                break
        return current

    def Delete(self, root, val):  ## driver function for delettion
        if root is None:
            return None
        else:
            if val < root.data:
                root.left = self.Delete(root.left, val)
            elif val > root.data:
                root.right = self.Delete(root.right, val)
            else:
                if not root.left:
                    right = root.right
                    del root
                    return right
                if not root.right:
                    left = root.left
                    del root
                    return left
                else:
                    successor = self.successor(root)
                    root.data = successor.data
                    root.right = self.Delete(root.right, successor.data)
        return root

    def delete(self, val):
        if self.search(val):
            self.root = self.Delete(self.root, val)
        else:
            return "error"

    def clear(self):
        print("\n\nre-initializing\n")
        self.__init__()


## creating an instance for the BST
bst = BST()
bst.insert(5)
bst.insert(9)
bst.insert(10)
