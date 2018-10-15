# Caesar Cipher
The Caesar Cipher (also known as shift cipher) is a method of encrypting messages. In this cipher, the original message (plaintext) is replaced with a letter corresponding to the original letter shifted by N places according to the English alphabet. It is therefore a Substitution cipher where letter at ‘L th’ position is shifted to ‘L+N th’ position, where **N is the same** for all the letters.

Using this method, the original message that is understandable to any English speaking user, needs to be deciphered before arriving at context. 


## Example

This example uses a right shift of 3.

```text
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
| | | | | | | | | | | | | | | | | | | | | | | | | |
V V V V V V V V V V V V V V V V V V V V V V V V V V
D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
```
#### Plain text:
I LOVE WORKING ON GITHUB

#### Cipher text:
L ORYH ZRUNLQJ RQ JLWKXE

## Further Reading
[Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher)

#### Fun Trivia:
This cipher is named after Julius Caesar, who used this in his private correspondence.
