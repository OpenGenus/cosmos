Binary search is a specialized algorithm.It takes advantage of data that has been sorted in an array or a list.
Binary search is used on sorted arrays,and it more often when used with binary search trees 
There is a dramatic speed enhancement in the runtime as the time complexity of binary search is  O(log(n)),where n is the number of elements being searched.


Algorithm to search an element using Binary Search:
0. Start.
1. Sort the given array. Let the array be arr[n], where 'n' is the size of the array.
2. Start with low = 0 and high = n-1, where 'low' and 'high' are the upper bounds of the selected subarray.
3. If low < high 
        go to step 4. 
    Else 
        go to step 9.
4. Find the element present at the middle of the sorted array.  
        mid= low + ( high - low ) / 2
5. Compare x with the middle element.
6. If x matches with the middle element, we return the 'mid' and go to 10. , else go to 7. .
        if(x==arr[mid])
            return mid;
            exit;
7. If x is greater than the middle element, then x can only lie in the right half subarray after the mid element. So we change the subarray to the right half of the    previous array.
        low = mid + 1;
        Repeat the steps starting from 3.
    Else go to 8.
8. If x is smaller than the middle element, then x can only lie in the left half subarray before the mid element. So we change the subarray to the left half of the    previous array.
        high = mid - 1;
        Repeat the steps starting from 3.
9. Print "Target not present".
10. Print "Target found at index " mid.
11. End.
