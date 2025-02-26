def inorder_traversal(node):
    if(node==None):
        print("Empty Tree")
        return
    if node.left:
        inorder_traversal(node.left)
    print(node.data)
    if node.right:
        inorder_traversal(node.right)
