def main():
    number = 3
    min = int("1" + ("0" * (number - 1)))
    max = int("9" + ("9" * (number - 1)))
    max_resul = 0
    for i in range(min, max + 1):
        for s in range(min, max + 1):
            resul = i * s
            str_resul = str(resul)
            if len(str_resul) % 2 == 0:
                div_str = int(len(str_resul) / 2)
                init_str = str_resul[:div_str]
                end_str = str_resul[div_str:]
                rev_end_str = end_str[::-1]
                if rev_end_str == init_str:
                    if resul > max_resul:
                        max_resul = resul
    print(max_resul)

if __name__ == '__main__':
    main()
