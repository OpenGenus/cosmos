# Given a non-negative number represented as an array of digits, add 1 to the number

# Ignore the leading zeros and start from the first non-zero digit

ar = list(map(int, input("Enter the elements: ").split()))
i = 0
while i < len(ar):
    if ar[i] != 0:
        break
    else:
        i = i + 1
string = ""
for j in range(i, len(ar)):
    string = string + str(ar[j])
k = int(string) + 1

print("The final array: ", *list(str(k)))

# INPUT:
# Enter the elements: 0 0 8 0 1 2

# OUTPUT:
# The final array:  8 0 1 3
