import sys, pyperclip, cryptomath, random

SYMBOLS = """ !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\] ^_`abcdefghijklmnopqrstuvwxyz{|}~"""  # note the space at the front


def main():
    myMessage = """"A computer would deserve to be called intelligent if it could deceive a human into believing that it was human." -Alan Turing"""
    myKey = 2023
    myMode = "encrypt"  # set to 'encrypt' or 'decrypt'

    if myMode == "encrypt":
        translated = encryptMessage(myKey, myMessage)
    elif myMode == "decrypt":
        translated = decryptMessage(myKey, myMessage)
    print("Key: %s" % (myKey))
    print("%sed text:" % (myMode.title()))
    print(translated)
    pyperclip.copy(translated)
    print("Full %sed text copied to clipboard." % (myMode))


def getKeyParts(key):
    keyA = key // len(SYMBOLS)
    keyB = key % len(SYMBOLS)
    return (keyA, keyB)


def checkKeys(keyA, keyB, mode):
    if keyA == 1 and mode == "encrypt":
        sys.exit(
            "The affine cipher becomes incredibly weak when key A is set to 1. Choose a different key."
        )
    if keyB == 0 and mode == "encrypt":
        sys.exit(
            "The affine cipher becomes incredibly weak when key B is set to 0. Choose a different key."
        )
    if keyA < 0 or keyB < 0 or keyB > len(SYMBOLS) - 1:
        sys.exit(
            "Key A must be greater than 0 and Key B must be between 0 and %s."
            % (len(SYMBOLS) - 1)
        )
    if cryptomath.gcd(keyA, len(SYMBOLS)) != 1:
        sys.exit(
            "Key A (%s) and the symbol set size (%s) are not relatively prime. Choose a different key."
            % (keyA, len(SYMBOLS))
        )


def encryptMessage(key, message):
    keyA, keyB = getKeyParts(key)
    checkKeys(keyA, keyB, "encrypt")
    ciphertext = ""
    for symbol in message:
        if symbol in SYMBOLS:
            # encrypt this symbol
            symIndex = SYMBOLS.find(symbol)
            ciphertext += SYMBOLS[(symIndex * keyA + keyB) % len(SYMBOLS)]
        else:
            ciphertext += symbol  # just append this symbol unencrypted
    return ciphertext


def decryptMessage(key, message):
    keyA, keyB = getKeyParts(key)
    checkKeys(keyA, keyB, "decrypt")
    plaintext = ""
    modInverseOfKeyA = cryptomath.findModInverse(keyA, len(SYMBOLS))

    for symbol in message:
        if symbol in SYMBOLS:
            # decrypt this symbol
            symIndex = SYMBOLS.find(symbol)
            plaintext += SYMBOLS[(symIndex - keyB) * modInverseOfKeyA % len(SYMBOLS)]
        else:
            plaintext += symbol  # just append this symbol undecrypted
    return plaintext


def getRandomKey():
    while True:
        keyA = random.randint(2, len(SYMBOLS))
        keyB = random.randint(2, len(SYMBOLS))
        if cryptomath.gcd(keyA, len(SYMBOLS)) == 1:
            return keyA * len(SYMBOLS) + keyB
