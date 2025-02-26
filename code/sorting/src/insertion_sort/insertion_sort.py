"""
Part of Cosmos by OpenGenus Foundation

Program for InsertionSort sorting

L :- List/Array of integers
order :- Sorting Order('asc' for Ascending; 'desc' for Descending)
"""


def insertion_sort(L, order):
    length = len(L)
    if order == 'asc':
        for i in range(length):
            key = L[i]
            j = i - 1
            while j >= 0 and key < L[j]:
                L[j + 1] = L[j]
                j -= 1
            L[j + 1] = key
        return L
    elif order == 'desc':
        for i in range(length):
            key = L[i]
            j = i - 1
            while j >= 0 and key > L[j]:
                L[j + 1] = L[j]
                j -= 1
            L[j + 1] = key
        return L


if __name__ == "__main__":

    # creating a random array of length 100
    L = np.random.random_integers(100, size=(100,)).tolist()
    print("Given array : \n", L)
    print("Sorted array : \n", insertion_sort(L, 'asc'))
