# Insertion Sort
**Overview:** Algorithm will construct a sorted array/list of elements one item at a time. With each iteration, the algorithm takes one element from the input data, identifies the ordered location in the new sorted array/list, then inserts the element. This is repeated until all the input data has been orderly inserted into the array/list.

One can consider it as sorting a group of cards. you select each card and insert it to the relevant position.

**Time Complexity:** O(n*n)

## Procedure
1. Run through the list element by element.
2. Compare each element to others to find the apt position.
3. Insert the element at the postion identified.(shift the other element one step right if the position is before some other element)
ps. we do not swap in insertion sort, instead we insert the element and shift other elements.
4. Loop for all elements in the list.

## Explanation by example
* Input : Random list of integers

   __ 1 4 2 5 3 __
* Output : Input integers in Descending order

   __ 5 4 3 2 1 __

  1. __First pass__:
   Here, algorithm compares the first two elements(1 and 4), Since 1 is smaller than 4, move 1 and insert 4 before 1 .

   updated list : __ 4 1 2 5 3 __

  2. __Second pass__: Here, algorithm compares the third element(2) and shifts 2 before 1.

    updated list : __ 4 2 1 5 3 __

  3. __Third pass__: Here, algorithm compares 5 with other elements before it and shifts it to the beginning since it is greated than all the preceding elements.

    updated list :__5 4 2 1 3__

  4. __Fourth pass__: Similarly 3 is compared to the preceding elements and is shifted before 2.

    The updated list after Third pass would be:

One Should go with insertion sort when the list is almost sorted or when the problem size is very small. For reverse orders/random lists, it is not recommended because of the insertion overhead.

## Further Reading
1.   [Fun Video Tutorial](https://www.youtube.com/watch?v=ROalU379l3U)

2.   [Some relevant Theory](https://www.khanacademy.org/computing/computer-science/algorithms/insertion-sort/a/insertion-sort)

3.   [Know your understanding](http://www.geeksforgeeks.org/insertion-sort-time-complexity-question/)


Collaborative effort by [OpenGenus](https://github.com/opengenus)
