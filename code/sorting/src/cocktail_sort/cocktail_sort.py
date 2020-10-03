# cocktailsort is the function used to sort array
# it is just like bubble sort with less complexity comparatively
def cocktailsort(l):
    # first indicates the first index of the array
    first = 0
    # k is the variable that counts the length of the array
    k = len(l)
    # last indicates the last index element of the array
    last = k - 1
    # t variable is used to denote if array is sorted after the sorting process.
    # it is initialised 1 to check if array is sorted after every iteration
    t = 1
    # temp is used as third variable to exchange the values
    temp = 0
    while t != 0:
        # t is set to 0 when loop conditions comes true
        # both forward and backward sort runs simultaneously
        t = 0
        # this for loop will do the forward sort
        # the greatest element after each pass will be at the last index
        for i in range(first, last, 1):
            if l[i] < l[i + 1]:
                continue
            else:
                temp = l[i]
                l[i] = l[i + 1]
                l[i + 1] = temp
                t = 1
        # t is initialised to 1 to chech if the loop was sorted or not in the forward sort
        # if value of t was not changed the control will jump off the loop
        # else the control will move to the backward sort
        if t == 0:
            break
        else:
            t = 0
            # value of last is decreased everytime that shows the greatest element is found after forward sort
            last -= 1
        # the next loop will do the backward sort in the array
        for i in range(last, first - 1, -1):
            if l[i] < l[i + 1]:
                continue
            else:
                temp = l[i]
                l[i] = l[i + 1]
                l[i + 1] = temp
                # t is set to 1 to show array has completed one backward sort pass.
                t = 1
        # value of first variable is increased everytime as smallest element is found after backward sort
        first += 1
    # when both the sorting is done the array is returned
    return l


# sample array is taken
a = [23, 1, 5, 32, 122, 76, 45]
c = cocktailsort(a)
print("New Array: ")
for i in a:
    print(i, end=" ")
# output-> New Array: 1 5 23 32 45 76 122
