# the function taxi_cab_numbers generates and returns n taxicab numbers along with the number pairs
def taxi_cab_numbers(n):
    gen_num = 0
    v = {}
    c = {}
    i = 0
    while gen_num < n:
        c[i] = i * i * i
        for j in range(i):
            s = c[j] + c[i]
            if s in v:
                gen_num = gen_num + 1
                yield (s, (j, i), v[s])
            v[s] = (j, i)
        i = i + 1


def print_taxi_numbers(n):
    for x in taxi_cab_numbers(n):
        print(x)


if __name__ == "__main__":
    print_taxi_numbers(10)
