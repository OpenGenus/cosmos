#Function to search x in an array using binary search

def binary_search(array,x):
	length = len(array)
	
	#index holders
	a = 0
	b = length - 1
		
	while a < b:
		c = (b-a) // 2
		if array[c] > x:
			a = c + 1
		else:
			b = c - 1

	if array[c] != x or c == length:
		print(str(x),"not found")
	else:
		print("Index of ",str(x),"is",str(c))

if __name__ == "__main__":
	#reading array and search element
	array = input("Enter elements of array with sapce as separator: \n")
	x = int(input("Enter a value to search: \n"))

	array = [int(element) for element in array.strip().split(" ")]
	binary_search(array,x)		

