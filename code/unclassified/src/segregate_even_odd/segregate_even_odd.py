# Implemented using Bubble Sort

ar = list(map(int, input("Enter the elements: ").split()))
n = len(ar)
for i in range(n):
    swapped = False
    for j in range(0, n - i - 1):
        if ar[j] > ar[j + 1]:
            ar[j], ar[j + 1] = ar[j + 1], ar[j]
            swapped = True
    if not swapped:
        break
print("The Final Array: ", *ar)

# INPUT:
# Enter the elements: -1 -2 4 8 2 -8

# OUTPUT:
# The Final Array:  -8 -2 -1 2 4 8
