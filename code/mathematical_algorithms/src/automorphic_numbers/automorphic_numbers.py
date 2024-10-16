"""
In mathematics an automorphic number (sometimes referred to as a circular number) is a number
whose square "ends" in the same digits as the number itself. 
For example, 5^2 = 25, 6^2 = 36, 76^2 = 5776, 376^2 = 141376,and 890625^2 = 793212890625, 
so 5, 6, 76 and 890625
"""

# Part of Cosmos by OpenGenus Foundation
def automorphic(num):
    order = len(str(num))
    square_num = num ** 2
    str_num = str(square_num)
    if str_num[len(str_num) - order :] == str(num):
        return True
    else:
        return False


if __name__ == "__main__":
    if automorphic(138):
        print("Automorphic Number")
    else:
        print("Not Automorphic Number")
