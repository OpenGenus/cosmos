# OOPs prpgrame for single linked list in python

#Linked list node class
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None




# Linkedlist class 
class Linkedlist:

#Method for initializing a linked list	
	def __init__(self):
		self.head=None
#Method to traverse through a linked list
	def traverse(self):
		temp=self.head
		while(temp):
			print(str(temp.data),end='->')
			temp=temp.next
		print("NULL")

# Method for inserting node
	def insert_node(self,data=0):
		new_node=Node(data)
		if(self.head==None):
			self.head=new_node
		else:
			temp=self.head
			while(temp.next!=None):
				temp=temp.next
			temp.next=new_node

# main function
"""
Example:
list_1=Linkedlist()	
list_1.insert_node()
list_1.inert_node()
list_1.insert_node(1)
list_1.insert_node(2)
list_1.insert_node(3)
list_1.traverse()
"""
#Output: 0->0->1->2->3->NULL

