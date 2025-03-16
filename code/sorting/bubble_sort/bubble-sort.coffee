bubbleSort = (array, compare) ->
  # Not an array, empty or array of 1 is already sorted
  return array  if not Array.isArray(array) or array.length < 2
  swap = (array, first, second) ->
    temp = array[first]
    array[first] = array[second]
    array[second] = temp
    array
  
  # Create a compare func if not passed in
  if typeof compare isnt "function"
    compare = (a, b) ->
      (if a > b then 1 else -1)
  i = undefined
  l = undefined
  i = 0
  while i < array.length
    l = i
    swap array, l, l + 1  while l-- and compare(array[l], array[l + 1]) > 0
i++
  array
