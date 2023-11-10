def main():
    n = 2 ** 1000
    s = list(str(n))
    ans = 0

    for i in s:
        ans += int(i)

    print(ans)


if __name__ == "__main__":
    main()
