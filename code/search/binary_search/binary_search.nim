proc binary_search*(collection: seq[int], item: int): int =
  var
    left: int = 0
    right: int = len(collection) - 1
    mid: int = (right + 1) div 2

  while left <= right:
    mid = (left + right) div 2
    if item == collection[mid]:
      # 
      return mid
    elif item > collection[mid]:
      left = mid + 1
    else:
      right = mid - 1

  return -1

echo binary_search(@[1, 2, 3, 4, 5], 4)  # 3
echo binary_search(@[2, 4, 6, 7, 199], 2)  # 0
echo binary_search(@[1, 2, 4, 5, 6], 100)  # -1
