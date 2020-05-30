# Reversing a string in Python

s = input("Enter a string: ")
s1 = ""
m = list(s)
m.append(" ")
l = []
for i in range(len(m)):
    if m[i] != " ":
        s1 += m[i]
    else:
        l.append(s1)
        s1 = ""
print("The Reversed String: ", *l[::-1])

# INPUT
# Enter a string: Code is Life
#
# OUTPUT:
# The Reversed String: Life is Code
