# Cosmos

![Fuzzy search](https://upload.wikimedia.org/wikipedia/commons/6/69/Did_you_mean_andr%C3%A9_emotions.png)
# Fuzzy search  

Fuzzy Search (also referred as fuzzy string searching or approximate string matching) is the technique of finding strings that match a pattern approximately (rather than exactly).
The problem of approximate string matching is typically divided into two sub-problems: finding approximate substring matches inside a given string and finding dictionary strings that match the pattern approximately.

One possible definition of the approximate string matching problem is the following: Given a pattern string P = p1 p2 ... pm and a text string T = t1 t2 ... tn, find a substring T(j -1,j) = Tj-1 ... Tj which, of all substrings of T, has the smallest edit distance to the pattern P.

A brute-force approach would be to compute the edit distance to P for all substrings of T, and then choose the substring with the minimum distance. However, this algorithm would have the running time O(n3 m). 

## Example
The closeness of a match is measured in terms of the number of primitive operations necessary to convert the string into an exact match.
This number is called the edit distance between the string and the pattern. The usual primitive operations are:

  - insertion: cot → coat
  - deletion: coat → cot
  - substitution: coat → cost

## Application
Common applications of approximate matching include spell checking.

[Fuzzy search Wikipedia](https://en.wikipedia.org/wiki/Approximate_string_matching)

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
