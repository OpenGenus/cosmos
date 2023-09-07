func reverse(number: int): int =
    var n = number.abs()
    while n > 0:
        let digit = n mod 10
        result = (result * 10) + digit
        n = n div 10
    if number < 0:
        result *= -1

when isMainModule:
    let num = 12345
    assert((reverse num.reverse) == num)

