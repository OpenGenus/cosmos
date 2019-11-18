def compute():
    ways = [0] * 201
    ways[0] = 1
    for coin in [1, 2, 5, 10, 20, 50, 100, 200]:
        for i in range(len(ways) - coin):
            ways[i + coin] += ways[i]
    return str(ways[-1])


if __name__ == "__main__":
    print(compute())
