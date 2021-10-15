class BinaryTree:
    def __init__(self,value):
        self.left=None
        self.right=None
        self.value=value
    def insert(self,data):
        if self.value:
            if data<self.value:
                if self.left is None:
                    self.left=BinaryTree(data)
                else:
                    self.left.insert(data)
            elif data > self.value:
                if self.right is None:
                    self.right=BinaryTree(data)
                else:
                    self.right.insert(data)
            else:
                self.value=data
    def inorderprint(self):
        if self.left:
            self.left.inorderprint()
        print(self.value)
        if self.right:
            self.right.inorderprint()
    def Postorderprint(self):
        if self.left:
            self.left.Postorderprint()
        if self.right:
            self.right.Postorderprint()
        print(self.value)
    def Preorderprint(self):
        print(self.value)
        if self.left:
             self.left.Preorderprint()
        if self.right:
             self.right.Preorderprint()

choice="s"
rootvalue=int(input("Enter a value for the root: "))
root=BinaryTree(rootvalue)
while(choice=="s"):
              e=int(input("Enter element to be inserted: "))
              root.insert(e)
              choice=input("Do you wish to insert another element(s/n)")
while(True):
              traversal=int(input("1.Preorder\n2.Postorder\n3.Inorder\n4.Exit\n"))
              if traversal==1:
                  root.Preorderprint()
              if traversal==2:
                  root.Postorderprint()
              if traversal==3:
                  root.inorderprint()
              if traversal==4:
                  break
