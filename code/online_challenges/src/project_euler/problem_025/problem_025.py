"""

# online challenges | project euler | problem 025 | problem 025 |  PYTHON 
# Part of Cosmos by OpenGenus Foundation

"""


def main(size):
    last, actual = 1, 1
    index = 2

    while actual < size:
        last, actual = actual, last + actual
        index += 1

    print(index)


if __name__ == "__main__":
    main(10 ** 999)
