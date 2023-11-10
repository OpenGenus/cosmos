from __future__ import print_function

"""
Part of Cosmos by OpenGenus Foundation
"""

matrix = lambda x: list(map(list, zip(*[iter(range(1, x * x + 1))] * x)))
"""
matrix = [
[1, 2, 3, 4, 5],
[6, 7, 8, 9, 10],
[11, 12, 13, 14, 15],
[16, 17, 18, 19, 20],
[21, 22, 23, 24, 25]
]
"""


def main(size):
    a = matrix(size)
    center = int(size / 2)
    r = c = center
    l = 1
    while l <= center:
        while c <= center + l:  # right
            print(a[r][c])
            c += 1
        c -= 1
        r += 1
        while r <= center + l:  # down
            print(a[r][c])
            r += 1
        r -= 1
        c -= 1
        while c >= center - l:  # left
            print(a[r][c])
            c -= 1
        c += 1
        r -= 1
        while r >= center - l:  # up
            print(a[r][c])
            r -= 1
        r += 1
        c += 1
        l += 1
    for i in a[r][c:]:
        print(i)


main(5)
# One can change the size and matrix accordingly
