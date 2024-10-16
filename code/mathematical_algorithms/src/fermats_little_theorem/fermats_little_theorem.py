import sys
import argparse

# computes (a^b)%m
# fermats little theorem is used assuming m is prime
def power(a, b, m):
    if b == 0:
        return 1

    p = power(a, b // 2, m)
    p = p % m
    p = (p * p) % m

    if b & 1:
        p = (p * a) % m

    return p


def stringToInt(a, m):
    a_mod_m = 0

    for i in range(len(a)):
        a_mod_m = (a_mod_m * 10 % m + int(a[i]) % m) % m

    return a_mod_m


def findPowerModuloP(args):
    cases = args.cases
    p = args.prime or 1000000007

    for case in cases:
        a_str, b_str = case.split(",")
        a = stringToInt(a_str, p)
        b = stringToInt(b_str, p - 1)  # using Fermats little theorem, (a^(p-1))%p = 1

        pow_ab_mod_m = power(a, b, p)

        print("%s^%s modulo %d = %d" % (a_str, b_str, p, pow_ab_mod_m))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "cases", type=str, nargs="+", help="comma seperated values of a and b in a^b"
    )
    parser.add_argument(
        "--prime",
        type=int,
        help="prime number aginst which to take the modulo (default: 1000000007)",
    )
    args = parser.parse_args()

    findPowerModuloP(args)

# Test
# ----------

# python fermats_little.py 3,2 4,5 7,4 34534985349875439875439875349875,93475349759384754395743975349573495  34543987529435983745230948023948,3498573497543987543985743989120393097595572309482304

# output:
# 3^2 modulo 1000000007 = 9
# 4^5 modulo 1000000007 = 1024
# 7^4 modulo 1000000007 = 2401
# 34534985349875439875439875349875^93475349759384754395743975349573495 modulo 1000000007 = 735851262
# 34543987529435983745230948023948^3498573497543987543985743989120393097595572309482304 modulo 1000000007 = 985546465
