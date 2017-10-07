# Binary indexed tree or fenwick tree
# Space Complexity: O(N) for declaring another array of N=size num_of_elements
# Time Complexity: O(logN) for each operation(update and query as well)
# original array for storing values for later lookup
# Part of Cosmos by OpenGenus Foundation
array=[]
# array to store cumulative sum
bit=[]
'''
index i in the bit[] array stores the cumulative sum from the index i to i - (1<<r) + 1 (both inclusive),
 where r represents the last set bit in the index i
'''
class FenwickTree:
# To intialize list of num_of_elements+1 size
	def initialize(self,num_of_elements):
		for i in range(num_of_elements+1):
			array.append(0)
			bit.append(0)

	def update(self,x,delta):
		while x<=num_of_elements:
			bit[x]=bit[x]+delta
			# x&(-x) gives the last set bit in a number x
			x=x+(x&-x)

	def query(self,x):
		range_sum=0
		while x>0:
			range_sum=range_sum+bit[x]
			# x&(-x) gives the last set bit in a number x
			x=x-(x&-x)
		return range_sum

fenwick_tree=FenwickTree()
num_of_elements=int(input("Enter the size of list: "))

fenwick_tree.initialize(num_of_elements)

for i in range(num_of_elements):
	# storing data in orginal list
	element=int(input("Enter the list element: "))
	# updating the BIT array
	fenwick_tree.update(i+1,element)

number_of_queries=int(input("Enter number of queries: "))

for i in range(number_of_queries):
	left_index=int(input("Enter left index (1 indexing): "))
	right_index=int(input("Enter right index (1 indexing): "))
	if right_index < left_index:
		print("Invalid range ")
		continue
	print("Sum in range[%d,%d]: "%(left_index,right_index))
	print(fenwick_tree.query(right_index)-fenwick_tree.query(left_index-1))
