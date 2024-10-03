# Part of Cosmos by OpenGenus Foundation

proc hamming_distance(x, y: int): int =
    var count = 0
    var t = x xor y

    while t != 0:
        t = t and (t - 1)
        count += 1

    count

assert hamming_distance(0b0, 0b0) == 0
assert hamming_distance(0b0, 0b1) == 1
assert hamming_distance(0b00, 0b11) == 2
assert hamming_distance(0b10101, 0b01010) == 5
