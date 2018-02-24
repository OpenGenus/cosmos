# cosmos
> Your personal library of every algorithm and data structure code that you will ever encounter

# Palindrome Checker

The aim is to find if the string is palindrome or not. The string is taken as input from the user.

Palindrome is defined as a string which reads the same backwards as forwards. If there are odd number of characters in the string, we ignore the middle character and check for palindrome. 

Here, after taking string as an input from the user we keep two pointers. One at the starting of the string and the other at the end. We keep on checking if string[start]==string[end] until start<=end .If not, we break the loop and return No else at the end of the loop we print Yes.

# Example 

- String= "agaga" : Palindrome = YES
- String= "abccba" : Palindrome = YES
- String= "rotor" : Palindrome = YES
- String= "abbaab" : Palindrome = NO

#Complexity 

-O(n) where n is the length of the string
---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
