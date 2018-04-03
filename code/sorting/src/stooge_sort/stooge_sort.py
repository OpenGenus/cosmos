#!/usr/bin/env python2
# Part of Cosmos by OpenGenus Foundation
def stooge_sort(a):
    def sort(left, right):
        if a[left] > a[right]:
            a[left], a[right] = a[right], a[left]

        if right - left > 1:
            third = (right - left + 1) // 3
            sort(left, right - third)
            sort(left + third, right)
            sort(left, right - third)

    sort(0, len(a) - 1)


l = [4, 7, 2, 8, 1, 9, 3]
stooge_sort(l)
print(", ".join(str(x) for x in l))
