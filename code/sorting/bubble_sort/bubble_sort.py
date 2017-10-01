'''
  Bubble Sort is the simplest sorting algorithm that works by repeatedly
  swapping the adjacent elements if they are in an incorrect order.

  First Pass:
  ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, the algorithm compares the first two elements, and swaps since 5 > 1.
  ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
  ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
  ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

  Second Pass:
  ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
  ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
  ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
  ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
  Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

  Third Pass:
  ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
  ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
  ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
  ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
'''
def bubble_sort(array):
  for i in range(len(array)):
    for j in range(len(array) - 1):
      if array[j] > array[j+1]:
        array[j], array[j+1] = array[j+1], array[j]

def test_bubble_sort(array):
  bubble_sort(array)
  print(array)

test_bubble_sort([54, 26, 93, 17, 77, 31, 44, 55, 20])
