from pycipher.base import Cipher

####################################################################################
class Porta(Cipher):
    """The Porta Cipher is a polyalphabetic substitution cipher, and has a key consisting of a word e.g. 'FORTIFICATION'.
    
    :param key: The keyword, any word or phrase will do. Must consist of alphabetical characters only, no punctuation of numbers.          
    """

    def __init__(self, key="FORTIFICATION"):
        self.key = [k.upper() for k in key]

    def encipher(self, string):
        """Encipher string using Porta cipher according to initialised key. Punctuation and whitespace
        are removed from the input.       
        Example::
            ciphertext = Porta('HELLO').encipher(plaintext)     
        :param string: The string to encipher.
        :returns: The enciphered string.
        """
        string = self.remove_punctuation(string)
        ret = ""
        for (i, c) in enumerate(string):
            i = i % len(self.key)
            if self.key[i] in "AB":
                ret += "NOPQRSTUVWXYZABCDEFGHIJKLM"[self.a2i(c)]
            elif self.key[i] in "YZ":
                ret += "ZNOPQRSTUVWXYBCDEFGHIJKLMA"[self.a2i(c)]
            elif self.key[i] in "WX":
                ret += "YZNOPQRSTUVWXCDEFGHIJKLMAB"[self.a2i(c)]
            elif self.key[i] in "UV":
                ret += "XYZNOPQRSTUVWDEFGHIJKLMABC"[self.a2i(c)]
            elif self.key[i] in "ST":
                ret += "WXYZNOPQRSTUVEFGHIJKLMABCD"[self.a2i(c)]
            elif self.key[i] in "QR":
                ret += "VWXYZNOPQRSTUFGHIJKLMABCDE"[self.a2i(c)]
            elif self.key[i] in "OP":
                ret += "UVWXYZNOPQRSTGHIJKLMABCDEF"[self.a2i(c)]
            elif self.key[i] in "MN":
                ret += "TUVWXYZNOPQRSHIJKLMABCDEFG"[self.a2i(c)]
            elif self.key[i] in "KL":
                ret += "STUVWXYZNOPQRIJKLMABCDEFGH"[self.a2i(c)]
            elif self.key[i] in "IJ":
                ret += "RSTUVWXYZNOPQJKLMABCDEFGHI"[self.a2i(c)]
            elif self.key[i] in "GH":
                ret += "QRSTUVWXYZNOPKLMABCDEFGHIJ"[self.a2i(c)]
            elif self.key[i] in "EF":
                ret += "PQRSTUVWXYZNOLMABCDEFGHIJK"[self.a2i(c)]
            elif self.key[i] in "CD":
                ret += "OPQRSTUVWXYZNMABCDEFGHIJKL"[self.a2i(c)]
        return ret

    def decipher(self, string):
        """Decipher string using Porta cipher according to initialised key. Punctuation and whitespace
        are removed from the input. For the Porta cipher, enciphering and deciphering are the same operation.
        Example::
            plaintext = Porta('HELLO').decipher(ciphertext)     
        :param string: The string to decipher.
        :returns: The deciphered string.
        """
        return self.encipher(string)


if __name__ == "__main__":
    print('use "import pycipher" to access functions')
