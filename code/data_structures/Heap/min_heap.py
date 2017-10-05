# Part of Cosmos by OpenGenus Foundation 
def left(i):
    return 2 * i + 1

def right(i):
    return 2 * i + 2


def min_heapify(a, i):
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
        min_heapify(a, smallest)

def build_min_heap(a):
    for i in range((len(a) - 1) / 2, -1, -1):
        min_heapify(a, i)

print "Enter the array of which you want to create a min heap"
a = map(int, raw_input().split())
build_min_heap(a)
print "The min heap is -"
for i in a:
	print i,
