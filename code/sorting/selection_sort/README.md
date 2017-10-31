# Selection Sort
The Selection Sort is a comparison as well as selection sort algorithm. It has an average performance of O(n*n).

## Procedure
1. Run through the list.
2. Select the least/highest element.
3. Add that element in another list which will be sorted.
4. repeat until the unsorted array gets empty.

## Explanation by example
* Input : Random list of integers

   __ 1 4 2 5 3 __
* Output : Input integers in Descending order

   __ 5 4 3 2 1 __

  1. __First pass__:
   Here, algorithm the highest element in the list and appends it to another empty list.

   unsorted list : __ 4 1 2 3 __

   sorted list : __5__

  2. __Second pass__: Similar to the first pass, the algorithm goes through the unsorted list, fetches the highest and moves it to sorted list.

    updated list : __ 2 3 1 __

    sorted list : __5 4__

  3. __Third, Fourth, Fifth pass__: After 3 more iterations through the unsorted list, the length of sorted list becomes 5 and length of unsorted list becomes 0.

  The updated list after 3 more passes would be:

    __5 4 3 2 1__

The algorithms performs worse than insertion sort and is very bad to use when the list length is large.

## Further Reading

1.   [Fun Video Tutorial](https://www.youtube.com/watch?v=Ns4TPTC8whw)

2.   [Some relevant Theory](http://www.geeksforgeeks.org/selection-sort/)

3.   [Know your understanding](http://www.sanfoundry.com/data-structure-questions-answers-selection-sort/)


A large scale collaboration of [OpenGenus](https://github.com/opengenus)
