# Python3 program for weighted job scheduling using
# Naive Recursive Method

# Importing the following module to sort array
# based on our custom comparison function
from functools import cmp_to_key

# A job has start time, finish time and profit
class Job:
	
	def __init__(self, start, finish, profit):
		
		self.start = start
		self.finish = finish
		self.profit = profit

# A utility function that is used for
# sorting events according to finish time
def jobComparataor(s1, s2):
	
	return s1.finish < s2.finish

# Find the latest job (in sorted array) that
# doesn't conflict with the job[i]. If there
# is no compatible job, then it returns -1
def latestNonConflict(arr, i):
	
	for j in range(i - 1, -1, -1):
		if arr[j].finish <= arr[i - 1].start:
			return j
			
	return -1

# A recursive function that returns the
# maximum possible profit from given
# array of jobs. The array of jobs must
# be sorted according to finish time
def findMaxProfitRec(arr, n):
	
	# Base case
	if n == 1:
		return arr[n - 1].profit

	# Find profit when current job is included
	inclProf = arr[n - 1].profit
	i = latestNonConflict(arr, n)
	
	if i != -1:
		inclProf += findMaxProfitRec(arr, i + 1)

	# Find profit when current job is excluded
	exclProf = findMaxProfitRec(arr, n - 1)
	return max(inclProf, exclProf)

# The main function that returns the maximum
# possible profit from given array of jobs
def findMaxProfit(arr, n):
	
	# Sort jobs according to finish time
	arr = sorted(arr, key = cmp_to_key(jobComparataor))
	return findMaxProfitRec(arr, n)

# Driver code
values = [ (3, 10, 20), (1, 2, 50),
		(6, 19, 100), (2, 100, 200) ]
arr = []
for i in values:
	arr.append(Job(i[0], i[1], i[2]))
	
n = len(arr)

print("The optimal profit is", findMaxProfit(arr, n))

# This code is code contributed by Kevin Joshi
