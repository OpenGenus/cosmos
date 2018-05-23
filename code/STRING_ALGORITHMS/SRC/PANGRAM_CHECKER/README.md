## PANGRAM
A pangram is a sentence in which every letter of a given alphabet appears at least once. The most famous pangram in the english language is "The quick brown fox jumps over a lazy dog".

_We only try to implement pangram checker algorithms for sentences in english language._

#### Algorithm
1. Set a flag variable and check the input string for every alphabet in the language starting from 'a'.
2. Change the flag variable and add a break statement as soon as the first missing letter is encountered.
3. If every letter is comapared and it's presence evaluated to be true then exit the loop.
4. If the value of flag is unchanged, the sentence is a pangram.
5. Else, the sentence is not a pangram.


#### Complexity
The Time complexity for the above algorithm will be O(n), where n is the length of input string.

