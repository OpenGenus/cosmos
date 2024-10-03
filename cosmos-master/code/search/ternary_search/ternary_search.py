def ternarySearch (arr, to_find):
   left = 0
   right = len(arr) - 1
   while left <= right:
      temp2 = left + (right - left) // 3
      temp3 = left + 2 * (right - left) // 3
      if to_find == arr[left]:
         return left
      elif to_find == arr[right]:
         return right
      elif to_find < arr[left] or to_find > arr[right]:
         return -1
      elif to_find <= arr[temp2]:
         right = temp2
      elif to_find > arr[temp2] and to_find <= arr[temp3]:
         left = temp2 + 1
         right = temp3
      else:
         left = temp3 + 1
   return -1


def test(x):
    arr = [6, 18, 47, 85, 44, 15, 97]
    index = ternarySearch(arr, x);

    if index != -1:
        print "The element",x,"is at the index",index
    else:
        print "Element",x,"not found!"
test(18)
