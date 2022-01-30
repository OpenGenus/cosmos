def is_perfect_number(n):
    sum = 0
    for x in range(1, n):
        if n % x == 0:
            sum += x
    return sum == n


num = int(input("Please enter a number to check if it is perfect or not"))
print(is_perfect_number(num))
