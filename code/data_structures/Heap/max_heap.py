# Part of Cosmos by OpenGenus Foundation 
def left(i):
    return 2 * i + 1

def right(i):
    return 2 * i + 2


def max_heapify(a, i):
    l = left(i)
    r = right(i)
    if l < len(a) and a[l] > a[i]:
        largest = l
    else:
        largest = i
    if r < len(a) and a[r] > a[largest]:
        largest = r
    if largest != i:
        a[i], a[largest] = a[largest], a[i]
        max_heapify(a, largest)

def build_max_heap(a):
    for i in range((len(a) - 1) / 2, -1, -1):
        max_heapify(a, i)

print "Enter the array of which you want to create a max heap"
a = map(int, raw_input().split())
build_max_heap(a)
print "The max heap is -"
for i in a:
    print i,
