# Part of Cosmos by OpenGenus Foundation


def cipher(plaintext):
    """
    Function to encode/decode given string.
    """
    cipher = list(plaintext)
    for i, c in enumerate(plaintext):
        if ord(c) in range(ord("a"), ord("z") + 1):
            cipher[i] = chr(ord("a") + ord("z") - ord(c))
    return "".join(cipher)


if __name__ == "__main__":
    import sys

    print cipher(sys.argv[1])
