#Function to perform linear search on a given array

def linear_search(array,x):
	#initializing index and length place holder	
	length = len(array)
	for i in range(length):
		if x == array[i]:
			print("Position of " + str(x) + " is " + str(i))
			return None
	print(str(x) + " not found")

if __name__ == "__main__":
	array = input("Enter elements of array with space as separator: \n")
	x = int(input("Enter the number you want to find:\n"))
	
	#converting str into a list
	array = [int(element) for element in array.strip().split(' ')]
	linear_search(array,x)
