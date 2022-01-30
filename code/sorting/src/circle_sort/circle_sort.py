# Python program to implement circle sort
# Part of Cosmos by OpenGenus Foundation
# function to swap 2 elements of a list
def swap(a, i, j):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp


# recursive function to perfrom circle sort on the given list
def circle_sort(a, lower, upper, swaps):
    # base case
    if lower == upper:
        return swaps

    low = lower
    high = upper
    mid = int((upper - lower) / 2)

    while lower < upper:
        if a[lower] > a[upper]:
            swap(a, lower, upper)
            swaps += 1
            print(a, swaps)

        lower += 1
        upper -= 1

    if lower == upper:
        if a[lower] > a[upper + 1]:
            swap(a, lower, upper + 1)
            swaps += 1
            print(a, swaps)

    circle_sort(a, low, low + mid, swaps)
    circle_sort(a, low + mid + 1, high, swaps)

    return swaps


# hard coded driver function to run the program
if __name__ == "__main__":
    a = [6, 5, 3, 1, 8, 7, 2, 4]
    print("Unsorted List: ", a)
    no_of_swaps = circle_sort(a, 0, len(a) - 1, 0)
    print("Sorted List: ", a)
