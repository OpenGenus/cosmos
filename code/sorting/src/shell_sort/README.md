# Shellsort
The Shellsort algorithm is a search algorithm. It's a generalization of the insertion sort that allows the exchange of items that are far apart.

The method starts by sorting pair of elements far apart from each other in the array, then progressively reducing the gap between the elements to be compared.

## Explanation
Consider the following example:

![image1](http://interactivepython.org/runestone/static/pythonds/_images/shellsortA.png)

This list has nine items. If we use an increment of three, there are three sublists, each of which can be sorted by an insertion sort. After completing these sorts, we get the list as shown below. 

![img2](http://interactivepython.org/runestone/static/pythonds/_images/shellsortB.png)

Although this list is not completely sorted, something very interesting has happened. By sorting the sublists, we have moved the items closer to where they actually belong.

Figure below shows a final insertion sort using an increment of one; in other words, a standard insertion sort. Note that by performing the earlier sublist sorts, we have now reduced the total number of shifting operations necessary to put the list in its final order. For this case, we need only four more shifts to complete the process.

![img3](http://interactivepython.org/runestone/static/pythonds/_images/shellsortC.png)

> Image credits: http://interactivepython.org


## Algorithm
```
procedure shellSort()
   A : array of items 
	
   /* calculate interval*/
   while interval < A.length /3 do:
      interval = interval * 3 + 1	    
   end while
   
   while interval > 0 do:

      for outer = interval; outer < A.length; outer ++ do:

      /* select value to be inserted */
      valueToInsert = A[outer]
      inner = outer

         /*shift element towards right*/
         while inner > interval -1 && A[inner - interval] >= valueToInsert do:
            A[inner] = A[inner - interval]
            inner = inner - interval
         end while

      /* insert the number at hole position */
      A[inner] = valueToInsert

      end for

   /* calculate interval*/
   interval = (interval -1)/3  

   end while
   
end procedure
```

## Complexity
**Time complexity**
- Worst Case: **O(n<sup>2</sup>)**
- Average Case: depends on gap sequence
- Best Case: **O(n logn)**

**Space complexity**: **O(n)** total, **O(1)** auxillary

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---