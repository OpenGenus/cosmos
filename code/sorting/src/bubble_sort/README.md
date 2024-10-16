# Bubble Sort
**Bubble Sort** is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. 
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines. Bubble sort is stable and adaptive in nature.

**Stable :** If any sorting algorithm preserving the order of duplicate elements in the sorted list then that algorithm is called stable.

## Explanation : Why bubble sort algorithm is stable by nature

**Case 1: Sorted by name**

**Name :** A    B    C    D    E    F    G

**Marks:** 5    8    6    4    6    7    10

**Case 2: Sorted by marks**

**Name :** D    A    C    E    F    B     G

**Marks:** 4    5    6    6    7    8    10

In both the cases we have duplicate elements and i.e C and E, but in Case 1 we sort by name and in Case 2 we sort by marks but in both the cases we observe that C comes first and then E. So if duplicate elements exist in the list their order should preserved. Here don't relate order with the index.

**Adaptive :** If any sorting method is taking less time or minimum time over already sorted list then we call that algorithm as adaptive.

## Explanation : Why bubble sort algorithm is adaptive by nature

**Elements :** 2  3  5  7  8

**Bubble sort algorithm** is comparison based algorithm and right now we have sorted list of elements so if you compare the elements you find that 
<br>
2 is less than 3
<br>
3 is less than 5
<br>
5 is less than 7
<br>
7 is less than 8
<br>
so we observe n is less than n+1, so no swaping will take place and if no swaping that means list is already sorted and that's why minimum time complexity of bubble sort algorithm is O(n).

## Explanation 
**First Pass:**
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
<br>
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4.
<br>
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2.
<br>
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
<br>
**Second Pass:**
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
<br>
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
<br>
**Third Pass:**
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

## Algorithm
```
begin BubbleSort(list)

   for unsorted_end in list[n...1]
      for unsorted_beg of list[1...unsorted_end-1]
         if list[unsorted_beg] > list[unsorted_beg+1]
            swap(list[unsorted_beg], list[unsorted_beg+1])
         end if
      end for
   end for
   
   return list
   
end BubbleSort
```
## Implementation in c++
```
void Bubble_Sort(int A[], int n)
{
   int i, j, flag=0;
   for(i=0;i<n-i;i++)
   {
       flag=0;
       for(j=0;j<n-i-1;j++)
       {
           if(A[j]>A[j+1])
	   {
               swap(A[j], A[j+1]);
               flag=1;
           }
       }
       if(flag==0)
          break;
     }
  }
```   
   




## Complexity
**Time complexity**
- Average and worst case: **O(n<sup>2</sup>)**
- Best case: **O(n)**

**Space complexity**: : **O(1)** auxillary

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
