/* Part of Cosmos by OpenGenus Foundation */

# Binary search
The binary search algorithm is used for finding an element in a sorted array. It has the average performance O(log n).

## Procedure
    1. Find middle element of the array.
    2. Compare the value of the middle element with the target value.
    3. If they match, it is returned. 
    4. If the value is less or greater than the target, the search continues in the lower or upper half of the array.  
    5. The same procedure as in step 2-4 continues, but with a smaller part of the array. This continues until the target element is found        or until there are no elements left. 

## Algorithm for Binary search

set first = 1, last = N, mid = N/2
  while (item not found and first < last)
  {
  compare search term to item at mid
    if match
      save index
      break
      
    else if
      search term is less than item at mid,
      set last = mid-1
      
    else
      set first = mid+1
      set mid = (first+last)/2
  }
return index of matching item, or -1 if not found

## Collaborative effort by [OpenGenus](https://github.com/opengenus)
