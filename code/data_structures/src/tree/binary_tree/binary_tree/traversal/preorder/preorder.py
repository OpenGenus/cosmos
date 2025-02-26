def preorder_traversal(node):
    if(node==None):
        print("Empty Tree")
        return
    print(node.data)
    if node.left:
        preorder_traversal(node.left)
    if node.right:
        preorder_traversal(node.right)
