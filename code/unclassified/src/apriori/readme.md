# cosmos
> Your personal library of every algorithm and data structure code that you will ever encounter

# Apriori Algoithm

The aim is to find items that occur together frequently in a set of transactions using the Apriori algorithm.

## Explanation

Apriori incrementally builds up itemsets by merging smaller itemsets.
Meanwhile, the itemsets which fail to qualify the minimum support criteria are filtered out.
Apriori is used in data mining to extract interesting patterns from data, and to analyse customer behaviour in retail and online stores.

## Time Complexity

N - Number of transactions in dataset
d - Number of unique items
w - Maximum number of items in a transaction

Complexity = O(N\*2<sup>d</sup>\*w)

Apriori prunes the search space to reduce the parameter 2<sup>d</sup> - the number of candidate itemsets.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---