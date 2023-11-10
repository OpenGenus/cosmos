# dynamic programming | boolean parenthesization | Python
# Part of Cosmos by OpenGenus Foundation

# Dynamic programming implementation of the boolean
# parenthesization problem using 'T' and 'F' as characters
# and '&', '|' and '^' as the operators


def boolean_parenthesization(c, o, n):
    t = [[0 for i in range(n)] for j in range(n)]
    f = [[0 for i in range(n)] for j in range(n)]

    for i in range(n):
        if c[i] == "T":
            t[i][i] = 1
            f[i][i] = 0
        else:
            t[i][i] = 0
            f[i][i] = 1

    for i in range(1, n):
        j, k = 0, i
        while k < n:

            t[j][k] = 0
            f[j][k] = 0

            for a in range(i):
                b = j + a
                d = t[j][b] + f[j][b]
                e = t[b + 1][k] + f[b + 1][k]

                if o[b] == "|":
                    t[j][k] += d * e - f[j][b] * f[b + 1][k]
                    f[j][k] += f[j][b] * f[b + 1][k]
                elif o[b] == "&":
                    t[j][k] += t[j][b] * t[b + 1][k]
                    f[j][k] += d * e - t[j][b] * t[b + 1][k]
                else:
                    t[j][k] += f[j][b] * t[b + 1][k] + t[j][b] * f[b + 1][k]
                    f[j][k] += t[j][b] * t[b + 1][k] + f[j][b] * f[b + 1][k]
            j += 1
            k += 1
    return t[0][n - 1]


def main():
    c = "TFTTF"
    s = "|&|^"
    n = len(c)
    print(boolean_parenthesization(c, s, n))


if __name__ == "__main__":
    main()
