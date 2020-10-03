"""

divide conquer | factorial | Python
part of Cosmos by OpenGenus Foundation

"""


def factorial(num):
    """
    Returns the factorial of a given integer num.

    Divide and conquer is used here by organizing the function into a base and recursive case.

    Parameter: num is the number for which the factorial will be found
    Precondition: num is a non-negative integer
    """
    assert (type(num)) == int
    assert num >= 0

    # base case
    if num == 0 or num == 1:
        return 1

    # recursive case
    recursive = factorial(num - 1)

    # output
    return num * recursive
