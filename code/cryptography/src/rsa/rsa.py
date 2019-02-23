#!/usr/bin/env python

from Crypto.PublicKey import RSA

# Convert string to number
def strToNum(s):
    return int(s.encode("hex"), 16)


# Convert number to string
def numToStr(n):
    s = "%x" % n
    if len(s) % 2 != 0:
        s = "0" + s
    return s.decode("hex")


# Encrypt s using public key (e,n)
def encrypt(s, e, n):
    return numToStr(pow(strToNum(s), e, n))


# Decrypt s using private key (d,n)
def decrypt(s, d, n):
    return numToStr(pow(strToNum(s), d, n))


# Example
# Generate random key
key = RSA.generate(2048)
n = key.n
d = key.d
e = key.e

# decrypt(encrypt(m)) = m
# Output: Hello world!
print(decrypt(encrypt("Hello world!", e, n), d, n))
