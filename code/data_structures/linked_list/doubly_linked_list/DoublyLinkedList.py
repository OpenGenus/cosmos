

class Node:
	# initializing a Node class
	def __init__(self, data=None, nxt=None, prev=None):
		self.data = data
		self.next_node = nxt
		self.prev_node = prev
		# prints out when new node is born
		print("Node of value {} Born".format(data))

	def __del__(self):
		# inside deconstructor. Prints when node is deleted
		print("Node Died.")


class DoublyLinkedList:
	def __init__(self, head=None, tail=None):
		self.head = head
		self.tail = tail
		print("List Born")

	def __del__(self):
		print("List Died")

	def is_empty(self):
		return (self.head is None) and (self.tail is None)

	def insert_front(self, value):
		node = Node(value)
		if self.is_empty():
			self.head = node
			self.tail = node
		else:
			temp = self.head
			node.next_node = temp
			temp.prev_node = node
			self.head = node

	def insert_back(self, value):
		node = Node(value)
		if self.is_empty():
			self.head = node
			self.tail = node
		else:
			temp = self.tail
			temp.next_node = node
			node.prev_node = temp
			self.tail = node

	def search(self, value):
		if self.is_empty():
			return 0
		else:
			found = False
			temp = self.head
			if temp.data == value:
				return True
			while temp and found is False:
				temp = temp.next_node
				if temp.data == value:
					found = True
			return temp if found is True else False

	def delete(self, value):
		to_delete = self.search(value)
		if to_delete is False:
			return False
		temp = to_delete.prev_node
		cur = to_delete.next_node
		temp.next_node = cur
		cur.prev_node = temp
		del temp

	def printList(self):
		if self.is_empty():
			return
		temp = self.head
		while temp:
			print("{}, ".format(temp.data))
			temp = temp.next_node


if __name__ == '__main__':
	list = DoublyLinkedList()
	front_elements = {1, 2, 5, 7}
	back_elements = {33, 23, 9, 4}
	for element in front_elements:
		list.insert_front(element)
	for element in back_elements:
		list.insert_back(element)
	list.printList()
	