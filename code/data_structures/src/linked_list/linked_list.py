''' simple prpgrame for single linked list in python '''


Head=None   ''' head node, initilase Null or none '''
Tail=None   ''' tail node, initilase Null or none '''

'''  object class '''

class A:
	def __init__(self):
		self.data=0
		self.next=None

''' function for creating node '''

def create_node():
	t=A()
	return t

'''  function for inserting node '''

def insert_node():
	global Head,Tail
	temp=create_node()
	print("Enter your value",end="\n")
	a=input()	
	temp.data=a
	if(Head==None):
		Head=temp
		Tail=temp
	else:
		Tail.next=temp
		Tail=temp

''' function for traversing linked list '''

def traverse(Head):
	t=Head
	while(t.next!=None):
		print(t.data,end="\n")
		t=t.next
	print(t.data,end="\n")

''' main function '''

insert_node()
insert_node()
insert_node()
insert_node()

traverse(Head)   ''' passing head node for tarversing'''

