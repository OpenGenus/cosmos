## BST operation
## functionalities included are:
'''
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
'''
import sys
import random


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
            self.root = Node(val)
            print ("root: %s" % self.root)
        else:
            root = self.root
            print "Insert: %d" % val
            while True:
                if val < root.data:
                    print "%d goes left (parent: %s)" % (val, root)
                    if not root.left:
                        root.left = Node(val)
                        break
                    else:
                        root = root.left
                else:
                    print "%d goes right (parent: %s)" % (val, root)
                    if not root.right:
                        root.right = Node(val)
                        break
                    else:
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
        print "\n\nBST representation"
        while nodes:
            current = nodes.pop(0)
            print "%s" % current.data
            if current.left:
                print "left next level: %s" % current.left
                nodes.append(current.left)
            if current.right:
                print "right, next level: %s" % current.right
                nodes.append(current.right)
            if not current.left and not current.right:
                print "leaf"

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
        if root == None: return 0
        else:
            max_left_subtree_height = self.height_(root.left)
            max_right_subtree_height = self.height_(root.right)
            max_height = max(max_left_subtree_height,
                             max_right_subtree_height) + 1
            return max_height

    ## height of the first node is 0 not 1
    def height(self):
        depth = self.height_(self.root)
        return (depth - 1)

    def search(self, val):
        if self.root is None: return False
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
                    if lca1 == lca2: store = lca1
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
                    print "Delete: %s" % root
                    right = root.right
                    del root
                    return right
                if not root.right:
                    print "Delete: %s" % root
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
        print "\n\nre-initializing\n"
        self.__init__()


def test_BST(args=None):
    if not args:
        args = sys.argv[1:]
  
    bst = BST()

    with open(args[0]) as f:
        cmds = f.read().replace('\n', ' ').replace('\r', ' ').split() 
        for cmd in cmds:
            if cmd[0] == 'i':
                i = int(cmd[1:])
                bst.insert(i)
            elif cmd[0] == 'd':
                i = int(cmd[1:])
                bst.delete(i)
            elif cmd[0] == 'p':
                bst.traverse() 

        # Example test case
        # i6 i8 i3 i1 i9 i5 i2 d1 d5 p
        # produces the following below:
        # ***output.txt***
        # root: 6
        # Insert: 8
        # 8 goes right (parent: 6)
        # Insert: 3
        # 3 goes left (parent: 6)
        # Insert: 1
        # 1 goes left (parent: 6)
        # 1 goes left (parent: 3)
        # Insert: 9
        # 9 goes right (parent: 6)
        # 9 goes right (parent: 8)
        # Insert: 5
        # 5 goes left (parent: 6)
        # 5 goes right (parent: 3)
        # Insert: 2
        # 2 goes left (parent: 6)
        # 2 goes left (parent: 3)
        # 2 goes right (parent: 1)
        # Delete: 1
        # Delete: 5


        # BST representation
        # 6
        # left next level: 3
        # right, next level: 8
        # 3
        # left next level: 2
        # 8
        # right, next level: 9
        # 2
        # leaf
        # 9
        # leaf


## creating an instance for the BST
if __name__ == '__main__':
    test_BST();

