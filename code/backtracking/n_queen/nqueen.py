
import json
global x
x=[]
global n
n=0
def place(k, i):
	# print("In place:")
	for l in range(1,k):
		if((x[l]==i) or (abs(x[l]-i) == abs(l-k))):
			return False
	return True


def nqueens(k):
	global x
	global n

	for j in range(1,n+1):	# iterate over all columns
		if(place(k, j)):
			x[k] = j
			if(k==n):
				print(x[1:n+1])
			else:
				nqueens(k+1)


def main():
	global n
	global x

	n = input("Enter n for n-queen problem solution:")
	x = [i for i in range(n+1)]
	for m in range(1,n+1):
		print "\nFirst queen is placed in column ",m,"\n"
		x[1]=m   
		nqueens(2)

if __name__ == '__main__':
	main()