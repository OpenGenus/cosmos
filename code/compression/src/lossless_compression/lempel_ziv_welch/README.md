# Lempel-Ziv-Welch compression

The **Lempel-Ziv-Welch** (LZW) algorithm is a dictionary-based lossless compressor. The algorithm uses a dictionary to map a sequence of symbols into codes which take up less space. LZW performs especially well on files with frequent repetitive sequences.

## Encoding algorithm

1. Start with a dictionary of size 256 or 4096 (where the key is an ASCII character and the values are consecutive)
2. Find the longest entry W in the dictionary that matches the subsequent values.
3. Output the index of W and remove W from the input.
4. Add (W + (the next value)) to the dictionary as a key with value (dictionary size + 1)
5. Repeat steps 2 to 4 until the input is empty

**Example:** the input "ToBeOrNotToBeABanana" (length of 20) would be encoded in 17.
```
[T][o][B][e][O][r][N][o][t][To][Be][A][B][a][n][an][a]
 1  2  3  4  5  6  7  8  9  10  11 12 13 14 15  16  17
```
The brackets separate the values (e.g. `[To]` is encoded as one value). The LZW algorithm replaces the second occurences of `To`, `Be`, and `an` with one value, eliminating data redundancy.

Note that there is **no need to store the dictionary** because the LZW uncompression process reconstructs the dictionary as it goes along.

### Encoding example
![Table showing the LZW compression process by character](https://slideplayer.com/slide/5049613/16/images/11/LZW+%E2%80%93+Encoding+Example+T%3Dababcbababaaaaaaa.jpg)

> Image credits: https://slideplayer.com/slide/5049613/

## Decoding algorithm

1. Start with a dictionary of size 256 or 4096 (must be the same as what the encoding process used in step 1)
2. Variable PREV = ""
3. Is the next code V in the dictionary?
    - Yes:
        1. Variable T = dictionary key whose value = V
        2. Output T
        3. Add (PREV + (first character of T)) to the dictionary
    - No:
        1. Variable T = PREV + (first character of PREV)
        2. Output T
        3. Add T to the dictionary
4. Repeat step 3 until the end of the input is reached

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>
---
