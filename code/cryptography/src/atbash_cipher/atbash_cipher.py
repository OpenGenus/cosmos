# Programmer: Shlok Gilda
# Updated: 18/1/2018
# Part of Cosmos by OpenGenus Foundation
def atbash(plain):
    cipher = list(plain)
    for i, c in enumerate(plain):
        if ord(c) in range(ord('a'), ord('z') + 1):
            cipher[i] = chr(ord('a') + ord('z') - ord(c))
    return ''.join(cipher)

if __name__ == '__main__':
    import sys
    print atbash(sys.argv[1])
