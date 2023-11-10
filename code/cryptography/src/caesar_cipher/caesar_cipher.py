MAX_KEY_SIZE = 26

# Mode to select (e)ncryption or (d)ecryption
def get_mode():
    while True:
        print("Do you wish to encrypt or decrypt a message?")
        mode = input().lower()
        if mode in "encrypt e decrypt d".split():
            return mode
        else:
            print('Enter either "encrypt" or "e" or "decrypt" or "d".')


# Gets message from the user
def get_message():
    print("Enter your message:")
    return input()


# Gets key from the user
def get_key():
    key = 0
    while key < 1 or key > MAX_KEY_SIZE:
        print("Enter the key number (1-%s)" % (MAX_KEY_SIZE))
        key = int(input())
    return key


# Translation logic here
def get_translated_message(mode, message, key):
    if mode[0] == "d":
        key = -key
    translated = ""
    for symbol in message:
        if symbol.isalpha():
            num = ord(symbol)
            num += key
            if symbol.isupper():
                if num > ord("Z"):
                    num -= 26
                elif num < ord("A"):
                    num += 26
            elif symbol.islower():
                if num > ord("z"):
                    num -= 26
                elif num < ord("a"):
                    num += 26
            translated += chr(num)
        else:
            translated += symbol
    return translated


mode = get_mode()
message = get_message()
key = get_key()

print("Your translated text is:")
print(get_translated_message(mode, message, key))
