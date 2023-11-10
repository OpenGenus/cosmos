class BinaryHeap:
    def __init__(self, size):
        self.List = (size) * [None]
        self.heapSize = 0
        self.maxSize = size

def peek(root):
    if not root:
        return
    else:
        return root.List[1]

def sizeof(root):
    if not root:
        return
    else:
        return root.heapSize

def heapifyTreeInsert(root, index):
    parentIndex = int(index/2)
    if index <= 1:
        return
    if root.List[index] < root.List[parentIndex]:
        temp = root.List[index]
        root.List[index] = root.List[parentIndex]
        root.List[parentIndex] = temp
    heapifyTreeInsert(root, parentIndex)

def insert(root, nodeValue):
    if root.heapSize + 1 == root.maxSize:
        return "The Binary Heap is full."
    root.List[root.heapSize + 1] = nodeValue
    root.heapSize += 1
    heapifyTreeInsert(root, root.heapSize)
    return "The node has been successfully inserted."

def heapifyTreeExtract(root, index):
    leftIndex = index * 2
    rightIndex = index * 2 + 1
    swapChild = 0

    if root.heapSize < leftIndex:
        return
    elif root.heapSize == leftIndex:
        if root.List[index] > root.List[leftIndex]:
            temp = root.List[index]
            root.List[index] = root.List[leftIndex]
            root.List[leftIndex] = temp
        return
        
    else:
        if root.List[leftIndex] < root.List[rightIndex]:
            swapChild = leftIndex
        else:
            swapChild = rightIndex
        if root.List[index] > root.List[swapChild]:
            temp = root.List[index]
            root.List[index] = root.List[swapChild]
            root.List[swapChild] = temp
    heapifyTreeExtract(root, swapChild)

def extract(root):
    if root.heapSize == 0:
        return "The Binary Heap is empty."
    else:
        extractedNode = root.List[1]
        root.List[1] = root.List[root.heapSize]
        root.List[root.heapSize] = None
        root.heapSize -= 1
        heapifyTreeExtract(root, 1)
        return extractedNode

def DisplayHeap(root):
    print(root.List)

B = BinaryHeap(5)
insert(B, 70)
DisplayHeap(B)
insert(B, 40)
DisplayHeap(B)
extract(B)
DisplayHeap(B)
insert(B, 30)
DisplayHeap(B)
insert(B, 60)
DisplayHeap(B)
extract(B)
DisplayHeap(B)
insert(B, 5)
DisplayHeap(B)