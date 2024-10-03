def postorder_traversal(node):
    if(node==None):
        print("Empty Tree")
        return
    if node.left:
        postorder_traversal(node.left)
    if node.right:
        postorder_traversal(node.right)
    print(node.data)
