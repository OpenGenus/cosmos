# RSA (Rivest–Shamir–Adleman) Cryptosystem

The RSA algorithm is named after Ron Rivest, Adi Shamir and Len Adleman, who invented it in 1977. The basic technique was first discovered in 1973 by Clifford Cocks of CESG (part of the British GCHQ) but this was a secret until 1997.
The RSA cryptosystem is the most widely-used public key cryptography algorithm in the world. It can be used to encrypt a message without the need to exchange a secret key separately.
This algorithm can be used for both public key encryption and digital signatures. Its security is based on the difficulty of factoring large integers.

## What is a Public Key Cryptosystem ?

Suppose a reciever wants to recieve a message from different senders but does not have a secret channel with each one of them, then a public key is created by which encryption function is known by all but the decryption function can only be accesed by the reciever.
Thus there is asymmetry in this cryptosystem and hence the ciphers based on the public key cryptosystems are called asymmetric ciphers.

## Prerequisites

Most encryption in RSA is based heavily on number theory, most of it being abstract algebra. Calculus and trigonometry isn't heavily used. Additionally, other subjects should be understood well; specifically probability (including basic combinatorics), information theory, and asymptotic analysis of algorithms.
One should have a firm grasp on modular arithmetic as it is one of the most important topics in public key cryptography.

## Encryption

Sender A does the following:- 

1. Obtains the recipient B's public key (n, e).
2. Represents the plaintext message as a positive integer m, 1 < m < n [see note 4].
3. Computes the ciphertext c = m<sup>e</sup> mod(n).
4. Sends the ciphertext c to B.

## Decryption

Recipient B does the following:-

1. Uses his private key (n, d) to compute m = c<sup>d</sup> mod(n).
2. Extracts the plaintext from the message representative m.

## Example Problem
Suppose public key: **(1189, 9)**, private key: **249** and plain text: **19** .

### Encryption
C ≡ 19<sup>9</sup> mod 1189.

This is most efficiently calculated using the Repeated Squares Algorithm:

_Step 1_: <br />

C ≡ 19<sup>8+1</sup> mod 1189 <br />
C ≡ (19<sup>8</sup>)(19<sup>1</sup>) mod 1189

_Step 2_: <br />

19<sup>1</sup> ≡ 19 mod 1189 <br />
19<sup>2</sup> ≡ 19<sup>2</sup> = 361 mod 1189 <br />
19<sup>4</sup> = (19<sup>2</sup>)<sup>2</sup> ≡ (361)2 = 130321 ≡ 720 mod 1189 <br />
19<sup>8</sup> = (19<sup>4</sup>)<sup>2</sup> ≡ (720)2 = 518400 ≡ 1185 mod 1189 <br />

_Step 3_:

C ≡ (19<sup>8</sup>)(19<sup>1</sup>) mod 1189 <br />
C ≡ (1185)(19) mod 1189 <br />
C ≡ 22515 mod 1189 <br />
C ≡ 1113 mod 1189 <br />

So the ciphertext C is **1113**.

## Summary of RSA
- n = pq, where p and q are distinct primes.
- phi, φ = (p-1)(q-1)
- e < n such that gcd(e, phi)=1
- d = e<sup>-1</sup> mod phi.
- c = m<sup>e</sup> mod n, 1<m<n.
- m = c<sup>d</sup> mod n.


## Sources and more detailed information:

- https://en.wikipedia.org/wiki/RSA_(cryptosystem)
- https://www.di-mgt.com.au/rsa_alg.html

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
