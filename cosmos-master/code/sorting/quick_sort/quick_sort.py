def quickSort(arr):
   quickSortHelper(arr,0,len(arr)-1)

def quickSortHelper(arr,first,last):
   if first<last:

       splitpoint = partition(arr,first,last)

       quickSortHelper(arr,first,splitpoint-1)
       quickSortHelper(arr,splitpoint+1,last)


def partition(arr,first,last):
   pivot = arr[first]

   left = first+1
   right = last

   done = False
   while not done:

       while left <= right and arr[left] <= pivot:
           left = left + 1

       while arr[right] >= pivot and right >= left:
           right = right -1

       if right < left:
           done = True
       else:
           temp = arr[left]
           arr[left] = arr[right]
           arr[right] = temp

   temp = arr[first]
   arr[first] = arr[right]
   arr[right] = temp


   return right