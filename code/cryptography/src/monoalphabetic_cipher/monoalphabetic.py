import random
alpha = "abcdefghijklmnopqrstuvwxyz"

#Encrypts the plain text message

def encrypt(original, key=None):

    if key is None:

        l = list(alpha)

        random.shuffle(l)

        key = "".join(l)

        new = []

    for letter in original:

        new.append(key[alpha.index(letter)])

    return ["".join(new), key]

#Decrypts the encrypted message

def decrypt(cipher, key=None):

    if key is not None:

        new = []

        for letter in cipher:

         new.append(alpha[key.index(letter)])

    return "".join(new)

 

e = encrypt('monoalphabetic', None)

print(e) #Prints encrypted message

print(decrypt(e[0], e[1])) #Decodes the message and prints it