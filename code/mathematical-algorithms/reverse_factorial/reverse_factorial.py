# Part of Cosmos by OpenGenus Foundation
def reversefactorial(factorial):
    n = 1
    m = 0
    notfound = True
    while m < 100:
        m += 1
        n *= m
        if factorial == n:
            print(str(factorial) + " is " + str(m) + "!")
            notfound = False
            break
        elif m == 100:
            print(str(factorial) + " is not a factorial product of any integer.")


factorial = int(input("Reverse Factorial > "))
reversefactorial(factorial)
