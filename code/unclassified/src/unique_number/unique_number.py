# Unique numbers in an array

l1 = list(map(int, input("Enter the elements: ").split()))
uniq_list = []

for i in l1:
    if i not in uniq_list:
        uniq_list.append(i)
print("Unique elements: ", *(uniq_list))


# INPUT:
# Enter the elements: 1 2 2 3 4 5 5

# OUTPUT:
# Unique elements:  1 2 3 4 5
