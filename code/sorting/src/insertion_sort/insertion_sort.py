"""
Part of Cosmos by OpenGenus Foundation

Program for InsertionSort sorting
"""


def insertion_sort(L):
    length = len(L)
    for i in range(length):
        key = L[i]
        j = i - 1
        while j >= 0 and key < L[j]:
            L[j + 1] = L[j]
            j -= 1
        L[j + 1] = key
    return L


if __name__ == "__main__":

    # creating a random array of length 100
    L = np.random.random_integers(100, size=(100,)).tolist()
    print("Given array : \n", L)
    print("Sorted array : \n", insertion_sort(L))
