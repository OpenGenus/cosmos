def divendo(number):
    min = 1
    max = number
    n = 1
    while True:
        arr_divendo = []
        for i in range(min, max + 1):
            arr_divendo.append(i) if n % i == 0 else None
        if len(arr_divendo) == max:
            num = n
            break
        n += 1
    print(num)

def main():
    divendo(20)

if __name__ == '__main__':
    main()
