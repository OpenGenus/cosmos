# Python program to implement circle sort

# function to swap 2 elements of a list
def swap(a, i, j):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp

# recursive function to perfrom circle sort on the given list
def circleSort(a, lower, upper, swaps):
    # base case
    if(lower == upper):
        return swaps

    low = lower
    high = upper
    mid = int((upper-lower)/2)


    while lower<upper:
        if(a[lower] > a[upper]):
            swap(a, lower, upper)
            swaps += 1
            print(a, swaps)

        lower += 1
        upper -= 1

    if (lower == upper):
        if(a[lower] > a[upper+1]):
            swap(a, lower, upper+1)
            swaps += 1
            print(a, swaps)

    circleSort(a, low, low+mid, swaps)
    circleSort(a, low+mid+1, high, swaps)

    return swaps

# hard coded driver function to run the program
def main():
    a = [6,5,3,1,8,7,2,4]
    print("Unsorted List: ", a)
    no_of_swaps = circleSort(a, 0, len(a)-1, 0)
    print("Sorted List: ", a)


# execute isOrdered() function
if __name__ == '__main__':
    main()
