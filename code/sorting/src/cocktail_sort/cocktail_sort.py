# Python program for implementation of Cocktail Sort 
# Cocktail sort traverses via both the directions alternatively
# It works similar to bubble sort. But takes less iterations/pass.

def cocktailSort(a):
    n = len(a)
    # swapped flag is set to True to enter the while loop
    swapped = True
    # starting index of the list
    start = 0
    # last index in the list
    end = n - 1
    while swapped == True:

        # reset the swapped flag on entering the loop,
        # because it might be true from a previous
        # iteration.
        swapped = False

        # loop from left to right same as the bubble
        # sort
        for i in range(start, end):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                swapped = True
        # if nothing moved, then array is sorted.
        if swapped == False:
            break
        # otherwise, reset the swapped flag so that it
        # can be used in the next stage
        swapped = False

        # move the end point back by one, because
        # item at the end is in its rightful spot
        end = end - 1

        # from right to left, doing the same
        # comparison as in the previous stage
        for i in range(end - 1, start - 1, -1):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                swapped = True
        # increase the starting point, because
        # the last stage would have moved the next
        # smallest number to its rightful spot.
        start = start + 1