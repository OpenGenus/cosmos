def sum_binaries(b1: str, b2: str) -> str:
    """
    Short/easy way, using builtins...
    :param b1: first binary
    :param b2: second binary
    :return: binary sum of both binaries
    """
    return bin(int(b1, 2) + int(b2, 2)).lstrip('0b')


def main():
    sum_binaries('10', '1000')
    # Output: 1010

    sum_binaries('1111', '10100')
    # Output: 100011


if __name__ == '__main__':
    main()
