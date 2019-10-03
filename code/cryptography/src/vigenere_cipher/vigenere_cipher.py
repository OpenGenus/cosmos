def encrypt(key, text):

    alfa = "abcdefghijklmnopqrstuvwxyz"
    msg_to_be_decrypted = text.replace(" ", "")
    msg_to_be_decrypted = msg_to_be_decrypted.lower()
    encrypted = ""

    for i in range(len(msg_to_be_decrypted)):
        letter_in_key = key[i % len(key)]
        shift = (alfa.find(letter_in_key) + 1) % 26
        index_of_letter = alfa.find(msg_to_be_decrypted[i])
        encrypted += alfa[(index_of_letter + shift) % 26]

    return encrypted


def decrypt(key, encrypted):

    alfa = "abcdefghijklmnopqrstuvwxyz"
    decrypted = ""

    for i in range(len(encrypted)):
        letter_in_key = key[i % len(key)]
        shift = (alfa.find(encrypted[i]) - alfa.find(letter_in_key) - 1) % 26
        decrypted += alfa[shift]

    return decrypted


key = "abc"
text = "ZZAla ma kota"
cipher = encrypt(key, text)
print(cipher)
msg = decrypt(key, cipher)
print(msg)
