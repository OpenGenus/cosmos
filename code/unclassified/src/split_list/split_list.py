"""
Function script to split a list in n parts
This function can be reused in any project or script.

If you have the following list: [1,2,3,4,5,6,7,8,9,10] and want to break it in
5 parts, you should do:
    >>> new_list = [1,2,3,4,5,6,7,8,9,10]
    >>> print breaker(new_list, 5)

And you should get:
    [[1,2], [3,4], [5,6], [7,8], [9,10]]
"""


def breaker(array, parts):
    return list(
        array[part * len(array) / parts : (part + 1) * len(array) / parts]
        for part in range(parts)
    )
