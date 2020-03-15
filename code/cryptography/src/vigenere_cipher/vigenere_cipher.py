#Method for encryption that takes key and plaintext as arguments
def encrypt(key, text):

    alfa = "abcdefghijklmnopqrstuvwxyz"
    msg_to_be_decrypted = text.replace(" ", "")         #Removes spaces from plaintext
    msg_to_be_decrypted = msg_to_be_decrypted.lower()   #Converts all characters to lowercase
    encrypted = ""

    #Traverses the plaintext
    for i in range(len(msg_to_be_decrypted)):
        letter_in_key = key[i % len(key)]               #Puts the required character of the key in variable letter_in_key
        shift = (alfa.find(letter_in_key) + 1) % 26     #Puts the amount to be shifted in variable shift
        index_of_letter = alfa.find(msg_to_be_decrypted[i])     #Finds the character of plaintext to be encrypted
        encrypted += alfa[(index_of_letter + shift) % 26]

    return encrypted

#Method for encryption that takes key and ciphertext as arguments
def decrypt(key, encrypted):

    alfa = "abcdefghijklmnopqrstuvwxyz"
    decrypted = ""

    #Traverses the ciphertext
    for i in range(len(encrypted)):
        letter_in_key = key[i % len(key)]       #Puts the required character of the key in variable letter_in_key
        shift = (alfa.find(encrypted[i]) - alfa.find(letter_in_key) - 1) % 26    #Puts the amount to be shifted in variable shift
        decrypted += alfa[shift]        #Performs decryption

    return decrypted


key = "abc"
text = "ZZAla ma kota"
cipher = encrypt(key, text)
print(cipher)
msg = decrypt(key, cipher)
print(msg)
