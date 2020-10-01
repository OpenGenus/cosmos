class Node:
    def __init__(self,data=0,left=None,right=None):
        self.data=data
        self.left=left
        self.right=right

##############################################################################3

class BST:
    def __init__(self):
        self.root=None

    def insert(self,data):
        new_node=Node(data)
        if not(self.root):
            self.root=new_node
            return
        curr_node=self.root
        while(curr_node):
            if(data<=curr_node.data):
                if(curr_node.left==None):
                    curr_node.left=new_node
                    return
                curr_node=curr_node.left
            elif(data>curr_node.data):
                if(curr_node.right==None):
                    curr_node.right=new_node
                    return
                curr_node=curr_node.right

    def lookup(self,item):
        if(self.root==None):
            print("Empty Tree")
            return
        curr_node=self.root
        while(curr_node):
            if(curr_node.data==item):
                print("Present")
                return
            elif(item<curr_node.data):
                curr_node=curr_node.left
            else:
                curr_node=curr_node.right
        print("Absent")

    def remove(self,item):
        if self.root==None:
            print("Empty Tree")
            return
        curr_node=self.root
        parent_node=Node()
        while(curr_node):
            if curr_node.data==item:
                #If it is a leaf node
                if curr_node.left==curr_node.right==None:
                    #If parent node is less than current node
                    if (curr_node==self.root):
                        self.root=None
                    elif parent_node.data<curr_node.data:
                        parent_node.right=None
                    else:
                        parent_node.left=None
                #If it has only left child
                elif curr_node.right==None:
                    if curr_node==self.root:
                        self.root=curr_node.left
                    else:
                        parent_node.left=curr_node.left
                #If it has only right child
                elif curr_node.left==None:
                    if curr_node==self.root:
                        self.root=curr_node.right
                    else:
                        parent_node.right=curr_node.right
                #If it has both left and right child
                else:
                    repl_node=self.inorder_successor(curr_node.right)
                    repl_node.left=repl_node.right=None
                    if curr_node.left!=repl_node:
                        repl_node.left=curr_node.left
                    if curr_node.right!=repl_node:
                        repl_node.right=curr_node.right
                    if curr_node==self.root:
                        self.root=repl_node
                    #Checking node is to left or right of parent
                    elif curr_node.data>parent_node.data:
                        parent_node.right=repl_node
                    else:
                        parent_node.left=repl_node
                return
            elif item<curr_node.data:
                parent_node=curr_node
                curr_node=curr_node.left
            elif item>curr_node.data:
                parent_node=curr_node
                curr_node=curr_node.right
        print("Not Found")

    def inorder_successor(self,node):
        curr_node=node
        parent_node=Node()
        while(curr_node):
            if curr_node.left==None:
                parent_node.left=curr_node.right
                return curr_node
            parent_node=curr_node
            curr_node=curr_node.left

############################################################

bst=BST()
