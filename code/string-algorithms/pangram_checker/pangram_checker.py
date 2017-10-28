def pangram_checker(text):
    """
    Part of Cosmos by OpenGenus Foundation
    
    Checks if text contains all the letters of the alphabet
    """
    alphabet = [False] * 26;

    # Find which letters are present
    for c in text:
        if c.isalpha():
            c = c.lower()
            c = ord(c) - ord('a')
            alphabet[c] = True

    # Check if all the letters are present
    for letter in alphabet:
        if not letter:
            return False
    
    return True
