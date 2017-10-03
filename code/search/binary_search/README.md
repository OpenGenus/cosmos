# Binary Search
The binary search algorithm is a search algorithm that finds the position of a given value within a sorted array.

It works by comparing the target value to the middle element of the array; if it's equal then the algorithm is finished, else it discards the half on which the value cannot lie on and applies the same technique to the remaining half, as many times as necessary, until the element is finally located.

### Running Time
| Average-Case Performance | Worst-Case Performance | Best-Case Performance |
|:------------------------:|:----------------------:|:---------------------:|
|         O(log n)         |        O(log n)        |          O(1)         |

### Further Reading
[Wikipedia - Binary Search Algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
