# Palindrome Checker

The aim is to find if the string is palindrome or not. The string is taken as input from the user.

## Explaination 

- String= "agaga" : Palindrome = YES #The string agaga is same when read from forward or backward. Hence it is a palindrome
- String= "abccba" : Palindrome = YES
- String= "rotor" : Palindrome = YES
- String= "abbaab" : Palindrome = NO

## Algorithm

Palindrome is defined as a string which reads the same backwards as forwards. If there are odd number of characters in the string, we ignore the middle character and check for palindrome. 

Here, after taking string as an input from the user we keep two pointers. One at the starting of the string and the other at the end. We keep on checking if string[start]==string[end] until start<=end .If not, we break the loop and return No else at the end of the loop we print Yes.


## Complexity 

-O(n) where n is the length of the string
---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
