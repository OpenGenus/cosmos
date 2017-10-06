import math

def finding_square(num):
    res = 0
    num = int(num)
    for i in range(num):
        if(i*i==num):
            res=1
            break
        if(i>math.sqrt(num)):
            break
    return res

number = input("Enter a number: ")
result = finding_square(number)

if(result==0):
    print(number, "is NOT a perfect square")
else:
    print(number, "is a perfect square")