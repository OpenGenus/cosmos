Binary search is a specialized algorithm.It takes advantage of data that has been sorted in an array or a list.
Binary search is used on sorted arrays,and it more often when used with binary search trees 
There is a dramatic speed enhancement in the runtime as the time complexity of binary search is  O(log(n)),where n is the number of elements being searched.


Algorithm to search an element using Binary Search
1) Compare x with the middle element.
2) If x matches with the middle element, we return the mid index.
3) Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
4) Else (x is smaller) recur for the left half.