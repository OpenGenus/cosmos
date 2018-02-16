# Circle Sort
Circle sort algorithm is an **inplace sorting algorithm** in which we compare the first element to the last element of the given array, the second element to the second last element, and so on and then split the array in two and recurse until we get pairs of sorted elements, which are then put together to get a sorted array.

## Example
Circle sort is best explained by drawing concentric circles on an array of integers. 

Now, the elements lying on the same circle (i.e., they are diametrically opposite) are compared and swapped. Then the array is split into two and recurse  until there are no more swaps.

![circle_sort](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/circle_sort_example.png)

> Image credits: geeksforgeeks

## Pseudocode

```int inner_circle (int *a, int *b)
{
  int *start = a;                       
  int *end = b;                       
  int swap = 0;                           
  int temp;                               

  if (start == end) return (0);          
  while (start < end)                   
    {                                  
      if (*start > *end)                 
         {                             
           temp = *start; *start = *end; *end = temp; 
           swap++;
         }                            
      start++; 
      end--;                    
    }                                  

  swap += inner_circle (a, end);
  swap += inner_circle (start, b);

  return(swap);                          
}
void circle_sort (int *a, int n)
{
  while (inner_circle (a, a + n - 1));
}
```

## Time complexity
The **best case time complexity** of circle sort is:**O(nlogn)**, while in **worst case**, it becomes: **O(nlogn logn)**.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---