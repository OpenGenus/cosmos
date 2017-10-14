# Part of Cosmos by OpenGenus Foundation
Integer = int(input("Enter an Number :  "))
absInteger = abs(Integer)
num = 1
prime_num = []
if absInteger > 0:
    while num <= absInteger:
        x = 0
        if absInteger % num == 0:
            y = 1
            while y <= num:
                if num % y == 0:
                    x = x + 1
                y = y + 1
            if x == 2:
                prime_num.append(num)
        num = num + 1

    print("Your Input: " + str(Integer))
    print("Prime Factors : " + str(prime_num))
elif absInteger == 0:
    print("Your Input: 0")
    print("Prime Factors : [0]")
else:
    print("Please Input a number")
