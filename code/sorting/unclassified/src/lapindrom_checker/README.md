# cosmos
> Your personal library of every algorithm and data structure code that you will ever encounter

# Lapindrome Checker

The aim is to find if the string is lapindrome or not. The string is taken as input from the user.

Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. 

Here, after taking string as an input from the user we divide it into two parts. If the length is even Part 1 goes from 0 to mid-1 and part goes from mid to end. Else if the string length is odd, we discard the middle character and Part 1 goes from 0 to mid-1 and part goes from mid+1 to end.

Then we sort both the strings and compare them. If they are same, the given string is lapindrome else it is not.

# Example 

- String= "gaga" : Lapindrome = YES
- String= "abccab" : Lapindrome = YES
- String= "rotor" : Lapindrome = YES
- String= "abbaab" : Lapindrome = NO

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
