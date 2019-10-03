# Part of Cosmos by OpenGenus Foundation
def get_palindrome_length(string, index):
    length = 1
    while index + length < len(string) and index - length >= 0:
        if string[index + length] == string[index - length]:
            length += 1
        else:
            break

    return length - 1


def interleave(string):
    ret = []
    for s in string:
        ret.extend(["#", s])
    ret.append("#")

    return "".join(ret)


def manacher(string):
    right = 0
    center = 0
    string = interleave(string)
    P = list(map(lambda e: 0, range(len(string))))

    for i in range(1, len(string)):
        mirror = 2 * center - i
        if i + P[mirror] <= right and mirror >= len(string) - i:
            P[i] = P[mirror]
        else:
            plength = get_palindrome_length(string, i)
            P[i] = plength
            if plength > 1:
                center = int(i)
                right = center + plength

    return [e / 2 for e in P]


def get_palindrome_number(string):
    return sum(manacher(string))
