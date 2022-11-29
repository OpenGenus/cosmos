#!/usr/bin/env python
# Part of Cosmos by OpenGenus Foundation


MOD = 1_000_000_007


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


def exp_by_sqr_mod(base: int, exp: int, mod: int = None) -> int:
    """
    :param return: (base ** exp) % mod
    forall base, exp in N
    """

    if exp == 0: return 1
    if exp == 1: return base
    if base in (0, 1): return base

    init_base = base

    for bit in bin(exp)[3:]:  # loop over bits of exp (ignore the first bit)

        # always square
        if mod is None:
            base *= base
        else:
            base = pow(base, 2, mod)

        if bit == '1':  # somtimes multiply
            if mod is None:
                base *= init_base
            else:
                base = (base * init_base) % mod

    return base


def main():
    base  = int(input("Enter base  : "))
    power = int(input("Enter power : "))
    mod   = int(input("Enter mod   : "))

    print(f"{base}^{power} = {fast_power(base, power) = }")
    print(f"{base}^{power} = {exp_by_sqr_mod(base, power) = }")
    print(f"{base}^{power} mod {mod} = {exp_by_sqr_mod(base, power, mod) = }")


if __name__ == '__main__':
    main()
