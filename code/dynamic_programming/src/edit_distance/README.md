# Edit distance

## Description

Edit distance is a way of quantifying how dissimilar two strings (e.g., words) are to one another by counting the minimum number of operations required to transform one string into the other. Edit distances find applications in natural language processing, where automatic spelling correction can determine candidate corrections for a misspelled word by selecting words from a dictionary that have a low distance to the word in question. In bioinformatics, it can be used to quantify the similarity of DNA sequences, which can be viewed as strings of the letters A, C, G and T.

## Example

The Levenshtein distance between "kitten" and "sitting" is 3. A minimal edit script that transforms the former into the latter is:

kitten → sitten (substitution of "s" for "k")

sitten → sittin (substitution of "i" for "e")

sittin → sitting (insertion of "g" at the end).

LCS distance (insertions and deletions only) gives a different distance and minimal edit script:

delete k at 0

insert s at 0

delete e at 4

insert i at 4

insert g at 6

for a total cost/distance of 5 operations.

---

<p align="center">
  A massive collaborative effort by <a href=https://github.com/OpenGenus/cosmos>OpenGenus Foundation</a>
</p>

---
