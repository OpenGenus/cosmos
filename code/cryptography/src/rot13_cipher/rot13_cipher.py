# Part of Cosmos by OpenGenus Foundation
if __name__ == "__main__":
    plaintext = "This is unencrypted sample text"
    ciphertext = ""
    for ch in plaintext:
        ascii_value = ord(ch)
        if ch == " ":
            ciphertext += " "
        elif ascii_value >= 65 and ascii_value <= 90:
            if ascii_value + 13 > 90:
                ciphertext += chr(ascii_value - 13)
            else:
                ciphertext += chr(ascii_value + 13)
        elif ascii_value >= 97 and ascii_value <= 122:
            if ascii_value + 13 > 122:
                ciphertext += chr(ascii_value - 13)
            else:
                ciphertext += chr(ascii_value + 13)
    print(ciphertext)
