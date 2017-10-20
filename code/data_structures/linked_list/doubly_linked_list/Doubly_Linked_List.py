

class Node:
	def __init__(self, data=None, nxt=None, prev=None):
		self.data = data
		self.next_node = nxt
		self.prev_node = prev
		print("Node of value {} Born".format(data))
	def __del__(self):
		print("Node Died.")


class Doubly_Linked_List:
	def __init__(self, head=None, tail=None):
		self.head = head
		self.tail = tail
		print("List Born")

	def __del__(self):
		print("List Died")

	def isEmpty(self):
		return (self.head is None) and (self.tail is None)

	def insert(self, value):
		node = Node(value)
		if self.isEmpty():
			self.head = node
			self.tail = node
		else:
			temp = self.tail
			temp.next_node = node
			node.prev_node = temp
			self.tail = node

	def search(self, value):
		if self.isEmpty():
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
		if self.isEmpty():
			return
		temp = self.head
		while temp:
			print("{}, ".format(temp.data))
			temp = temp.next_node


if __name__ == '__main__':
	list = Doubly_Linked_List()
	elements = {1, 2, 5, 7, 32, 753, 34, 55, 4}
	for element in elements:
		list.insert(element)
	list.printList()
	