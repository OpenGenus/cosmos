def compute():
    LIMIT = 28124
    divisorsum = [0] * LIMIT
    for i in range(1, LIMIT):
        for j in range(i * 2, LIMIT, i):
            divisorsum[j] += i
    abundantnums = [i for (i, x) in enumerate(divisorsum) if x > i]

    expressible = [False] * LIMIT
    for i in abundantnums:
        for j in abundantnums:
            if i + j < LIMIT:
                expressible[i + j] = True
            else:
                break

    ans = 0
    for (i, x) in enumerate(expressible):
        if not x:
            ans += i
    return str(ans)


if __name__ == "__main__":
    print(compute())
