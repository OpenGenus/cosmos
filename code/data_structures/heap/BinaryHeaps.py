class Heap:
    # Parent class for MinHeap and MaxHeap
    def get_root(self):
        # Return first element if it exists else inf (MaxHeap) or -inf (MinHeap)
        if self.size > 0:
            return self.array[1]
        else:
            return self.array[0]

    def get_array(self):
        # Return the heap in form of array
        return self.array[1:]

    @staticmethod
    def parent(ind):
        # Calculate parent position for given index
        return ind//2

    @staticmethod
    def child_left(ind):
        # Calculate first child position for given index
        return ind*2

    @staticmethod
    def child_right(ind):
        # Calculate second child position for given index
        return ind*2 + 1

    def is_child_left(self, ind):
        # Check if first child exists
        return self.child_left(ind) < len(self.array)

    def is_child_right(self, ind):
        # Check if second child exists
        return self.child_right(ind) < len(self.array)


class MaxHeap(Heap):
    def __init__(self):
        # Initialize the array with inf for easier comparisons:
        self.array = [float("inf")]
        self.size = 0

    def insert(self, el):
        # Insert new element into heap
        #
        # Start with appending it:
        self.array.append(el)
        self.size += 1
        # Save current index:
        ind = self.size
        # Compare given element with its parent
        # If bigger - swap
        # Else - finish:
        while el > self.array[self.parent(ind)]:
            self.array[ind], self.array[self.parent(ind)] = self.array[self.parent(ind)], self.array[ind]
            ind = self.parent(ind)

    def extract_max(self):
        # Delete biggest element (root) and return it
        #
        # Save the element for return:
        root = self.get_root()
        # Replace it with the last element:
        self.array[1] = self.array.pop()
        self.size -= 1
        # Fix the structure:
        self.max_heapify(1)
        return root

    def max_heapify(self, ind):
        # Recursive method used in extract_max()
        #
        # We need to determine which is the largest element - given parent or one of its children
        largest_ind = ind
        # If left child exists and is larger that its parent:
        if self.is_child_left(ind) and self.array[self.child_left(ind)] > self.array[largest_ind]:
            largest_ind = self.child_left(ind)
        # If right child exists and is larger than its parent and left child:
        if self.is_child_right(ind) and self.array[self.child_right(ind)] > self.array[largest_ind]:
            largest_ind = self.child_right(ind)
        # If parent is not the largest element:
        if largest_ind != ind:
            # Swap parent with bigger child and launch recursion for it:
            self.array[ind], self.array[largest_ind] = self.array[largest_ind], self.array[ind]
            self.max_heapify(largest_ind)


class MinHeap(Heap):
    def __init__(self):
        self.array = [-float("inf")]
        self.size = 0

    def insert(self, el):
        self.array.append(el)
        self.size += 1
        ind = self.size
        while el < self.array[self.parent(ind)]:
            self.array[ind], self.array[self.parent(ind)] = self.array[self.parent(ind)], self.array[ind]
            ind = self.parent(ind)

    def extract_min(self):
        root = self.get_root()
        self.array[1] = self.array.pop()
        self.size -= 1
        self.min_heapify(1)
        return root

    def min_heapify(self, ind):
        smallest_ind = ind
        if self.child_left(ind) <= self.size and self.array[self.child_left(ind)] < self.array[smallest_ind]:
            smallest_ind = self.child_left(ind)
        if self.child_right(ind) <= self.size and self.array[self.child_right(ind)] < self.array[smallest_ind]:
            smallest_ind = self.child_right(ind)
        if smallest_ind != ind:
            self.array[ind], self.array[smallest_ind] = self.array[smallest_ind], self.array[ind]
            self.min_heapify(smallest_ind)
