# Problem Link:
[Modified_Kaprekar_Numbers](https://www.hackerrank.com/challenges/kaprekar-numbers/problem)

# Description
A modified Kaprekar number is a positive whole number with a special property. If you square it, then split the number into two integers and sum those integers, you have the same value you started with.

Consider a positive whole number  with  digits. We square  to arrive at a number that is either 2 * D digits long or (2 * d) - 1 digits long. Split the string representation of the square into two parts, l and r. The right hand part, r must be d digits long. The left is the remaining substring. Convert those two substrings back to integers, add them and see if you get n.

For example, if n = 5, d = 1 then (n)^2 = 25. We split that into two strings and convert them back to integers 2 and 5. We test 2 + 5 =7, so this is not a modified Kaprekar number. If n = 9, still d = 1, and n^2 = 81. This gives us 1 + 8 = 9, the original n.

Note: r may have leading zeros.

Here's an explanation from Wikipedia about the ORIGINAL Kaprekar Number (spot the difference!):