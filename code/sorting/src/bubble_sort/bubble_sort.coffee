#Implementation of the Bubble sort algorithm in CoffeeScript
bubbleSort = (list) ->
  for i in [0...list.length]
    for j in [0...list.length - i]
      [list[j], list[j + 1]] = [list[j + 1], list[j]] if list[j] > list[j + 1]
  list

array = [2, 4, 4, 1, 6, 8, 5]
console.log bubbleSort array

### Output
[ 1, 2, 4, 4, 5, 6, 8 ]
###
