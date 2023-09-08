
# cosmos

Your personal library of every algorithm and data structure code that you will ever encounter

Collaborative effort by [OpenGenus](https://github.com/opengenus)

## Minimum Coins

The **Minimum Coins** tackles the [Change-making problem](https://en.wikipedia.org/wiki/Change-making_problem).

It takes a value V and a set of coin's denomination D.

Supposing we have infinite supply of each denomination, the algorithm returns the minimum set of coins C that makes the value V.

### The algorithm in plain english:

    Assuming the set D is sorted in descending order
    Foreach denomination in D
        While value V is greater than or equal to the current denomination value
            Add the current denomination value to the set of coins C
            Subtract the current denomination value from the value V

### Practical example

    Given V = 98; D = {50, 25, 10, 5, 1} and C = {}
    Loop 0-0:
        V = 48 and C = {50}
    Loop 1-0:
        V = 23 and C = {50, 25}
    Loop 2-0:
        V = 13 and C = {50, 25, 10}
    Loop 2-1:
        V = 3  and C = {50, 25, 10, 10}
    Loop 3-0:
        V = 3  and C = {50, 25, 10, 10}
    Loop 4-0:
        V = 2  and C = {50, 25, 10, 10, 1}
    Loop 4-1:
        V = 1  and C = {50, 25, 10, 10, 1, 1}
    Loop 4-2:
        V = 0  and C = {50, 25, 10, 10, 1, 1, 1}
    END.