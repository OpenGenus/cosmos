## Returns average of given sequence of floats
proc average(numbers: seq[float]): float =
  for num in numbers:
    result += num

  result / numbers.len.float

## Test
let numList: seq[float] = @[1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0]
average(numList).echo # 5.5
