# Atbash Cipher
Atbash cipher is a method of encrypting messages. It is a type of monoalphabetic cipher where every letter in the original message (also known as plaintext) is mapped to it's reverse. The first letter becomes the last, the second letter becomes the second last and so on. In the latin alphabet the mapping would be as follows.

| Plain  | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| ------ |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Cipher | Z | Y | X | W | V | U | T | S | R | Q | P | O | N | M | L | K | J | I | H | G | F | E | D | C | B | A |

_We only try to implement atbash cipher encryption/decryption algorithms for latin alphabet._

#### Algorithm
> For encryption
1. Read the first character of the input string.

2. If it's value is an upper case alphabet then, find out it's distance from 'A' and subtract that from 'Z'. Copy the calculated value to      the corrosponding index in a new character array.

3. If it's value is a lower case alphabet then, repeat the above step with 'a' and 'z'.

4. Else copy the read character unchanged at the corrosponding index in the new character array.

5. Repeat the above steps until you read null from input string.

6. The character array at the end is the encrypted message.

> For decryption.
1. Read the first character of the input string.

2. If it's value is an upper case alphabet then, find out it's distance from 'Z' and subtract that from 'A'. Copy the calculated value to      the corrosponding index in a new character array.

3. If it's value is a lower case alphabet then, repeat the above step with 'z' and 'a'.

4. Else copy the read character unchanged at the corrosponding index in the new character array.

5. Repeat the above steps until you read null from input string.

6. The character array at the end is the decrypted message.



#### Time Complexity
The time complexity for the above algorithm would be O(n), where n is the length of the input string. 
