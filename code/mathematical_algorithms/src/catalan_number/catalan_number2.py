"""

# mathematical algorithms | catalan number | catalan number2 |  PYTHON 
# Part of Cosmos by OpenGenus Foundation

"""


def catalanNum(n):
    if n <= 1:
        return 1
    result = 0
    for i in range(n):
        result += catalanNum(i) * catalanNum(n - i - 1)
    return result


for i in range(15):
    print(catalanNum(i))
