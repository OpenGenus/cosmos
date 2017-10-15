# Part of Cosmos by OpenGenus Foundation

MOD = 1000000007


def fast_power(base, power):
    """
    Returns the result of a^b i.e. a**b
    We assume that a >= 1 and b >= 0
    """

    result = 1
    while power > 0:
        # If power is odd
        if power % 2 == 1:
            result = (result * base) % MOD

        # Divide the power by 2
        power = int(power / 2)
        # Multiply base to itself
        base = (base * base) % MOD

    return result


base = int(input("Enter base :"))
power = int(input("Enter power :"))

print(fast_power(base, power))
