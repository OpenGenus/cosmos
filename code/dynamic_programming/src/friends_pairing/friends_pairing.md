
## Friends Pairing

The problem description is as follows :

- Given n friends, each one can remain single or can be paired up with some other friend.

- Each friend can be paired only once

**Objective** : Find out the total number of ways in which friends can remain single or can be paired up.

Example :

```cpp

    Input : n =  3

    Output : 4

    Explanation:

    {1}, {2}, {3} : all single

    {1}, {2, 3} : 2  and  3 paired but 1 is single.

    {1, 2}, {3} : 1  and  2 are paired but 3 is single.

    {1, 3}, {2} : 1  and  3 are paired but 2 is single.

    Note that {1, 2} and {2, 1} are considered same.

```

Solution :

- For n-th person there are two choices:

	- n-th person remains single, we recur for f(n – 1)

	- n-th person pairs up with any of the remaining n – 1 persons.

- So we get (n – 1) * f(n – 2).

- Therefore we can recursively write f(n) as :

``` f(n) = f(n – 1) + (n – 1) * f(n – 2)```

  

### Let's go through the code block by block!

  

``` int table[n+1];```

Creates an array of size **n+1** i.e from 0 to n.

```cpp

    for(int i =  0; i <= n; ++i)

    {

    if(i <=  2)

    table[i] = i;

    else

    table[i] = table[i-1] + (i-1) * table[i-2];

    }

```

Iterate through the array from 0 to n (both inclusive) and apply the formula : ``` f(n) = f(n – 1) + (n – 1) * f(n – 2)```