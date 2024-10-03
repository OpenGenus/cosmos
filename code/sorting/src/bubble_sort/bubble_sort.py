# Part of Cosmos by OpenGenus Foundation
# Bubble Sort function takes 2 arguements- 
# arr - Array of numbers
# order - Sorting order (Ascending/Descending)
# To sort array in ascending order: order = 'asc'
# To sort array in descending order: order = 'desc'

def bubble_sort(arr, order):
    """
    >>> arr = [5, 1, 3, 9, 2]
    >>> bubble_sort(arr, 'asc')
    >>> arr
    [1, 2, 3, 5, 9]
    """
    if order == 'asc':
        for i in range(len(arr)):
           # Terminate algorithm if no more swaps are to be carried out
           is_sorted = True 
           for j in range(i + 1, len(arr)):
               # If current(ith) element is greater than the next((i+1)th) element swap them
               if arr[i] > arr[j]:
                  arr[i], arr[j] = arr[j], arr[i]
                  is_sorted = False
           if is_sorted:
               break
                
    elif order == 'desc':
            for i in range(len(arr)):
               # Terminate algorithm if no more swaps are to be carried out
               is_sorted = True 
               for j in range(i + 1, len(arr)):
                   # If current(ith) element is lesser than the next((i+1)th) element swap them
                   if arr[i] < arr[j]:
                      arr[i], arr[j] = arr[j], arr[i]
                      is_sorted = False
               if is_sorted:
                   break


# Less elegant solution, but easier to follow along:
def bubble_sort(alist, order):
    if order == 'asc':
        # flag to keep track of whether the list is sorted or not, initially it is set as false
        is_sorted = False
        # keep comparing till the list is sorted
        while not is_sorted:
            num_swaps = 0
            # iterate through all the elements(except the last) in the list
            for i in range(len(alist) - 1):
                # if the current element is greater than the next element, pop it out of the list 
                if alist[i] > alist[i + 1]:
                    a = alist.pop(i + 1)
                    # insert the popped element to its right position in the list
                    alist.insert(i, a)
                    num_swaps += 1
            # if the list is sorted, no more swaps are carried out
            if num_swaps == 0:
                is_sorted = True
        return alist
    
    elif order == 'desc':
        # flag to keep track of whether the list is sorted or not, initially it is set as false
        is_sorted = False
        # keep comparing till the list is sorted
        while not is_sorted:
            num_swaps = 0
            # iterate through all the elements(except the last) in the list
            for i in range(len(alist) - 1):
                # if the current element is lesser than the next element, pop it out of the list 
                if alist[i] < alist[i + 1]:
                    a = alist.pop(i + 1)
                    # insert the popped element to its right position in the list
                    alist.insert(i, a)
                    num_swaps += 1
            # if the list is sorted, no more swaps are carried out
            if num_swaps == 0:
                is_sorted = True
        return alist
