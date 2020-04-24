import numpy as np

# 1D array
arr = np.array([2,4,6],dtype='int32')
print(arr)

# 2D array
arr = np.array([[1,2,3],[4,5,6]])
print(arr)

print(arr.shape)
print(arr.dtype)

print(arr[1,1])
print(arr[1,:])

arr = np.ones((4,4))
t = arr[1:3,1:3]
print(t)

arr_zeros = np.zeros((3,5))
print(arr_zeros)

arr_ones = 2*np.ones((3,5))
print(arr_ones)

arr_rand = np.random.rand(3,4)
print(arr_rand)

arr_i = np.identity(3)
print(arr_i)

a = np.array([[1,2,3],[4,6,2],[0,7,1]])
print(a+2)
print(a-4)
print(a*3)
print(a/2)
print(a**2)

a = np.array([[1,2,3],[4,6,2],[0,7,1]])
b = np.array([[3,6],[1,4],[7,2]])
c = np.array([[1,0,3],[2,3,1],[0,0,1]])
add = a+c
mul = np.matmul(a,b)

print(add)
print(mul)

print(np.min(b))
print(np.max(b))
print(np.linalg.det(a))

print(np.sum(b,axis=0))
print(np.sum(b,axis=1))

before = np.array([[1,2,3,4],[5,6,7,8]])
after = before.reshape(4,2)
print(after)

a = np.identity(2)
b = np.array([[1,2],[2,1]])
hstack = np.hstack((a,b))
print(hstack)

a = np.identity(2)
b = np.array([[1,2],[2,1]])
vstack = np.vstack((a,b))
print(vstack)
