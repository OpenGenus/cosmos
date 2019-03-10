def compute():
    i = 286
    j = 166
    k = 144
    while True:
        triangle = i * (i + 1) // 2
        pentagon = j * (j * 3 - 1) // 2
        hexagon = k * (k * 2 - 1)
        minimum = min(triangle, pentagon, hexagon)
        if minimum == max(triangle, pentagon, hexagon):
            return str(triangle)
        if minimum == triangle:
            i += 1
        if minimum == pentagon:
            j += 1
        if minimum == hexagon:
            k += 1


if __name__ == "__main__":
    print(compute())
