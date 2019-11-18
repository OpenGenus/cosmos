def compute():
    ans = max(range(1, 1000), key=reciprocal_cycle_len)
    return str(ans)


def reciprocal_cycle_len(n):
    seen = {}
    x = 1
    i = 0
    while x not in seen:
        seen[x] = i
        x = x * 10 % n
        i += 1
    return i - seen[x]


if __name__ == "__main__":
    print(compute())
