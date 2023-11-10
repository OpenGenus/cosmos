# Part of Cosmos by OpenGenus Foundation
def left(i):
    return 2 * i + 1


def right(i):
    return 2 * i + 2


def heapify(a, i):
    l = left(i)
    r = right(i)
    if l < len(a) and a[l] < a[i]:
        smallest = l
    else:
        smallest = i
    if r < len(a) and a[r] < a[smallest]:
        smallest = r
    if smallest != i:
        a[i], a[smallest] = a[smallest], a[i]
        heapify(a, smallest)


def build_min_heap(a):
    for i in range((len(a) - 1) // 2, -1, -1):
        heapify(a, i)


if __name__ == "__main__":
    print("Enter the array of which you want to create a min heap")
    a = [int(x) for x in input().split()]
    build_min_heap(a)
    print("The min heap is -")
    for i in a:
        print(i, end=" ")
    print("")
