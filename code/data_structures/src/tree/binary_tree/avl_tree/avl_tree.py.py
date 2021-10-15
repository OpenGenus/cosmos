class node:
    def __init__(self, num):
        self.value = num
        self.left = None
        self.right = None
        self.height = 1

class AVL:

    def height(self, Node):
        if Node is None:
            return 0
        else:
            return Node.height

    def balance(self, Node):
        if Node is None:
            return 0
        else:
            return self.height(Node.left) - self.height(Node.right)

    def rotateR(self, Node):
        a = Node.left
        b = a.right
					
        a.right = Node
        Node.left = b
        Node.height = 1 + max(self.height(Node.left), self.height(Node.right))
        a.height = 1 + max(self.height(a.left), self.height(a.right))
        return a

    def rotateL(self, Node):
        a = Node.right
        b = a.left
        a.left = Node
        Node.right = b
        Node.height = 1 + max(self.height(Node.left), self.height(Node.right))
        a.height = 1 + max(self.height(a.left), self.height(a.right))
        return a

    def insert(self, val, root):
        if root is None:
            return node(val)
        elif val <= root.value:
            print("\n%s Inserted as Left Child of %s" % (val, root.value))
            root.left = self.insert(val, root.left)
            
        elif val > root.value:
            print("\n%s Inserted as Right Child of %s" % (val, root.value))
            root.right = self.insert(val, root.right)
            
            
        root.height = 1 + max(self.height(root.left), self.height(root.right))
        balance = self.balance(root)

        if balance > 1 and root.left.value > val:
            print("\nROTATE RIGHT of ", root.value)
            return self.rotateR(root)
        
        if balance < -1 and val > root.right.value:
            print("\nROTATE LEFT of ", root.value)
            return self.rotateL(root)
        
        if balance > 1 and val > root.left.value:
            print("\nROTATE LEFT of ", root.value)
            root.left = self.rotateL(root.left)
            return self.rotateR(root)
        
        if balance < -1 and val < root.right.value:
            print("\nROTATE RIGHT of ", root.value)
            root.right = self.rotateR(root.right)
            return self.rotateL(root)
        
        return root
                                                                                                                         
    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        print(root.value, end = '->')
        self.inorder(root.right)

   
Tree = AVL()
rt = None

while True:
    choice = int(input("To Continue Insertion Enter 1 Else 0: "))
    if choice == 0:
        break
    item = int(input("Enter the item to be inserted :  "))

    rt = Tree.insert(item, rt)
    Tree.inorder(rt)
