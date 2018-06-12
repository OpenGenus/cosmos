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


def right_rotate(node):
	x = node.left
	T2 = x.right

	x.right = node
	node.left = T2
	
	node.height = max(height(node.left), height(node.right)) + 1
	x.height = max(height(x.left), height(x.right)) + 1

	return x

def left_rotate(node):
	y = node.right
	T2 = y.left

	y.left = node
	node.right = T2

	node.height = max(height(node.left), height(node.right)) + 1
	y.height = max(height(y.left), height(y.right)) + 1

	return y

def get_balance(node):
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
	
	balance = get_balance(node)

	if balance > 1 and key < node.left.key:
		return right_rotate(node)
		
	if balance < -1 and key > node.right.key:
		return left_rotate(node)

	if balance > 1 and key > node.left.key:
	
		node.left = left_rotate(node.left)
		return right_rotate(node)

	if balance < -1 and key < node.right.key:
		node.right = right_rotate(node.right)
		return left_rotate(node)
	return node
 
def min_value_node(node):
	current = node

	while current.left is not None:
	   current = current.left

	return current

def delete_node(root, key):
	if root is None:
		return root

	if key < root.key:
		root.left = delete_node(root.left, key)

	elif key > root.key:
		root.right = delete_node(root.right, key)

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
			temp = min_value_node(root.right)
			root.key = temp.key
			root.right = delete_node(root.right, temp.key)

	if root is None:
		return root

	root.height = max(height(root.left), height(root.right)) + 1

	balance = get_balance(root)

	if balance > 1 and get_balance(root.left) >= 0:
		return right_rotate(root)

	if balance > 1 and get_balance(root.left) < 0:
		root.left = left_rotate(root.left)
		return right_rotate(root)

	if balance < -1 and get_balance(root.right) <= 0:
		return left_rotate(root)

	if balance < -1 and get_balance(root.right) > 0:
		root.right = right_rotate(root.right)
		return left_rotate(root)
	return root


def pre_order(node):
	if node is not None:
		print str(node.key),
		pre_order(node.left)
		pre_order(node.right)
		
def main():
	print "Enter numbers (space seperated) to be added to the AVL Tree: ",
	arr = map(int, raw_input().strip().split())
	
	tree = Node(arr[0])
	for i in arr[1::]:
		tree = insert(tree, i)
 	print "pre_order traversal of constructed tree is : ",
	pre_order(tree)
	print
	tree = delete_node(tree, arr[0])
	print
	print "pre_order traversal after deletion of " + str(arr[0]) + ": ",
	pre_order(tree)
	
if __name__ == "__main__":
	main()

  
