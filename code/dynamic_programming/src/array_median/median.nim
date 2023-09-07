# Part of Cosmos by OpenGenus Foundation

import algorithm

proc median[T](nums: seq[T]): float =
    let numsSorted = sorted(nums)
    let numsLen = len(nums)

    # If the length is odd, the median is the middle value of the sorted list.
    if numsLen %% 2 == 1:
        return numsSorted[(numsLen - 1) div 2].float

    # Otherwise it's the average of the middle two.
    return (numsSorted[numsLen div 2] + numsSorted[(numsLen div 2) - 1]).float / 2.0

assert median(@[0, 5, 99999]) == 5.0
assert median(@[1, 4, 11, 123]) == 7.5
assert median(@[1, 1, 1, 1]) == 1.0
assert median(@[1.5, 3.6, 8.8]) == 3.6
assert median(@[12.34, 56.78, 90.12, 34.56]) == 45.67
