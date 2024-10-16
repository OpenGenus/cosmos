# Problem Link:
[CHFING](https://www.codechef.com/JUNE19A/problems/CHFING/)

# Description

Chef wants to make a feast. In order to do that, he needs a lot of different ingredients. Each ingredient has a certain tastiness; the tastiness of each ingredient may be any positive integer. Initially, for each tastiness between K and K+N−1 (inclusive), Chef has an infinite supply of ingredients with this tastiness.

The ingredients have a special property: any two of them can be mixed to create a new ingredient. If the original ingredients had tastiness x and y (possibly x=y), the new ingredient has tastiness x+y. The ingredients created this way may be used to mix other ingredients as well. Chef is free to mix ingredients in any way he chooses any number of times.

Let's call a tastiness v (v>0) unreachable if there is no way to obtain an ingredient with tastiness v; otherwise, tastiness v is reachable. Chef wants to make ingredients with all reachable values of tastiness and he would like to know the number of unreachable values. Help him solve this problem. Since the answer may be large, compute it modulo 1,000,000,007 (109+7).

Note that there is an infinite number of reachable values of tastiness, but it can be proven that the number of unreachable values is always finite for N≥2.