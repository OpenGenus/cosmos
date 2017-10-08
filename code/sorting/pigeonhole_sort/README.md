# Pigeonhole Sort
The Pigeonhole sort is a sorting algorithm suitable for sorting lists of elements where the number (n) of elements and the length of the range of possible key values (N) are approximately the same. It requires O(n + N) time.

The algorithm works as follows:
1. Given the array; sets up an auxiliary array of initial empty 'pigeonholes', one for each key through the range of the original array.

2. Going over the original array, put each value into the pigeonhole corresponding to it's key, such that each pigeonhole eventually contains a list of all values with that key.

3. Iterate over the pigeonhole array in order, and put the elements from non-empty pigeonholes back into the original array.

## Further Reading
[Wikipedia - Pigeonhole Sort](https://en.wikipedia.org/wiki/Pigeonhole_sort)

A large scale collaboration of [OpenGenus](https://github.com/opengenus)
