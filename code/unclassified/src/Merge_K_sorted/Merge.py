
import sys 
from typing import List, Optional 
Matrix = List[List[int]] 
  
  
class MinHeapNode: 
    def __init__(self, el, i, j): 
        self.element = el
        self.i = i
        self.j = j         
  
class MinHeap: 
    def __init__(self, ar: List[MinHeapNode], size: int):
        """

        :type ar: object
        """
        self.heap_size = size 
        self.heap_arr = ar 
        i = (self.heap_size - 1) // 2
        while i >= 0: 
            self.__min_heapify__(i)
            i -= 1
  
    
    def __min_heapify__(self, i):
        l = __left__(i) 
        r = __right__(i) 
        smallest = i 
        if l < self.heap_size and self.heap_arr[l].element < self.heap_arr[i].element: 
            smallest = l 
        if r < self.heap_size and self.heap_arr[r].element < self.heap_arr[smallest].element: 
            smallest = r 
        if smallest != i: 
            __swap__(self.heap_arr, i, smallest) 
            self.__min_heapify__(smallest)
  
    def __get_min__(self) -> Optional:
        if self.heap_size <= 0: 
            print('Heap underflow') 
            return None
        return self.heap_arr[0] 
  
    
    def __replace_min__(self, root):
        self.heap_arr[0] = root 
        self.__min_heapify__(0)
  
  
def __left__(i):
    return 2 * i + 1
  
  
def __right__(i):
    return 2 * i + 2
  
  
def __swap__(arr: List[MinHeapNode], i, j):
    temp = arr[i] 
    arr[i] = arr[j] 
    arr[j] = temp 
  
  
def __merge_k_sorted_arrays__(arr: Matrix, k: int):
    # type: (object, object) -> object
    h_arr = [] 
    result_size = 0
    for i in range(len(arr)): 
        node = MinHeapNode(arr[i][0], i, 1) 
        h_arr.append(node) 
        result_size += len(arr[i]) 
  
    min_heap = MinHeap(h_arr, k) 
    result = [0]*result_size 
    for i in range(result_size): 
        root = min_heap.__get_min__()
        result[i] = root.element 
        if root.j < len(arr[root.i]): 
            root.element = arr[root.i][root.j] 
            root.j += 1
        else: 
            root.element = sys.maxsize 
        min_heap.__replace_min__(root)
    for x in result: 
        print(x, end=' ') 
    print() 
  
  
if __name__ == '__main__': 
    arr = [ 
        [1, 2, 12, 20], 
        [1, 10, 15, 1003], 
        [23, 30, 45, 1500] 
    ] 
    print('Merged Array is:') 
    __merge_k_sorted_arrays__(arr, len(arr))
