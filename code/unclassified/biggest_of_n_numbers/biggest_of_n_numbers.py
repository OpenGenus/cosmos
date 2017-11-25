elements = []
n = int(input("Enter number of elements:"))
for i in range(1, n + 1):
  elements.append(int(input("Enter element:")))
elements.sort()
print("Largest element is : ", elements[n - 1])
