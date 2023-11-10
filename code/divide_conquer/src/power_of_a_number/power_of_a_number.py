# Python3 program to check if
# a given number can be expressed
# as power
import math

# Returns true if n can be written as x^y
def isPower(n) :
	if (n==1) :
		return True

	# Try all numbers from 2 to sqrt(n) as base
	for x in range(2,(int)(math.sqrt(n))+1) :
		y = 2
		p = (int)(math.pow(x, y))

		# Keep increasing y while power 'p' is smaller
		# than n.
		while (p<=n and p>0) :
			if (p==n) :
				return True
			
			y = y + 1
			p = math.pow(x, y)
		
		
	return False
	

# Driver Program
for i in range(2,100 ) :
	if (isPower(i)) :
		print(i,end=" ")
		
		

