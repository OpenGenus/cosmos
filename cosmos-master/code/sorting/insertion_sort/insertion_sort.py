import random
# Part of Cosmos by OpenGenus Foundation
num_of_nums = 100


# Function to randomly seed an array
def random_array(num):
    array = []  # Define a new array
    for y in range(num):  # Iterate through the array putting random numbers in it
        array.append(random.randint(0, 1000))

    # Return the array
    return array


# Function to insertion sort and return an array
def insertion_sort(array):
    for i in range(len(array)):  # Iterate through the array
        j = i
        while j > 0 and array[j - 1] > array[j]:  # Compare the index and the index before
            array = swap(array, j, j - 1)  # If they're out of order then swap and decrement
            j -= 1

    return array  # Return the array


# Function to swap two elements in an array
def swap(array, i, j):
    placeholder = array[i]
    array[i] = array[j]
    array[j] = placeholder
    return array


if __name__ == '__main__':
    # Insertion sort a new random array
    new_a = insertion_sort(random_array(num_of_nums))

    # Print it
    for x in range(len(new_a)):
        print(new_a[x])
