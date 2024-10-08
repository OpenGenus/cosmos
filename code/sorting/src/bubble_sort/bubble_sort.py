# Part of Cosmos by OpenGenus Foundation


def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr


# Example usage
if __name__ == "__main__":
    # Just an example list to test with
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", arr)  # Output: [64, 34, 25, 12, 22, 11, 90]

    # Run the bubble sort
    bubble_sort(arr)

    # Print out the sorted list
    print("Sorted array:", arr)  # Output: [11, 12, 22, 25, 34, 64, 90]
