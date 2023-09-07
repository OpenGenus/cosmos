func average(arr: seq[int]): float =
    for i in arr:
        result += i.float()
    result / arr.len().float()

when isMainModule:
    echo average(@[1, 2, 3, 4, 5])
    echo @[1, 2, 3, 4, 79, 3, 6, 59, 92].average
