# Circle Sort

The **circle sort** algorithm can be visualized by drawing concentric circles on an array of integers. The elements of the array lying on the same circle diametrically opposite to each other are compared and if found in the wrong order they are swapped. This goes on in a recursive fashion in which the array is divided into sub-arrays on which the above process is repeated until we get pairs of sorted elements which when put together form a sorted array.

In short below two steps are repeated while there are swap operations involved in the steps.

*Compare the first element to the last element, then the second element to the second last element, etc.
*Then split the array in two and recurse until there is only one single element in the array.

It can be better explained by the image below

![alt text](http://contribute.geeksforgeeks.org/wp-content/uploads/CircleSort.png "Circle Sorting")

This article is obtained as a reference from [Geeksforgeeks](http://www.geeksforgeeks.org/circle-sort/)
