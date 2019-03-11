import csv
import itertools


def compute():
    ans = 0
    WORDS = read_file()
    for s in WORDS:
        x = sum((ord(c) - ord("A") + 1) for c in s)
        if is_triangular_number(x):
            ans += 1
    return str(ans)


def is_triangular_number(n):
    temp = 0
    for i in itertools.count():
        temp += i
        if n == temp:
            return True
        elif n < temp:
            return False


def read_file():
    file = open("p042_words.txt")
    words = []
    for row in csv.reader(file):
        words = row
    return words


if __name__ == "__main__":
    print(compute())
