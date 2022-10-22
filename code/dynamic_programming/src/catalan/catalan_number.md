## Catalan Numbers
- If you do not know what **Catalan Numbers** are, please [visit](https://en.wikipedia.org/wiki/Catalan_number) to get an idea about it.
- If you do not know what **dynamic programming** is please [visit](https://iq.opengenus.org/n-th-fibonacci-number-using-dynamic-programming/) to get an idea about it.
### Let's go step by step i.e code block by code block
To get first *n* Catalan numbers, we first create an array of size n
```cpp
    vector<unsigned long int> catalan(n,0);
``` 
The underlying concept for Catalan Numbers is that :
    - $$  C_{n}={\frac {1}{n+1}}{2n \choose n}={\frac {(2n)!}{(n+1)!\,n!}}=\prod \limits _{k=2}^{n}{\frac {n+k}{k}}\qquad {\text{for }}n$$
    - And the initial case is :
        - ```catalan[0] = catalan[1] = 1```
The block of code below does exactly what we discussed above i.e initialise for 0,1 and then iterate from 2 to n and calculate the Catalan Numbers using the concept of $$  C_{n}={\frac {1}{n+1}}{2n \choose n}={\frac {(2n)!}{(n+1)!\,n!}}=\prod \limits _{k=2}^{n}{\frac {n+k}{k}}\qquad {\text{for }}n$$
```cpp 
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] = catalan[i] + catalan[j] * catalan[i - j - 1];
    }
```
- The outer for loop iterates through every number and for each of the numbers we have to calculate it's catalan as : ```cpp catalan[i] = catalan[i] + catalan[j] * catalan[i - j - 1]```, j running from 0 to i-1.
- This is because, ```cpp catalan[i] = (i*catalan[i]) + (catalan[0] * catalan[i - 1]) + (catalan[1] * catalan[i - 2]) + .......... + (catalan[i-1]*catalan[0]) ``` i.e $$C_0=1 \ and \ C_{n+1}=\sum_{i=0}^{n}C_iC_{n-i} \ for \ n\geq 0$$