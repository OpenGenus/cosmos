def tiling(n):
    tile = [0 for i in range(n + 1)]

    tile[0] = 1
    tile[1] = 1
    tile[2] = 2
    for i in range(3, n + 1):
        tile[i] = tile[i - 1] + tile[n - 2]

    return tile[n]


if __name__ == "__main__":
    n = 10
    print(tiling(n))
