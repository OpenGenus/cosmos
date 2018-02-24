class Dequeue:
	""" Python implementation the Deque """

	def __init__(self, container=None):
		if container is None:
			container = []
		self.__container = container

	def insert_at_front(self, d):
		self.__container.insert(0, d)

	def insert_at_rear(self, d):
		self.__container.append(d)

	def remove_front(self):
		return self.__container.pop(0)

	def remove_rear(self):
		return self.__container.pop()

# Sample inputs
if __name__ == '__main__':
	dq = Dequeue();
	for i in range(1,11):
		dq.insert_at_front(i);
		dq.insert_at_rear(-1*i);
	
	for i in range(1,11):
		print(dq.remove_front())   
		print(dq.remove_rear())  
		print('\n')
