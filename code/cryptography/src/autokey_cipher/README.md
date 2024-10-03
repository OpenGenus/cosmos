# Auto Key Cipher

Auto Key Cipher is a Symmetric Polyalphabetic Substitution Cipher. This algorithm is about changing plaintext letters based on secret key letters. Each letter of the message is shifted along some alphabet positions. The number of positions is equal to the place in the alphabet of the current key letter.

## How this Algorithm works

Formula used for Encryption:

> Ei = (Pi + Ki) mod 2

Formula used for Decryption:

> Di = (Ei - Ki + 26) mod 26

**Pseudo Code**

1.  Convert the Plain Text or Cipher Text to either Upper or lower(must be in one format).
2.  Encryption:
3.  for 0 to length(text), use above formula for Dncryption,
4.       nextkey = text[i] - 'A';
5.       text[i] = (text[i] - 'A' + keyvalue) % 26 + 'A';
6.  Decryption:
7.  for 0 to length(text), use above formula for Decryption,
8.       result = (text[i] - 'A' - keyvalue) % 26 + 'A';
9.       text[i] = result < 'A' ? (result + 26) : (result);
10. nextkey = text[i] - 'A';
11. Display the Results

<p align="center">
	For more insights, refer to <a href="https://iq.opengenus.org/auto-key-cipher/">Auto Key Cipher</a>
</p>

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/ravireddy07">me</a> at <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
