# Merge Sort

## Overview

The merge sort is a comparison-based sorting algorithm. It has a usual performance of O(n log n).

This algorithm works by dividing the unsorted list into n sublists; each one containing one element (which
is considered sorted, since it only has one element).

Then it merges the sublists to produce new sorted sublists, this is repeated until there's only one sublist remaining, which is the resulting sorted list.

**Time Complexity:** O(n log(n))

## Procedure
1. Divide the list in halves recursively.
2. Sort the atomic(can't be further divided or dividing won't improve performance) lists individually taking each part as a different list.
3. Merge the sorted lists in the specific order(part of algorithm)
4. Make a single list out of the merged lists.

## Explanation by example
* Input : Random list of integers

   __ 1 4 2 5 3 __
* Output : Input integers in Descending order

   __ 5 4 3 2 1 __

  1. __First step__:
  Divide the list into two halves.

   list 1 : __ 4 1 2 __

   list 2 : __ 5 3 __

   _ Further Divide the lists into two halves._

   For first list, we get:

   list 3 : __ 4 1 __

   list 4 : __ 2 __

   For second list, we get:

   list 5 : __ 5 __

   list 6 : __ 3 __

   _ Divide list one again to get: _

   list 7 : __ 4 __

   list 8 : __ 1 __

   So we have 5 atomic lists to merge now in reverse order of their division.

   **Ps : Order is an important criteria while coding merge sort, if the order goes**

  2. __Remaining steps__: Merge the lists one by one in the order of their breaking/dividing to make a single list.

    Merge elements __ 1 __ and __ 4 __ .

    we get a new updated list:

    __ 1 4 __

    Remaining lists: __2__ , __3__ , __5 __

    Now merge __2__ with the updated list.

    we get : __ 1 2 4 __.

    Now merge __5__ and __3__. we get __3 5__.

    so we have the two initially divided lists in sorted order. just merge the two sorted lists to get the final sorted list.

    __ 5 4 3 2 1 __


One Should go with insertion sort when the list is almost sorted or when the problem size is very small. For reverse orders/random lists, it is not recommended because of the insertion overhead.

## Further Reading

1.   [Fun Video Tutorial](https://www.youtube.com/watch?v=XaqR3G_NVoo)

2.   [Some relevant Theory](http://www.geeksforgeeks.org/merge-sort/)

3.   [Know your understanding](http://www.sanfoundry.com/data-structure-questions-answers-merge-sort/)

4.  [Wikipedia - Merge sort](https://en.wikipedia.org/wiki/Merge_sort)


A large scale collaboration of [OpenGenus](https://github.com/opengenus)
