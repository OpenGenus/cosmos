# Merge Sort
The merge sort is a comparison-based sorting algorithm.
This algorithm works by dividing the unsorted list into n sublists; each one containing one element (which
is considered sorted, since it only has one element).

Then it merges the sublists to produce new sorted sublists, this is repeated until there's only one sublist remaining, which is the resulting sorted list.

## Explanation
The following illustrates complete merge sort process for the given array:
 `{38, 27, 43, 3, 9, 82, 10}`

![image](https://www.geeksforgeeks.org/wp-content/uploads/Merge-Sort-Tutorial.png)

> Image credits: geeksforgeeks

## Algorithm
```
procedure mergesort( var a as array )
   if ( n == 1 ) return a

   var l1 as array = a[0] ... a[n/2]
   var l2 as array = a[n/2+1] ... a[n]

   l1 = mergesort( l1 )
   l2 = mergesort( l2 )

   return merge( l1, l2 )
end procedure

procedure merge( var a as array, var b as array )
   var c as array

   while ( a and b have elements )
      if ( a[0] > b[0] )
         add b[0] to the end of c
         remove b[0] from b
      else
         add a[0] to the end of c
         remove a[0] from a
      end if
   end while
   
   while ( a has elements )
      add a[0] to the end of c
      remove a[0] from a
   end while
   
   while ( b has elements )
      add b[0] to the end of c
      remove b[0] from b
   end while
   
   return c
	
end procedure
```

## Complexity
**Time complexity**
Worst, average and best case time complexity: **O(n * logn)**

**Space Complexity**
Auxillary space: **O(n)**

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---