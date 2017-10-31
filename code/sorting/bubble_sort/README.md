# Bubble Sort
The Bubble Sort is a comparison sort algorithm. It has an average performance of O(n*n).

## Procedure
1. Run through the list.
2. Compare each adjacent pair of element
3. Swap elements if not in correct order
4. Repeat until no swap is needed

## Explanation by example
* Input : Random list of integers

   __ 1 4 2 5 3 __
* Output : Input integers in Descending order

   __ 5 4 3 2 1 __

  1. __First pass__:
   Here, algorithm compares the first two elements(1 and 4), and swaps since __4 > 1__.

   updated list : __ 4 1 2 5 3 __

   Now the algorithm compares element 2 and element 3(1 and 2), and swaps since __2 > 1__.

   updated list : __4 2 1 5 3__

   Now the algorithm compares element 3 and element 4(1 and 5), and swaps since __5 > 1__.

   updated list : __4 2 5 1 3__

   Now the algorithm compares element 4 and element 5(1 and 3), and swaps since __3 > 1__.

   updated list : __4 2 5 3 1__

   _so the updated list after first pass would be : _

   __4 2 5 3 1__

  2. __Second pass__: Here, algorithm compares the first two elements again(4 and 2), and doesn't swap since __4 > 2__.

    updated list : __ 4 2 5 3 1 __

    Similarly it does the comparisons as in first pass and the updated list after second pass would be:

    __4 5 3 2 1__

  3. __Third pass__: Here, algorithm compares the elements in the similar fashion as in First pass and Second pass.

  The updated list after Third pass would be:

    __5 4 3 2 1__

The algorithms still runs two more passes to compare all the elements with each other, But it can be optimized such that the algorithm stops when there were no swaps in a pass.

## Further Reading

1.   [Fun Video Tutorial](https://www.youtube.com/watch?v=lyZQPjUT5B4)

2.   [Some relevant Theory](http://blog.benoitvallon.com/sorting-algorithms-in-javascript/the-bubble-sort-algorithm/)

3.   [Know your understanding](http://www.sanfoundry.com/data-structure-questions-answers-bubble-sort/)


Collaborative effort by [OpenGenus](https://github.com/opengenus)
