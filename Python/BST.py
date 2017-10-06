class TreeNode:
    def __init__(self,key,value):
        self.key=key
        self.value=value
        self.left=None
        self.right=None
        self.parent=None

class BinarySearchTree:
    def __init__(self):
        self.root=None
    
    def minimum(self):
        temp=self.root
        while temp.left is not None:
            temp=temp.left
        return temp
    
    def maximum(self):
        temp=self.root
        while temp.right is not None:
            temp=temp.right
        return temp
    
    def predecessor(self,keyptr):
        temp=keyptr
        if temp.left is not None:
            temp=temp.left
            while temp.right is not None:
                temp=temp.right 
            return temp
        while temp.parent is not None:
            if temp.parent.value<keyptr.value:
                return temp.parent
            temp=temp.parent
        return None
    
    def successor(self,keyptr):
        temp=keyptr
        if temp.right is not None:
            temp=temp.right
            while temp.left is not None:
                temp=temp.left
            return temp
        while temp.parent is not None:
            if temp.parent.value>keyptr.value:
                return temp.parent
            temp=temp.parent
        return None

    def search(self,k):
        temp=self.root
        while temp is not None:
            if temp.key==k:
                return True
            elif temp.key<k:
                temp=temp.right
            else:
                temp=temp.left
        return False
    
    def insert(self,key,value):
        newNode=TreeNode(key,value)
        temp=self.root
        #root insertion
        if temp is None:
            self.root=newNode
            return
        while temp is not None:
            par=temp
            if temp.key>key:
                temp=temp.left
            else:
                temp=temp.right
        if key>par.key:
            par.right=newNode
        else:
            par.left=newNode
        newNode.parent=par
        
    def delete(self,key):
        #searching for key
        keyptr=self.root
        f=-1
        while keyptr is not None:
            if keyptr.key==key:
                f=0
                break
            elif keyptr.key<key:
                keyptr=keyptr.right
            else:
                keyptr=keyptr.left
        if f==-1:
            print("This key doesn't exist in tree.")
            return
                
        if self.root is None:
            return
        #case 1: node to be deleted is a leaf
        if keyptr.left is None and keyptr.right is None:
            par=keyptr.parent
            if par.left is keyptr:
                par.left=None
            else:
                par.right=None

        #case 2: node has one child
        elif (keyptr.left is None and keyptr.right is not None):
            keyptr.key=keyptr.right.key
            keyptr.value=keyptr.right.value
            keyptr.right=None
        elif (keyptr.right is None and keyptr.left is not None):
            keyptr.key=keyptr.left.key
            keyptr.value=keyptr.left.value
            keyptr.left=None

        #case 3: node has 2 children
        else:
            s=self.successor(keyptr)
            keyptr.key=s.key
            keyptr.value=s.value
            return self.delete(s)

    def preOrderTraversal(self,rootnode):
        temp=rootnode
        if temp is not None:
            print(temp.key,end=' ')
            self.preOrderTraversal(temp.left)
            self.preOrderTraversal(temp.right)
    
    def postOrderTraversal(self,rootnode):
        temp=rootnode
        if temp is not None:
            self.postOrderTraversal(temp.left)
            self.postOrderTraversal(temp.right)
            print(temp.key,end=' ')
    
    def inOrderTraversal(self,rootnode):
        temp=rootnode
        if temp is not None:
            self.inOrderTraversal(temp.left)
            print(temp.key,end=' ')
            self.inOrderTraversal(temp.right)
            

def main():
    tree=BinarySearchTree()
    tree.insert(25,"auto")
    tree.insert(12,"bus")
    tree.insert(15,"truck")
    s=tree.search(30)
    tree.insert(123,"plane")
    tree.insert(45,"train")
    print(s)
    print(tree.minimum().key)
    print(tree.maximum().key)
    print(tree.predecessor(tree.root).key)
    print(tree.successor(tree.root).key)
      
    tree.preOrderTraversal(tree.root)
    print()
    tree.inOrderTraversal(tree.root)
    print()
    tree.postOrderTraversal(tree.root)
    print()
    tree.delete(12)
   
    tree.preOrderTraversal(tree.root)
    print()
    print(tree.search(12))

if __name__ == '__main__':
    main()    