
class Node: 
	def __init__(self, data): 
		self.data = data 
		self.next = None

class LinkedList: 
	def __init__(self): 
		self.head = None
	
	 
	def append(self, new_value): 
		
		 
		new_node = Node(new_value) 
		
		
		if self.head is None: 
			self.head = new_node 
			return
		curr_node = self.head 
		while curr_node.next is not None: 
			curr_node = curr_node.next
			
		
		curr_node.next = new_node 
		
	def sortedMerge(self, x, y): 
		result = None
		
		if x == None: 
			return y 
		if y == None: 
			return x 
			
		
		if x.data <= y.data: 
			result = x 
			result.next = self.sortedMerge(x.next, y) 
		else: 
			result = y 
			result.next = self.sortedMerge(x, y.next) 
		return result 
	
	def mergeSort(self, z): 
		
		
		if z == None or z.next == None: 
			return z 

		 
		middle = self.getMiddle(z) 
		nexttomiddle = middle.next

		
		middle.next = None

		 
		left = self.mergeSort(z) 
		
		
		right = self.mergeSort(nexttomiddle) 

		
		sortedlist = self.sortedMerge(left, right) 
		return sortedlist 
	
	
	def getMiddle(self, head): 
		if (head == None): 
			return head 

		slow = head 
		fast = head 

		while (fast.next != None and
			fast.next.next != None): 
			slow = slow.next
			fast = fast.next.next
			
		return slow 
		
def printList(head): 
	if head is None: 
		print(' ') 
		return
	curr_node = head 
	while curr_node: 
		print(curr_node.data, end = " ") 
		curr_node = curr_node.next
	print(' ') 
	

if __name__ == '__main__': 
	li = LinkedList() 
	
	li.append(-5) 
	li.append(11) 
	li.append(-17) 
	li.append(12) 
	li.append(39) 
	li.append(24) 
	

	li.head = li.mergeSort(li.head) 
	print ("Sorted Linked List is:") 
	printList(li.head) 

