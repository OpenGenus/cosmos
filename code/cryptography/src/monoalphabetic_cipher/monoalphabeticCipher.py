keyDict = {}

# Enter a custom map for the monoalphabetic encryption mapping
def create_Map():
    print("Enter the monoalphabetic map as a string(lenght 26)")
    inputMap = input()
    cur = "a"
    curIndex = 0
    while curIndex < 26:
        keyDict[cur] = inputMap[curIndex]
        cur = chr(ord(cur) + 1)
        curIndex += 1


# Return the corresponding decrypted char for a given input char
def get_key(value):
    for key, val in keyDict.items():
        if val == value:
            return key


# Encrypt the input text
def monoalphabetic_encrypt():
    plainText = input("Enter plain text-")
    wordList = plainText.split(" ")
    cipherText = ""
    for word in wordList:
        c = ""
        for i in word:
            i = keyDict[i]
            c += i
        cipherText += c + " "
    cipherText = cipherText[:-1]
    return cipherText


# De-crypt the input text
def monoalphabetic_decrypt():
    cipherText = input("Enter cipher text-")
    wordList = cipherText.split(" ")
    plainText = ""
    for word in wordList:
        c = ""
        for i in word:
            i = get_key(i)
            c += i
        plainText += c + " "
    plainText = plainText[:-1]
    return plainText


create_Map()
print(monoalphabetic_encrypt())
print(monoalphabetic_decrypt())
