"""

# unclassified | biggest of n numbers | biggest of n numbers |  PYTHON 
# Part of Cosmos by OpenGenus Foundation

"""


elements = []
n = int(input("Enter number of elements:"))
for i in range(0, n):
    elements.append(int(input("Enter element:")))
elements.sort()
print("Largest element is : ", elements[n - 1])
