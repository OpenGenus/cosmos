# Autobiographical Numbers

### Problem Description:
Given a string, return "true" if it is an autobiographical number or false otherwise.

An Autobiographical Number is a number where each number at a given index represents the number of times it (the index value) appears in the given string.


For example:

- String s = "1000" -> returns false.
s[0] = '1', but 0 appears "three" times in the string - hence it is NOT an autobiographical number.


- String s = 302200 -> returns false.
s[0] = '3' and 0 appears "three" times in the string, so the zero index is valid.
s[1] = '0' and 1 appears "zero" times in the string, so the first index is valid.
s[2] = '2' and 2 appears "two" times in the string, so it is valid.
s[3] = '2', but 3 appears "one" time in the string, so it is NOT valid.
Hence, it returns false.

- String s = 2020 -> returns true
Because the string contains 2 zeroes, 0 ones, 2 twos, and 0 threes.

### Problem Solution approach:
The idea to solve this problem would be:

Let's say the input is a string.

1) Make a hash_table, let's call it indexCounter and initialize an integer index to 0.
Record indexCounter[index] = convertToInteger(currentChar). Repeat for all chars in the string. the index will be incremented by 1 every repetition. 

2) Make another hash table, let's call it eleCounter. This table simply records how many times each element occurs.

3) Loop through each pair of elements present in the indexCounter.
Check if the value at indexCounter for that index and the count of elements for that index (from eleCounter) is the same or not. Even if one value mismatches, return false immediately.

4) if we still make it to the end, return true.

5) See the autobiographical_numbers.cpp file for a in-code example (C++).
