# Part of Cosmos by OpenGenus Foundation
"""
The selection sort algorithm sorts an array by repeatedly finding 
the minimum element (ascending order)/ maximum element (descending order)
from unsorted part and putting it at the beginning. 
The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (ascending order)/ maximum element (descending order)
from the unsorted subarray is picked and moved to the sorted subarray.


Selection Sort function takes 2 arguements- 
array - Array of numbers
order - Sorting order (Ascending/Descending)

To sort array in ascending order: order = 'asc'
To sort array in descending order: order = 'desc'
"""

def selection_sort(array, order):
    if order == 'asc':
        for i in range(len(array) - 1):
            minimumValue = i
            for j in range(i + 1, len(array)):
                if array[j] < array[minimumValue]:
                    minimumValue = j
            temp = array[minimumValue]
            array[minimumValue] = array[i]
            array[i] = temp
        return array
    elif order == 'desc':
        for i in range(len(array) - 1):
            maximumValue = i
            for j in range(i + 1, len(array)):
                if array[j] > array[maximumValue]:
                    maximumValue = j
            temp = array[maximumValue]
            array[maximumValue] = array[i]
            array[i] = temp
        return array
    
"""
>>> arr = [7, 1, 4, 9, 3]	    
>>> selection_sort(arr, 'asc')	    
>>> arr	   
[1, 3, 4, 7, 9]	 
"""
