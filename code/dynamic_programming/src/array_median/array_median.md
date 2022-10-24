# Array Median
If you don't know what Median is, please [visit](https://en.wikipedia.org/wiki/Median).
So in precise we can say that the formula for finding Median in an array is :

$$ If\ n\ is\ odd\ ,  median(x) = X_{\frac{n+1}{2}}$$
$$ If\ n\ is\ even\ ,  median(x) =\frac{X_{\frac{n}{2}}+X_{(\frac{n}{2})+1}}{2}$$

The below code block checks if there are even number of elements in array or odd : 
```cpp
    if (n % 2 != 0)
        return (float)arr[n / 2];
```
Otherwise, apply the formula for even number :
```cpp
    return (float)(arr[(n - 1) / 2] + arr[n / 2]) / 2;
```

Time complexity
---------------
Worst case: O(1) Constant Time

Space complexity
----------------
O(1) - Constant Extra Space