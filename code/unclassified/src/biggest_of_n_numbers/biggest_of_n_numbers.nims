## Find Biggest of given sequence of integers using built in proc
proc biggestNum(numbers: seq[int]): int =
  max(numbers)

## Find Biggest of given sequence of integers by iteration
proc biggestNumNative(numbers: seq[int]): int =
  for num in numbers:
    if num > result:
      result = num

## Tests
biggestNum(@[3, 2, 6, 1]).echo # 6 
biggestNum(@[10, 4, 3, 7]).echo # 10

biggestNumNative(@[3, 2, 6, 1]).echo # 6
biggestNumNative(@[10, 4, 3, 7]).echo # 10
