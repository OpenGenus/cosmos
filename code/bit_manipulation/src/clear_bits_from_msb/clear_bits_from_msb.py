"""
Problem Statement :
Clear all MSB's except for the first i LSB's of a number n.
MSB -> Most Significant Bit
LSB -> Most Significant Bit 
"""

def clear_bits_from_msb(n, i):
    mask = (1 << i) - 1
    return n & mask

if __name__ == "__main__":
    print("Enter n and i : ")
    n, i = map(int, input().split())

    n = clear_bits_from_msb(n, i)
    print("Result : " + str(n))

"""
Enter n and i :
14 3
Result : 6
"""
