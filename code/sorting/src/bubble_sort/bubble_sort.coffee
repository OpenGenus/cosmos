Bubble_Sort = (list) ->
  for i in [0...list.length]
    for j in [0...list.length - i]
      [list[j], list[j+1]] = [list[j + 1], list[j]] if list[j] > list[j + 1]
  list

array = [2, 4, 3, 1, 6, 8, 4]
console.log Bubble_Sort array

### Output
[ 1, 2, 3, 4, 4, 6, 8 ]
###
