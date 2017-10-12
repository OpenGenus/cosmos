# Edit Distance

Description
---
In this problem, there are two strings `A` and `B`,
and three operations that can be performed in them:

- Insert a character
- Remove a character
- Replace a character

It is needed to find the minimum number of operations
that need to performed to make `A` and `B` equal.

Solution
---
Let's denote by `m` the lenght of `A` and `n` the length of `B`.
Let's call `f(m, n)` the minimum number of operations to make
`A[0...m-1]` and `B[0...n-1]` equal.

If we compare the last character of both strings,
we will have two possibilities:

- The two characters are equal: then it is not necessary to make
any operation in these characters and we just need to find the
minimum answer between `A[0...m-2]` and `B[0...n-2]`, that is `f(m-1, n-1)`.
- The characters are different: In this case we will need to use
the operations in these characters. As an operation in a string
has an equivalent operation in the other, we can just assume to
operate in one of them, let's say the first. So we have three cases:
- Insert: make the last characters equal by adding `B[n-1]`
to `A` and we can move to find solution between `A[0...m-1]` and `B[0...n-2]`,
that is `f(m, n-1)`.
- Remove: remove `A[m-1]` and find solution between
`A[0...m-2]` and `B[0...n-1]`, that is `f(m-1, n)`.
- Replace: make the last characters equal by making `A[m-1] = B[n-1]`
and then we need to find solution between `A[0...m-2]` and `B[0...n-2]`,
that is `f(m-1, n-1)`.

As we want the mimimum number of operations, we get miminum from
the three possibilities.

So, summarizing it all, we can define the following algorithm:
```
f(m, 0) = m
f(0, n) = n

f(m, n) = f(m-1, n-1) if A[m-1] == B[n-1]
= 1 + min( f(m, n-1), f(m-1, n), f(m-1, n-1) ) otherwise
```

The time and space complexities of this approach are O(m * n), by using
tabulation or memoization to store already computed values of subproblems.

Collaborative effort by [OpenGenus](https://github.com/opengenus)
