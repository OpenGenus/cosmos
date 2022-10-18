## Fibonacci Series implemented using dynamic programming
- If you do not know what **Fibonacci Series** is please [visit](https://en.wikipedia.org/wiki/Fibonacci_number) to get an idea about it.
- If you do not know what **dynamic programming** is please [visit](https://www.geeksforgeeks.org/dynamic-programming/) to get an idea about it.
### Let's go step by step i.e code block by code block
To get first *n* Fibonnaci numbers, we first create an array of size n
```cpp
    int *ans = new int[n + 1];
``` 
Since the underlying concept for Fibonnaci Series is that :
    - ```cpp F[i] = F[i-1] + F[i-2] ``` for all i>1
    - And the initial case is :
        - ```cpp F[0] = 0 ```
        - ```cpp F[1] = 1 ```
The block of code below does exactly what we discussed above i.e initialise for 0,1 and then iterate from 2 to n and calculate the Fibonnaci Series using the concept of ```cpp F[i] = F[i-1] + F[i-2] ``` for all i>1.
```cpp 
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2]; 
    }
```
The main function takes an input for the number *n* i.e the number of first *n* Fibonacci Numbers and calls the **fib()** function to get the array of first *n* Fibonnaci Numbers.