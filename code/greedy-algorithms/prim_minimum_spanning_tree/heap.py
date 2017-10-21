class Heap:
	'''
	Implementation of a binary minimum heap data structure
	Assumptions:
		Input elements can be tuples or lists, where
		the first element is a key (which the algorithm for enforcing the heap property is based on),
		the second element is an identifier for the related object,
		and after that, anything can follow.
	Attributes:
		heap: a list as a realization of the heap
		heapIdx: a dictionary with keys the identifiers of the objects in the heap, and
				 with values the indices of the objects' positions in the heap.
	'''

	def __init__(self, element = None, batch = None):
		'''
		Creates the heap
		The heap can be initiated empty, with an object, or with many objects
		Args:
			element: an object for insertion into the heap
			batch: a list of objects for insertion into the heap
		'''
		self.heap, self.heapIdx = [], {}
		if batch: self.heapify(batch)
		if element: self.insert(element)


	def length(self):
		'''
		Returns the number of objects in the heap
		'''
		return len(self.heap) 


	def insert(self, element):
		'''
		Inserts an object in the heap
		Args:
			element: object for insertion into the heap
		'''
		self.heap[self.length():] = [element]
		self.heapIdx[element[1]] = self.length() - 1
		self.__siftUp()


	def __siftUp(self):
		'''
		Enforces the heap property (after an insertion into the heap)
		'''
		childIdx = self.length() - 1
		parentIdx = int((childIdx - 1) / 2)
		while self.heap[childIdx][0] < self.heap[parentIdx][0]:
			parent, child = self.heap[parentIdx], self.heap[childIdx]
			self.heap[parentIdx], self.heapIdx[child[1]] = child, parentIdx
			self.heap[childIdx], self.heapIdx[parent[1]] = parent, childIdx
			parentIdx, childIdx = int((parentIdx - 1) / 2), parentIdx


	def heapify(self, batch):
		'''
		Builds the heap in linear time
		
		Args:
			batch: list of objects for insertion into the heap
		'''
		for idx, element in enumerate(batch):  # populates the heap
			self.heap.append(element)
			self.heapIdx[element[1]] = idx
		for i in range(int(self.length() / 2) - 1, -1, -1):  # enforces the heap property
			self.__minHeapify(i)


	def __minHeapify(self, parentIdx):
		'''
		Enforces the heap property, top to bottom, along a certain path
		
		Args:
			parentIdx: starting position for the checking
		'''
		leftChildIdx, rightChildIdx = 2 * parentIdx + 1, 2 * parentIdx + 2
		lowest = leftChildIdx if leftChildIdx < self.length() and self.heap[leftChildIdx] < self.heap[parentIdx] else parentIdx
		if rightChildIdx < self.length() and self.heap[rightChildIdx] < self.heap[lowest]: lowest = rightChildIdx
		if lowest != parentIdx:
			parent, child = self.heap[parentIdx], self.heap[lowest]
			self.heap[parentIdx], self.heapIdx[child[1]] = child, parentIdx
			self.heap[lowest], self.heapIdx[parent[1]] = parent, lowest
			self.__minHeapify(lowest)


	def extractMin(self):
		'''
		Extracts the top (minimum) object from the heap, and rectifies the heap
		'''
		minElm = self.heap[0]
		del self.heapIdx[minElm[1]]
		lastElm = self.heap.pop()
		if self.length():
			self.heap[0] = lastElm
			self.heapIdx[lastElm[1]] = 0
			self.__siftDown(0)
		return minElm


	def __siftDown(self, parentIdx):
		'''
		Enforces the heap property (after an extraction from the heap)
		'''
		if 2 * parentIdx + 1 >= self.length(): return  # if the parent doesn't have children, you are good to go!
		if 2 * parentIdx + 2 >= self.length():  # if the parent has one child...
			# and the child's key is less than the parent's key, it swaps the entries
			if self.heap[parentIdx][0] > self.heap[2 * parentIdx + 1][0]:
				parent, child = self.heap[parentIdx], self.heap[2 * parentIdx + 1]
				self.heap[parentIdx], self.heapIdx[child[1]] = child, parentIdx
				self.heap[2 * parentIdx + 1], self.heapIdx[parent[1]] = parent, 2 * parentIdx + 1
			return

		parent = self.heap[parentIdx]
		leftChild, rightChild = self.heap[2 * parentIdx + 1], self.heap[2 * parentIdx + 2]
		minLeft = False
		if leftChild[0] <= rightChild[0]: minLeft = True
		if parent[0] > min(leftChild[0], rightChild[0]):
			self.heap[parentIdx] = leftChild if minLeft else rightChild
			self.heapIdx[leftChild[1] if minLeft else rightChild[1]] = parentIdx
			self.heap[2 * parentIdx + 1 if minLeft else 2 * parentIdx + 2] = parent
			self.heapIdx[parent[1]] = 2 * parentIdx + 1 if minLeft else 2 * parentIdx + 2
			self.__siftDown(2 * parentIdx + 1 + (not minLeft))


	def get(self, id):
		'''
		Returns an object from the heap. If the object is not in the heap, it returns None
		Args:
			id: identifier of the object to be retrieved
		'''
		return self.heap[self.heapIdx[id]] if id in self.heapIdx else None


	def delete(self, id):
		'''
		Deletes an object from the heap, and returns that object
		Args:
			id: identifier of the object to be handled
		'''
		if id not in self.heapIdx: return None
		idx = self.heapIdx[id]
		del self.heapIdx[id]
		element = self.heap[idx]
		lastElm = self.heap.pop()
		if idx != self.length():
			self.heap[idx] = lastElm
			self.heapIdx[lastElm[1]] = idx
			self.__siftDown(idx)
		return element



if __name__ == "__main__":
	l = [[9,'a'],[7,'c'],[5,'d'],[4,'h'],[3,'f'],[2,'x'],[1,'r'],[6,'t'],[3,'u'],[7,'v'],[2,'w'],[6,'l'],[4,'o']]
	heap = Heap(batch = l)
	print(heap.heap)
	heap.extractMin()
	print(heap.heap)
