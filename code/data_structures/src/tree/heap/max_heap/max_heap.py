# Part of Cosmos by OpenGenus Foundation
def left(i):
    return 2 * i + 1


def right(i):
    return 2 * i + 2


def heapify(a, i):
    l = left(i)
    r = right(i)
    length = len(a)
    if l < length and a[l] > a[i]:
        largest = l
    else:
        largest = i
    if r < length and a[r] > a[largest]:
        largest = r
    if largest != i:
        a[i], a[largest] = a[largest], a[i]
        heapify(a, largest)


def build_max_heap(a):
    for i in range((len(list(a)) - 1) // 2, -1, -1):
        heapify(a, i)


if __name__ == "__main__":
    print("Enter the array of which you want to create a max heap")
    a = [int(x) for x in input().split()]
    build_max_heap(a)
    print("The max heap is -	")
    for i in range(len(a)):
        print(a[i], end=" ")
    print("")
