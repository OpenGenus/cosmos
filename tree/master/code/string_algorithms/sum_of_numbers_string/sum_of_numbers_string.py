# ADDING ALL NUMBERS IN A STRING.


st = input("Enter a string: ")
a = ""
total = 0
for i in st:
    if i.isdigit():
        a += i
    else:
        total += int(a)
        a = "0"
print(total + int(a))

# INPUT:
# Enter a string: 567hdon2

# OUTPUT:
# 569
