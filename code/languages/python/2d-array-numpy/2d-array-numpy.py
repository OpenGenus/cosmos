import numpy as np   # Importing NumPy library for numerical operations

# Creating a 1D array
arr = np.array([2,4,6], dtype='int32')   # Define a NumPy array with datatype int32
print(arr)                               # Print the 1D array


# Creating a 2D array
arr = np.array([[1,2,3],[4,5,6]])        # 2 rows and 3 columns matrix
print(arr)                               # Print the 2D array


# Printing properties of the array
print(arr.shape)     # Shows dimensions of the array (rows, columns)
print(arr.dtype)     # Shows the datatype of elements in the array


# Accessing elements
print(arr[1,1])      # Access element at row index 1, column index 1
print(arr[1,:])      # Access entire second row


# Creating an array filled with ones
arr = np.ones((4,4))     # Create a 4x4 matrix of ones

# Slicing the array
t = arr[1:3,1:3]         # Extract a 2x2 sub-matrix from rows 1-2 and columns 1-2
print(t)


# Creating an array filled with zeros
arr_zeros = np.zeros((3,5))   # 3 rows and 5 columns of zeros
print(arr_zeros)


# Creating an array filled with 2s
arr_ones = 2 * np.ones((3,5))   # Multiply ones matrix by 2
print(arr_ones)


# Creating an array with random numbers
arr_rand = np.random.rand(3,4)  # Random values between 0 and 1
print(arr_rand)


# Creating an identity matrix
arr_i = np.identity(3)          # 3x3 identity matrix
print(arr_i)


# Creating a matrix for arithmetic operations
a = np.array([[1,2,3],[4,6,2],[0,7,1]])

print(a+2)     # Add 2 to every element
print(a-4)     # Subtract 4 from every element
print(a*3)     # Multiply each element by 3
print(a/2)     # Divide each element by 2
print(a**2)    # Square each element


# Matrix operations
a = np.array([[1,2,3],[4,6,2],[0,7,1]])
b = np.array([[3,6],[1,4],[7,2]])
c = np.array([[1,0,3],[2,3,1],[0,0,1]])

add = a + c            # Matrix addition
mul = np.matmul(a,b)   # Matrix multiplication

print(add)
print(mul)


# Finding minimum, maximum and determinant
print(np.min(b))          # Smallest element in matrix b
print(np.max(b))          # Largest element in matrix b
print(np.linalg.det(a))   # Determinant of matrix a


# Sum operations along axes
print(np.sum(b,axis=0))   # Sum of each column
print(np.sum(b,axis=1))   # Sum of each row


# Reshaping arrays
before = np.array([[1,2,3,4],[5,6,7,8]])  # 2x4 matrix
after = before.reshape(4,2)               # Convert to 4x2 matrix
print(after)


# Horizontal stacking (joining matrices side by side)
a = np.identity(2)
b = np.array([[1,2],[2,1]])

hstack = np.hstack((a,b))   # Combine matrices horizontally
print(hstack)


# Vertical stacking (joining matrices one above another)
a = np.identity(2)
b = np.array([[1,2],[2,1]])

vstack = np.vstack((a,b))   # Combine matrices vertically
print(vstack)
