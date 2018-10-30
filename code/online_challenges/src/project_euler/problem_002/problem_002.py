def main():
    # Variables to keep track of Fibonacci numbers
    prev = 1
    forw = 1
    sum = 0
    isFib = True
    while isFib:
        value = prev + forw
        prev = forw
        forw = value
        if value > 4000000:
            isFib = False
        if value % 2 == 0 and isFib:
            sum += value
    print(sum)

if __name__ == '__main__':
    main()
