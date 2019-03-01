""" Part of Cosmos by OpenGenus Foundation """


def divide(dividend, divisor):

    if divisor == 0:
        return "undefined"

    isPositive = (dividend > 0) is (divisor > 0)
    dividend = abs(dividend)
    divisor = abs(divisor)

    answer = 0
    while dividend >= divisor:
        temp, i = divisor, 1
        while dividend >= temp:
            dividend -= temp
            answer += i
            i <<= 1
            temp <<= 1

    if not isPositive:
        answer = -answer

    return answer


def test():

    testCases = [[9, 4], [-10, 3], [103, -10], [-9, -4], [0, -3], [2, 0]]

    for test in testCases:
        print("{:3} / {:<3} = {:<3}".format(test[0], test[1], divide(test[0], test[1])))


test()
