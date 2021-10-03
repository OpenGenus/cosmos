<h1> ALL ABOUT BINARY SEARCH </h1>

<h3>Binary search, also known as half-interval search,logarithmic search,binary chop, 
it is a search algorithm that finds the position of a target value within a sorted array.</h3>

 Binary search compares the target value to the middle element of the array. 
 If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, 
 again taking the middle element to compare to the target value, and repeating this until the target value is found. 
 If the search ends with the remaining half being empty, the target is not in the array.

Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
A simple approach is to do a linear search. The time complexity of the above algorithm is O(n). 
Another approach to perform the same task is using Binary Search. 
Binary Search: Search a sorted array by repeatedly dividing the search interval in half. 
Begin with an interval covering the whole array. 
If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. 
Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.

![image](https://user-images.githubusercontent.com/91491296/135704464-c05fe13f-707c-44b0-a265-0ba6bb809a23.png) 
<br>
<br>
<br>
We basically ignore half of the elements just after one comparison.
<br>

<h3>Algorithm</h3><br> 
Binary search works on sorted arrays. Binary search begins by comparing an element in the middle of the array with the target value. <br>
If the target value matches the element, its position in the array is returned.<br>
If the target value is less than the element, the search continues in the lower half of the array. <br>
If the target value is greater than the element, the search continues in the upper half of the array.<br>
By doing this, the algorithm eliminates the half in which the target value cannot lie in each iteration.<br>
<br>

Compare x with the middle element.<br>
If x matches with the middle element, we return the mid index.<br>
Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.<br>
Else (x is smaller) recur for the left half.<br>
<br>
Steps to hit Recursive implementation of Binary Search the problem is:<br><br>
Step 1 - Read the search element from the user.<br>
Step 2 - Find the middle element in the sorted list.<br>
Step 3 - Compare the search element with the middle element in the sorted list.<br>
Step 4 - If both are matched, then display "Given element is found!!!" and terminate the function.<br>
Step 5 - If both are not matched, then check whether the search element is smaller or larger than the middle element.<br>
Step 6 - If the search element is smaller than middle element, repeat steps 2, 3, 4 and 5 for the left sublist of the middle element.<br>
Step 7 - If the search element is larger than middle element, repeat steps 2, 3, 4 and 5 for the right sublist of the middle element.<br>
Step 8 - Repeat the same process until we find the search element in the list or until sublist contains only one element.<br>
Step 9 - If that element also doesn't match with the search element, then display "Element is not found in the list!!!" and terminate the function.<br>
<br>
