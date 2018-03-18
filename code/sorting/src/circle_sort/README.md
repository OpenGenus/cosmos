# Circle Sort
Circle sort algorithm is an **inplace sorting algorithm** in which we compare the first element to the last element of the given array, the second element to the second last element, and so on and then split the array in two and recurse until we get pairs of sorted elements, which are then put together to get a sorted array.

## Explanation
Circle sort is best explained by drawing concentric circles on an array of integers. 

Now, the elements lying on the same circle (i.e., they are diametrically opposite) are compared and swapped. Then the array is split into two and recurse  until there are no more swaps.

![circle_sort](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/circle_sort_example.png)

> Image credits: geeksforgeeks

## Algorithm

``` 
function inner_circle (index a, index b)
{
   start := a                      
   end := b                       
   swap := 0                           
                                 
   if (start == end) 
      return (swap)

   while (start< end)                                                   
      if (value at start > value at end)                 
           swap.values(start , end)
           swap++
      (end if) 

      start++
      end--

   (end while)                              

   swap += inner_circle (a, end)
   swap += inner_circle (start, b)

   return(swap)                         
}
function circle_sort (index a, n)
{
  while inner_circle (a, a + n - 1)
}
```

## Complexity
The **best case time complexity** of circle sort is:**O(nlogn)**, while in **worst case**, it becomes: **O(nlogn logn)**.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
