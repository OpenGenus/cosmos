# Number of substrings divisible by 8 but not 3
We are interested to find number of substrings of a given string which are divisible by 8 but not 3.
For example, in "556", possible substrings are "5", "6", "55", "56" and "556". Amongst which only 56 is divisible by 8 and is not divisible by 3. Therefore, answer should be 1

This problem can be solved by first finding all the possible substrings of given string and next counting ones relevant to us but this gives us O(n^2) as time complexity. 

We can use dynamic programming here to get O(n) as time complexity. 

For more explanation, refer to <a href="https://iq.opengenus.org/number-of-substrings-divisible-by-8-but-not-3/">number_of_substring_divisible_by_8_but_not_3</a>
