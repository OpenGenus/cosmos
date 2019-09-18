def main():
    n = 10001
    x = 2
    list_of_primes = []

    while len(list_of_primes) < n:
        if all(x % prime for prime in list_of_primes):
            list_of_primes.append(x)
        x += 1

    print(list_of_primes[-1])


if __name__ == "__main__":
    main()
