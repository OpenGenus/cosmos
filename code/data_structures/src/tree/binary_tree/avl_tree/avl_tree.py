class Node():
	def __init__(self, d = 0):
		self.key = d
		self.height = 1
		self.left = None
		self.right = None
def height(node):
	if node is None:
		return 0
	return node.height


def rightRotate(node):
	x = node.left
	T2 = x.right

	x.right = node
	node.left = T2
	
	node.height = max(height(node.left), height(node.right)) + 1
	x.height = max(height(x.left), height(x.right)) + 1

	return x

def leftRotate(node):
	y = node.right
	T2 = y.left

	y.left = node
	node.right = T2

	node.height = max(height(node.left), height(node.right)) + 1
	y.height = max(height(y.left), height(y.right)) + 1

	return y

def getBalance(node):
	if node is None:
		return 0
	return height(node.left) - height(node.right)
		
def insert(node, key):
	if node is None:
		return Node(key)

	if key < node.key:
		node.left = insert(node.left, key)
	elif key > node.key:
		node.right = insert(node.right, key)
	else: 
		return node

	node.height = 1 + max(height(node.left), height(node.right))
	
	balance = getBalance(node)

	if balance > 1 and key < node.left.key:
		return rightRotate(node)
		
	if balance < -1 and key > node.right.key:
		return leftRotate(node)

	if balance > 1 and key > node.left.key:
	
		node.left = leftRotate(node.left)
		return rightRotate(node)

	if balance < -1 and key < node.right.key:
		node.right = rightRotate(node.right)
		return leftRotate(node)
	return node
 
def minValueNode(node):
	current = node

	while current.left is not None:
	   current = current.left

	return current

def deleteNode(root, key):
	if root is None:
		return root

	if key < root.key:
		root.left = deleteNode(root.left, key)

	elif key > root.key:
		root.right = deleteNode(root.right, key)

	else:
		if root.left is None or root.right is None:
			temp = None
			if temp == root.left:
				temp = root.right
			else:
				temp = root.left
				
			if temp is None:
				temp = root
				root = null
			else:
				root = temp 
		else:
			temp = minValueNode(root.right)
			root.key = temp.key
			root.right = deleteNode(root.right, temp.key)

	if root is None:
		return root

	root.height = max(height(root.left), height(root.right)) + 1

	balance = getBalance(root)

	if balance > 1 and getBalance(root.left) >= 0:
		return rightRotate(root)

	if balance > 1 and getBalance(root.left) < 0:
		root.left = leftRotate(root.left)
		return rightRotate(root)

	if balance < -1 and getBalance(root.right) <= 0:
		return leftRotate(root)

	if balance < -1 and getBalance(root.right) > 0:
		root.right = rightRotate(root.right)
		return leftRotate(root)
	return root


def preOrder(node):
	if node is not None:
		print str(node.key),
		preOrder(node.left)
		preOrder(node.right)
		
def main():
	print "Enter numbers (space seperated) to be added to the AVL Tree: ",
	arr = map(int, raw_input().strip().split())
	
	tree = Node(arr[0])
	for i in arr[1::]:
		tree = insert(tree, i)
 	print "Preorder traversal of constructed tree is : ",
	preOrder(tree)
	print
	tree = deleteNode(tree, arr[0])
	print
	print "Preorder traversal after deletion of " + str(arr[0]) + ": ",
	preOrder(tree)
if __name__ == "__main__":
	main()

  
