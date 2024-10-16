# Minimum Number of Operations to Change GCD of given numbers to *k*

GCD refers to the *greatest common factor* of two or more numbers. For ex: GCD of 10, 25 is 5.
We are interested in finding minimum number of operations to change the GCD of given numbers to *k* where an operation could be either an increment or decrement of array element by 1.

The problem could be solved by shifting the array elements to nearest multiple of *k* and changing the minimum value in array to *k*.

The Pseudocode for same will be:
1. Sort the array
2. For i = 1 to n - 1 
3.   No_of_operations += min(arr[i] % k, k - arr[i] % k) 
4. If arr[0] > k, 
5.    No_of_operations += arr[0] - k 
   else
6.    No_of_operations += k - arr[0]

## Complexity 
* Time Comlexity: O(nlogn)
* Space Complexity: O(1)

For more explanations, refer to <a href = "https://iq.opengenus.org/minimum-operations-to-make-gcd-k/">Minimum Number of Operations to Change GCD of given numbers to *k*</a>
