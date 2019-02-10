def main():
    list = range(1, 1000)
    nums = []
    for i in list:
        multiploTres = False
        multiploCinco = False
        if i % 3 == 0 and not multiploCinco:
            multiploTres = True
            nums.append(i)
        if i % 5 == 0 and not multiploTres:
            multiploCinco = True
            nums.append(i)
    soma = 0
    for i in nums:
        soma += i
    print(soma)

if __name__ == '__main__':
    main()
