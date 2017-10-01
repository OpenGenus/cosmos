# Part of Cosmos by OpenGenus Foundation
import math

def heapRoot(arr, i, length):
	left = 2*i +1
	right = 2*i + 2
	max_index = i

	if left<length and arr[left]>arr[max_index]:
		max_index = left

	if right<length and arr[right]>arr[max_index]:
		max_index = right

	if max_index != i:
		swap(arr, max_index, i)
		heapRoot(arr, max_index, length)

def swap(arr, a, b):
	arr[a] = arr[a]+arr[b]
	arr[b] = arr[a]-arr[b]
	arr[a] = arr[a]-arr[b]

#sorting is in the ascending order
def heapSort(arr):
	#form a max heap
	for i in range(math.floor(len(arr)/2), -1, -1):
		heapRoot(arr, i, len(arr))

	length = len(arr)
	#remove the root and reform the heap
	for i in range(len(arr)-1, 0, -1):
		print(i)
		swap(arr, 0, i)
		print(arr)
		length -= 1
		heapRoot(arr, 0, length)

#arr = [7, -1, -2, 5, 15, 0, 10]
#heapSort(arr)
#print(arr)
