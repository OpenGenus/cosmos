#!/usr/bin/pyhton

"""
Program for InsertionSort sorting
"""
import numpy as np
import cProfile


def InsertionSort(L):
	"""
	arguments:
        ---------
		L: list

	return:
	-------
		L: list
	
	description:
	------------
		Function to return sorted list using Insertion sort.
	"""
	length = len(L)
	for i in range(length):
		key = L[i]
		j = i - 1

		while j >= 0:
			if key < L[j]:
				j -= 1
			else:
				break

		j += 1
		L.insert(j,L.pop(i))

	return L


if __name__ == "__main__":

	#creating a random array of length 100
	L = np.random.random_integers(100,size = (100,)).tolist()
	print "Given array : \n",L
	print "Sorted array : \n",InsertionSort(L)
	
	




























