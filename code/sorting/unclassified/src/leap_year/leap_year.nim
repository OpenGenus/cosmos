func find_leap_year(start, last: int): seq[int] =
    for y in start..last:
        if (y mod 4 == 0 and y mod 100 != 0) or (y mod 400 == 0):
            result.add(y)

when isMainModule:
    echo find_leap_year(2000, 2020)
