# Problem Link:

[DYNAMO](https://www.codechef.com/JAN20B/problems/DYNAMO/)

# Description

**This is an interactive problem.**

An N-perfect number is defined as a positive integer with at most N digits (in decimal representation without leading zeros) ― that is, X is an N-perfect number if 0<X<10^N.

Chef has a friend named Dynamo, who is a legendary magician. Chef learned a new magic trick from him and now, he wants to impress his friend Cheffa by showing her the trick:

- First, Cheffa should choose a positive integer N and tell it to Chef.
- Then, Cheffa should choose an N - perfect number A and tell it to Chef, who should then choose a positive integer S and tell it to Cheffa.
- Then, Cheffa and Chef should alternately tell each other four N-perfect numbers B, C, D and E (in this order). Cheffa chooses B and D, while Chef chooses C and E.
- Cheffa will be really impressed if S turns out to be equal to A+B+C+D+E. Otherwise, Cheffa will be angry that Chef was wasting her time with a failed magic trick.

Since Chef is busy in the kitchen, you should perform the magic trick for him and impress Cheffa. The grader is acting as Cheffa and it is trying to make the magic trick fail.

### Interaction

- First, you should read a line containing a single integer T. The description of interaction for T test cases follows.

- For each test case, you should start by reading a line containing a single integer N

  . Then, you should perform the following actions:

  - Read a line containing a single integer A.
  - Print a line containing a single integer S.
  - Read a line containing a single integer B.
  - Print a line containing a single integer C.
  - Read a line containing a single integer D.
  - Print a line containing a single integer E.
  - Finally, you should read a line containing a single integer: 1 if your predicted sum S is correct or −1 if it is incorrect.

Note that when you receive −1 at the end of a test case, you should immediately terminate your program to receive a Wrong Answer verdict; otherwise, you may receive any verdict. Don't forget to flush the output after printing each line!

