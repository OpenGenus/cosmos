// ADDING ALL NUMBERS IN A STRING.

CODE:

st = input("Enter a string: ")
a = "" 
Sum = 0
for i in st: 
    if (i.isdigit()): 
        a += i
    else: 
        Sum += int(a) 
        a = "0"
print(Sum + int(a))

// INPUT:
Enter a string: 567hdon2

// OUTPUT:
569
