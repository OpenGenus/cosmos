# Part of Cosmos by OpenGenus Foundation
def shell_sort(alist):
    sub_list_count = len(alist) // 2
    while sub_list_count > 0:
        for start in range(sub_list_count):
            gap_insertion_sort(alist, start, sub_list_count)
        sub_list_count = sub_list_count // 2


def gap_insertion_sort(alist, start, gap):
    for i in range(start + gap, len(alist), gap):
        currentvalue = alist[i]
        position = i
        while position >= gap and alist[position - gap] > currentvalue:
            alist[position] = alist[position - gap]
            position = position - gap
        alist[position] = currentvalue


alist = [91, 91, 82, 45, 48, 35, 83, 70, 97]
print("Before: ", alist)
shell_sort(alist)
print("After: ", alist)
