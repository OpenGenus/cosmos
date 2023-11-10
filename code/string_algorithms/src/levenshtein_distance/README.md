# Levenshtein Distance

The Levenshtein distance between two strings measures the similarity between them by calculating the **minimum number of one-character insertions, deletions, or substitutions required to change one string into another**. This edit distance is often used in spell chekers, plagiarism detectors, and OCR.

For example, each of these examples have a Levensthein distance of 1 with `cosmos`:
- cosmo**t**s (addition of t in the middle)
- cosmos**k** (addition of k at the end)
- cosms (deletion of o in the middle)
- cosmo (deletion of s at the end)
- cosm**a**s (substitution of o to a)

## Recursive algorithm

Recursively solving this problem is simple, but computationally very inefficient because it recalculates the distance between substrings it has already covered.

Function LevDistance(String S, String T):

1. If either (length of `S`) or (length of `T`) is `0`, return the maximum of (length of `S`) and (length of `T`)
	- This is because the minium edit distance between a nonempty string and an empty string is always the length of the nonempty string
2. Else, return minimum of:
	- LevDistance(`S` without the last character, `T`)
	- LevDistance(`S`, `T` without last character)
	- LevDistance(`S` without the last character, `T` without the last character)

## Iterative matrix algorithm

This algorithm is more efficient than the recursive one because the matrix stores the distance calculations for substrings, saving computational time.

Function LevDistance(String S, String T):

1. Variable `SL` = length of `S` and `TL` = length of `T`
2. Create an empty `matrix` (2d array) of height `SL` and width `TL`
3. Fill the first row with numbers from `0` to `TL`
4. Fill the first column with numbres from `0` to `SL`
5. For each character `s` of `S` (from `i` = `1` to `SL`):
	- For each character `t` of `T` (from `j` = `1` to `TL`):
		- if `s` equals `t`, the `cost` is `0`
		- if `s` does not equal `t`, the `cost` is `1`
		- set `matrix[i][j]` to the minimum of:
			- `matrix[i - 1, j] + 1` (this is for deletion)
			- `matrix[i, j - 1] + 1` (this is for insertion)
			- `matrix[i - 1, j - 1] + cost` (this is for substitution)
6. Return `matrix[SL, TL]`

Each bottom-up dynamic program works by setting each cell's value to the minimum edit distance between the substrings of S and T.

### Example matrix

This is the final Levenshtein distance matrix for the strings "cosmos" and "catmouse". The minimum edit distance is the value in the bottom right corner: 4.

|       |   | c | a | t | m | o | u | s | e |
|-------|---|---|---|---|---|---|---|---|---|
|       | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| **c** | 1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| **o** | 2 | 1 | 1 | 2 | 3 | 3 | 4 | 5 | 6 |
| **s** | 3 | 2 | 2 | 2 | 3 | 4 | 4 | 4 | 5 |
| **m** | 4 | 3 | 3 | 3 | 2 | 3 | 4 | 5 | 5 |
| **o** | 5 | 4 | 4 | 4 | 3 | 2 | 3 | 4 | 5 |
| **s** | 6 | 5 | 5 | 5 | 4 | 3 | 3 | 3 | **4** |

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
