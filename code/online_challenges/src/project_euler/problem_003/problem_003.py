def main():
    value = 600851475143
    count = 1
    arr_prime = []
    while True:
        if value == 1:
            break
        if value % count == 0:
            arr_prime.append(count)
            value = value / count
            count = 1
        count += 1
    print(max(arr_prime))

if __name__ == '__main__':
    main()
