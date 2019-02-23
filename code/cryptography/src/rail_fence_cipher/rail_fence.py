string = "Aditya Krishnakumar"
key = 2
mode = 0


def cipher(s, k, m):
    w = len(s)
    h = k
    matrix = [[0 for x in range(w)] for y in range(h)]
    output = []
    replace = []

    def c(string):
        cur_x, cur_y, not_0 = 0, 0, 0
        for char in string:
            matrix[cur_y][cur_x] = char
            cur_x += 1
            if cur_y < h - 1 and not_0 == 0:
                cur_y += 1
            else:
                if cur_y > 0:
                    cur_y -= 1
                    not_0 = 1
                else:
                    cur_y += 1
                    not_0 = 0
        return matrix

    def d(string):
        pointer = 0
        for i in range(len(string)):
            replace.append("r")
        for row in c("".join(replace)):
            for pos, char in enumerate(row):
                if char == "r":
                    row[pos] = list(string)[pointer]
                    pointer += 1
        return matrix

    if m == 0:
        for row in c(string):
            print(row)
            for char in row:
                if char is not 0:
                    output.append(char)
        return "".join(output)
    if m == 1:
        cur_x, cur_y, not_0 = 0, 0, 0
        matrix = d(string)
        for row in matrix:
            print(row)
        while len(output) < len(list(string)):
            output.append(matrix[cur_y][cur_x])
            cur_x += 1
            if cur_y < h - 1 and not_0 == 0:
                cur_y += 1
            else:
                if cur_y > 0:
                    cur_y -= 1
                    not_0 = 1
                else:
                    cur_y += 1
                    not_0 = 0
        return "".join(output)


print(string, "->", cipher(string, key, mode))
