def main():
    n = 2000000
    sum = 0
    prime = [True] * n

    for p in range(2, n):
        if prime[p]:
            sum += p
            for i in range(p * p, n, p):
                prime[i] = False

    print(sum)


if __name__ == "__main__":
    main()
