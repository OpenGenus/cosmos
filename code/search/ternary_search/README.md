# Ternary search
The ternary search algorithm is used for finding a given element in a sorted array.

## Procedure
1. Find where the array divides into two thirds
2. Compare the value of both the thirds elements with the target element.
3. If they match, it is returned the index. 
4. If the value is less than the first third, the search continues in the leftmost third of the array.
5. If the value is greater than the second third, the search continues in the rightmost third of the array.
6. If the value is both greater than the first third and less than the second third, the search continues in the middle third of the array.
5. The same procedure as in step 2-6 continues, but with a part of the array. This continues until the given element is found or until there are no elements left. 

Collaborative effort by [OpenGenus](https://github.com/OpenGenus)
