from pycipher.base import Cipher
import re

####################################################################################
class PolybiusSquare(Cipher):
    """The Polybius square is a simple substitution cipher that outputs 2 characters of ciphertext for each character of plaintext. It has a key consisting
    which depends on 'size'. By default 'size' is 5, and the key is 25 letters (5^2). For a size of 6 a 36 letter key required etc.
    For a more detailed look at how it works see http://www.practicalcryptography.com/ciphers pycipher.polybius-square-cipher/.
    
    :param key: The keysquare, each row one after the other. The key must by size^2 characters in length.
    :param size: The size of the keysquare, if size=5, the keysquare uses 5^2 or 25 characters.
    :param chars: the set of characters to use. By default ABCDE are used, this parameter should have the same length as size.
    """

    def __init__(self, key="phqgiumeaylnofdxkrcvstzwb", size=5, chars=None):
        self.key = "".join([k.upper() for k in key])
        self.chars = chars or "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[:size]
        self.size = size
        assert (
            len(self.key) == size * size
        ), "invalid key in init: must have length size*size, has length " + str(
            len(key)
        )
        assert (
            len(self.chars) == size
        ), "invalid chars in init: must have length=size, has length " + str(len(chars))

    def encipher_char(self, ch):
        row = (int)(self.key.index(ch) / self.size)
        col = self.key.index(ch) % self.size
        return self.chars[row] + self.chars[col]

    def decipher_pair(self, pair):
        row = self.chars.index(pair[0])
        col = self.chars.index(pair[1])
        return self.key[row * self.size + col]

    def encipher(self, string):
        """Encipher string using Polybius square cipher according to initialised key.
        Example::
            ciphertext = Polybius('APCZWRLFBDKOTYUQGENHXMIVS',5,'MKSBU').encipher(plaintext)     
        :param string: The string to encipher.
        :returns: The enciphered string. The ciphertext will be twice the length of the plaintext.
        """
        string = self.remove_punctuation(string)  # ,filter='[^'+self.key+']')
        ret = ""
        for c in range(0, len(string)):
            ret += self.encipher_char(string[c])
        return ret

    def decipher(self, string):
        """Decipher string using Polybius square cipher according to initialised key.
        Example::
            plaintext = Polybius('APCZWRLFBDKOTYUQGENHXMIVS',5,'MKSBU').decipher(ciphertext)     
        :param string: The string to decipher.
        :returns: The deciphered string. The plaintext will be half the length of the ciphertext.
        """
        string = self.remove_punctuation(string)  # ,filter='[^'+self.chars+']')
        ret = ""
        for i in range(0, len(string), 2):
            ret += self.decipher_pair(string[i : i + 2])
        return ret


if __name__ == "__main__":
    print('use "import pycipher" to access functions')
