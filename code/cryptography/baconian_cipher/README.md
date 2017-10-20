# Bacon's Cipher

Bacon's cipher (or Baconian cipher) is actually a form of steganography rather than a cipher. This means that it's a method to hide a message in plain sight. It works by utilizing two different typefaces. One would be 'A', the other 'B'. You then write some text using both typefaces mixed together, following a simple pattern corresponding to each letter of the message you want to hide:

| Letter | Code  | Letter | Code  |
|--------|-------|--------|-------|
| A      | aaaaa | N      | abbab |
| B      | aaaab | O      | abbba |
| C      | aaaba | P      | abbbb |
| D      | aaabb | Q      | baaaa |
| E      | aabaa | R      | baaab |
| F      | aabab | S      | baaba |
| G      | aabba | T      | baabb |
| H      | aabbb | U      | babaa |
| I      | abaaa | V      | babab |
| J      | abaab | W      | babba |
| K      | ababa | X      | babbb |
| L      | ababb | Y      | bbaaa |
| M      | abbaa | Z      | bbaab |

\* There is also another version of this cipher where I and J, and U and V correspond to the same code. This version, where each letter has it's own distinct code, is more popular and is generally the one used in implementations.

For example, "Hello world" would become "AABBBAABAAABABBABABBABBBABABBAABBBABAAABABABBAAABB" (spaces are ignored). If we wanted to hide this in some Lorem Ipsum, making typeface A normal and typeface B bold, it would look like the following:

Lo**rem** ip**s**um d**o**l**or** s**i**t **am**e**t** **co**n**s**e**ct**et**ur** **a**d**i**pis**c**i**n**g **el**it s**ed**

## Sources and more detailed information:

- https://en.wikipedia.org/wiki/Bacon's_cipher
- http://rumkin.com/tools/cipher/baconian.php

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
