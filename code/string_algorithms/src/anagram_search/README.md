## Anagram Search 
An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “abcd” and “dabc” are anagram of each other.

![download](https://user-images.githubusercontent.com/29759141/45692328-21a91980-bb78-11e8-90f8-c484de6fc894.png)


### There are two methods used to implement the above algortithms - 

### Method 1 (Use Sorting)   ( used in C program )
- Sort both strings
- Compare the sorted strings

- Time Complexity: Time complexity of this method depends upon the sorting technique used. In the above implementation, quickSort is used which may be O(n^2) in worst case. If we use a O(nLogn) sorting algorithm like merge sort, then the complexity becomes O(nLogn)

### Method 2 (Count characters)   ( used in C++ program )
This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters.
- Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
- Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
- Compare count arrays. If both count arrays are same, then return true.

- Time Complexity - O(n)

### Method 3 (Prime Array Method)   ( used in Ruby program )
- This method takes an array of first 26 prime numbers .Each number representing a-z characters accordingly. 
- The product of numbers corresponding to each alphabet in counted for both of the string.
- If product is equal then the strings are analgrams.

- Time Complexity - O(n)
