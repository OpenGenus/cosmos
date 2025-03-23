Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence.
Input:
The first line of the input contains an integer T denoting the number of test cases.  For each test case, there is a string s as an input.

Output:
For each test case, the output is a string displaying equivalent mobile numeric keypad sequence. 

Constraints:
1<=T<=100
1<=S<=10^5
'A'<=S[i]<='Z'
Note: Whitespace and alphabets are allowed in uppercase only.  Whitespace is denoted by 0

Example:
Input:
2
GEEKSFORGEEKS
HELLO WORLD
Output:
4333355777733366677743333557777
4433555555666096667775553

Explanation:
For obtaining a number, we need to press a number corresponding to that character for the number of times equal to the position of the character. For example, for character C, we press number 2 three times and accordingly.
Link: https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence/0/?ref=self
