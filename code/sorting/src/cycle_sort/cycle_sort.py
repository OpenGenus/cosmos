# Part of Cosmos by OpenGenus Foundation


def cycle_sort(arr):
    writes = 0

    # Loop through the array to find cycles
    for cycle in range(0, len(arr) - 1):
        item = arr[cycle]

        # Find the location to place the item
        pos = cycle
        for i in range(cycle + 1, len(arr)):
            if arr[i] < item:
                pos += 1

        # If item already present, not a cycle
        if pos == cycle:
            continue

        # Else, put the item there or after any of its duplicates
        while item == arr[pos]:
            pos += 1
        arr[pos], item = item, arr[pos]
        writes += 1

        # Rotate the rest of the cycle
        while pos != cycle:

            # Find location to put the item
            pos = cycle
            for i in range(cycle + 1, len(arr)):
                if arr[i] < item:
                    pos += 1

            # Put the item there or after any duplicates
            while item == arr[pos]:
                pos += 1
            arr[pos], item = item, arr[pos]
            writes += 1

    return writes


if __name__ == "__main__":
    arr = [1, 6, 4, 7, 2, 8]
    print("Unsorted Array: ", arr)
    cycle_sort(arr)
    print("Sorted Array:   ", arr)
