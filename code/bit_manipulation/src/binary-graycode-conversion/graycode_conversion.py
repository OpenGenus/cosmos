def gray_to_binary(n):
    binary = n
    while n > 0:
        n >>= 1
        binary ^= n
    return binary

# Example
gray_num = 4  # Gray: 100
binary_num = gray_to_binary(gray_num)
print(bin(binary_num))  # Output: 0b111
