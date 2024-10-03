## Fibonacci Series implemented using dynamic programming
- If you do not know what **Fibonacci Series** is please [visit](https://iq.opengenus.org/calculate-n-fibonacci-number/) to get an idea about it.
- If you do not know what **dynamic programming** is please [visit](https://iq.opengenus.org/introduction-to-dynamic-programming/) to get an idea about it.
### Let's go step by step i.e code block by code block
The underlying concept for finding the factorial of a number *n* is :
    - ```cpp n! = n*(n-1)*(n-2)*......*2*1 ``` for all i>1
    - Which can also be written as ```cpp n! = n*((n-1)!)``` for all i>1
    - And the initial case is :
        - ```cpp 0! = 0 ```  (If you are curious about why this is the case, [checkout](https://iq.opengenus.org/factorial-of-large-numbers/))
        - ```cpp 1! = 1 ```
The block of code below does exactly what we discussed above but using recursion.
```cpp 
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return (n * factorial(n - 1));
```
The main function takes an input for the number *n* and calls the **factorial(n)** function, which has an if condition to check if it's the base condition i.e if *n* is 0 or 1, and return 1, otherwise it returns ```cpp (n * factorial(n - 1))```, which means that it call **factorial(n-1)** and waits for it to return and multiplies this with n and returns **n!**.
The recursion can be explained with the below diagram. 
```cpp
                                    main()
                                     |   ^
                                     V   | (return n*factorial(n-1))
                                factorial(n)
                                     |   ^
                                     V   |  (return (n-1)*factorial(n-2))
                                factorial(n-1)
                                     |   ^
                                     V   |  (return (n-2)*factorial(n-3))
                                factorial(n-2)
                                        .
                                        .
                                        .
                                        .
                                        .
                                        .
                                     |   ^
                                     V   |  (return 2*factorial(1)  = 2 * 1 = 2)
                                factorial(1)
                                ( We know factorial(1) = 1 )
```
