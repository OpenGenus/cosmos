# Moving zeroes to the end of array

ar = list(map(int, input("Enter the elements: ").split()))
lis = [0] * len(ar)
j = 0
for i in range(len(ar)):
    if ar[i] != 0:
        lis[j] = ar[i]
        j += 1
print("Final Array: ", *lis)

# INPUT: 
# Enter the elements: 0 2 3 0 5 0

# OUTPUT:
# Final Array:  2 3 5 0 0 0
