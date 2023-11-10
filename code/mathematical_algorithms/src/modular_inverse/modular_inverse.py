def extendedEuclid(a, b):
    if b == 0:
        return (a, 1, 0)

    (_d, _x, _y) = extendedEuclid(b, a % b)
    return (_d, _y, _x - (a // b) * (_y))


def modInverse(num, mod):
    if num < 1 or num >= mod:
        raise Exception("Number should lie between 1 and mod ({})!".format(str(mod)))

    else:
        (d, x, y) = extendedEuclid(num, mod)

        if d == 1:
            while x < 0:
                x += mod
            return x

        else:
            raise Exception(
                "The number ({0}) and mod ({1}) are not coprime!".format(
                    str(num), str(mod)
                )
            )

    return -1


num, mod = list(map(int, input().split()))
res = modInverse(num, mod)

if res == -1:
    raise Exception("Modular inverse couldn't be calculated!")
else:
    print(res)
