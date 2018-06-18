#!/usr/bin/python
"""
	AVL Tree in Python
	18.06.18
	Yash Shah(https://github.com/yashshah1)
"""

class Node(object):
	def __init__(self, key):
		self.left = None
		self.right = None
		self.key = key

class AVLTree(object):
	def __init__(self, key = None):
		self.node = None 
		self.height = -1  
		self.balance = 0; 
		
		if key: 
			self.insert(i)
	
	def height(self):
		if self.node is not None:
			return self.node.height
		else:
			return 0
	def is_leaf(self):
		if self.height == 0:
			return 0
		else:
			return 1
			
	def rrotate(self):
		"""
		Right-rotates the tree
		"""
		node_1 = self.node 
		node_2 = self.node.left.node 
		node_3 = node_2.right.node 
		
		self.node = node_2
		node_2.right.node = node_1
		node_1.left.node = node_3
	
	def lrotate(self):
		"""
		Left-rotates the tree
		"""
		node_1 = self.node 
		node_2 = self.node.right.node 
		node_3 = node_2.left.node 
		
		self.node = node_2 
		node_2.left.node = node_1 
		node_1.right.node = node_3
	
	def balance_the_tree(self):
		"""
		The actual "AVL" stuff of rebalancing.
		refer to: https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
		"""
		
		# key inserted. Let's check if we're balanced
		self.update_heights(False)
		self.update_balances(False)
		
		while self.balance < -1 or self.balance > 1: 
			if self.balance > 1:
				if self.node.left.balance < 0:  
					self.node.left.lrotate() # II
					self.update_heights()
					self.update_balances()
				self.rrotate() # I
				self.update_heights()
				self.update_balances()
				
			if self.balance < -1:
				if self.node.right.balance > 0:  
					self.node.right.rrotate() # we're in case III
					self.update_heights()
					self.update_balances()
				self.lrotate() # IV
				self.update_heights()
				self.update_balances()
			
	def insert(self, key):
		#First do normal BST, according to key
		if self.node is None:
			self.node = Node(key)
			self.node.left = AVLTree()
			self.node.right = AVLTree()
			
		elif key < self.node.key:
			self.node.left.insert(key)
		else:
			self.node.right.insert(key)
			
		
		self.balance_the_tree()


	def delete(self, key):
		if self.node is not None: #check for a node
			if self.node.key == key: #If key is root
				if (self.node.left.node is None) and (self.node.right.node is None):
					self.node = None #No children, YAY, remove root
				elif self.node.left.node is None:
					self.node = self.node.right.node #If left child, make it the right
				elif self.node.right.node is None:
					self.node = self.node.left.node
				
				# both children present. Find logical successor
				else:  
					replacement = self.min_value_node(self.node.right.node) #read func_doc
					if replacement:  
						self.node.key = replacement.key 						
						self.node.right.delete(replacement.key)
				self.balance_the_tree()  
				
			elif key < self.node.key: #key is in left tree
				self.node.left.delete(key)  
			else: #key is in right tree
				self.node.right.delete(key)
			
			self.balance_the_tree()
	
			
	def update_heights(self, recurse = True):
		if self.node is not None: 
			if recurse: 
				if self.node.left: 
					self.node.left.update_heights()
				if self.node.right:
					self.node.right.update_heights()
			
			self.height = max(self.node.left.height, self.node.right.height) + 1 
		else: 
			self.height = -1 
			
	def update_balances(self, recurse = True):
		if self.node:
			if recurse: 
				if self.node.left:
					self.node.left.update_balances()
				if self.node.right:
					self.node.right.update_balances()

			self.balance = self.node.left.height - self.node.right.height 
		else: 
			self.balance = 0 


	def check_balanced(self):
		if (self is None) or (self.node is None):
			return True
		
		self.update_heights()
		self.update_balances()
		if abs(self.balance) < 2:
			if self.node.left.check_balanced() and self.node.right.check_balanced():
				return True
		return False
		
	def inorder_traverse(self):
		if self.node is not None:
			self.node.left.inorder_traverse()
			print self.node.key, 
			self.node.right.inorder_traverse()
			
	def min_value_node(self, node):
		"""
		Gets the minimum value node 
		"""
		if node: #safety check
			while node.left:
				if node.left.node is None:
					return node 
				else: 
					node = node.left.node  
		return node 

#Driver:
if __name__ == "__main__":
	my_tree = AVLTree()
	l = [7, 5, 2, 6, 3, 4, 1, 8, 9, 0]
	print "Adding [7, 5, 2, 6, 3, 4, 1, 8, 9, 0]"
	for i in l:
		my_tree.insert(i)
	my_tree.inorder_traverse()
	print
	print
	
	my_tree.delete(3)
	print "Delete 3"
	my_tree.inorder_traverse()
	print
	print
	print "Delete 4"
	my_tree.delete(4)
	my_tree.inorder_traverse()
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
