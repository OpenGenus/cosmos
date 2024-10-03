"""
Part of Cosmos by OpenGenus Foundation
   Affine Cipher: each alphabet letter is maped by a linear function to its numeric equivalent
   and converted to letter again. 
"""


def encryption(a, b):
    for x in range(26):
        print(chr(x + 65) + ":" + chr((a * x + b) % 26 + 65))


encryption(5, 8)
