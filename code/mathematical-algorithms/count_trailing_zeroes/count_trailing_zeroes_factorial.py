def countTrailingZeroes(n):
    count = 0
    i = 5
    while n/i>=1:
        count += n/i
        i *= 5
    return count

print("Enter n : ", end='')
n = int(input())
print("Number of trailing zeroes in factorial of {} : {}".format(n, int(countTrailingZeroes(n))))
