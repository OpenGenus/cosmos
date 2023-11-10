# we define the function
def uniqueNumber(array):
    d = {}
    result = array[0]
    # case multiple elements
    if len(array) > 1:
        for x in array:
            # fill the dictionary in O(n)
            if d.has_key(x):
                d[x] += 1
            else:
                d[x] = 1
    # case 1 element
    else:
        return result
    keys = d.keys()
    # find the result key in O(1/3 * n)
    for k in keys:
        if d.get(k) == 1:
            return k


# asking for the parameters
array_lenght = input("Enter Size of array: ")
variable = []
for i in range(array_lenght):
    array_index = input("Enter element: ")
    variable.append(array_index)

result = uniqueNumber(variable)
# printing result
print(result)
