# ElGamal encryption

# pip install pycryptodome
from Crypto.Util import number

# Key generation algorithm
def elgamal_gen_key(bits):
    # Prime number p
    while True:
        q = number.getPrime(bits - 1)
        p = 2 * q + 1
        if number.isPrime(p):
            break
    # Primitive element g
    while True:
        g = number.getRandomRange(3, p)
        # Primitive element judgment
        if pow(g, 2, p) == 1:
            continue
        if pow(g, q, p) == 1:
            continue
        break
    #  Secret value x
    x = number.getRandomRange(2, p - 1)
    #  Public value y
    y = pow(g, x, p)
    return (p, g, y), x


# Encryption algorithm
def elgamal_encrypt(m, pk):
    p, g, y = pk
    assert 0 <= m < p
    r = number.getRandomRange(2, p - 1)
    c1 = pow(g, r, p)
    c2 = (m * pow(y, r, p)) % p
    return (c1, c2)


# Decryption algorithm
def elgamal_decrypt(c, pk, sk):
    p, g, y = pk
    c1, c2 = c
    return (c2 * pow(c1, p - 1 - sk, p)) % p


pk, sk = elgamal_gen_key(bits=20)
print("pk:", pk)  # Public key
print("sk:", sk)  # Private key
print()

m = 314159  # Plain text
print("m:", m)
c = elgamal_encrypt(m, pk)  # Encryption
print("c:", c)
d = elgamal_decrypt(c, pk, sk)  # Decryption
print("d:", d)
