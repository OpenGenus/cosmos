# Programmer: Shlok Gilda
# Updated: 18/1/2018
# Part of Cosmos by OpenGenus Foundation

"""
Function to encode/decode given string.
"""
def cypher(plaintext):
    cipher = list(plaintext)
    for i, c in enumerate(plaintext):
        if ord(c) in range(ord('a'), ord('z') + 1):
            cipher[i] = chr(ord('a') + ord('z') - ord(c))
    return ''.join(cipher)

if __name__ == '__main__':
    import sys
    print cypher(sys.argv[1])
