# Part of Cosmos by OpenGenus Foundation
# Find frequently occuring subsets of items in a set of transactions
# Contributed by: Aditya Lohana (dundermiflin)


import csv
from itertools import combinations, chain
from collections import defaultdict

min_support = 0.1


def csv_to_list(filename):
	"""Function to convert the transaction-dataset into a list of lists
	"""
	with open(filename, 'r') as f:
		reader = csv.reader(f)
		data = list(reader)
		return data


def count_support(transactions):
	"""Function to count the support of each unique item in the dataset
	Returns a dictionary with item names as keys, and support as values
	"""
	sup = defaultdict(int)
	num_transactions = len(transactions)
	for row in transactions:
		for col in row:
			sup[col] += 1
	for item in sup:
		sup[item] /= num_transactions
	return dict(sup)


def join_itemset(a, b):
	"""Function to merge to length-N itemsets with (N-1)-length common prefix
	Returns an itemset of length N+1
	"""
	a = list(a)
	b = list(b)
	x = a[:-1]
	y = b[:-1]
	if x == y:
		x.extend([a[-1], b[-1]])
		return tuple(x)
	return None


def subsets(itemlist):
	"""Function to generate all subsets of a given itemset
	"""
	subs = []
	for i in range(1, len(itemlist)):
		subs.extend(list(set(combinations(itemlist, i))))
	return subs


def frequent_candidates(transactions, candidates):
	"""Function to count support of candidate itemsets,
	and filter out ones which do not meet the criteria.
	Returns a list of frequent itemsets from the candiates,
	and a dictionary containing their support.
	"""
	count = {}
	freq = {}
	for c in candidates:
		count[c] = 0
	for t in transactions:
		for c in candidates:
			if set(c) <= set(t):
				count[c] += 1
	for c in count:
		if count[c] >= min_support * len(transactions):
			freq[c] = count[c] / len(transactions)
	return freq.keys(), freq


def apriori(items, transactions, support):
	"""Apriori algorithm to extract frequent itemsets from a set of transactions.
	Uses anti-montone property for support to prune the search space.
	Returns a dictionary of frequent itemsets as keys and support as values
	"""
	freq = dict()
	# Make 1-itemsets from frequent items
	L = [(item,) for item in items if support[item] > min_support]
	for l in L:
		freq[l] = support[l[0]]    
	while len(L) > 0:
		C = []
		for a in L:
			for b in L:
				if a != b:
					# Build (k+1)-itemsets from two k-itemsets
					c = join_itemset(a, b)
					if c is not None:
						C.append(c)
		for c in C:
			# Application of anti-monotone property.
			# If any subset of an itemset is infrequent, so is the itemset.
			subs = subsets(c)
			# Building candidates for the next iteration
			if not any([s in freq for s in subs]):
				C.remove(c)
		# Add frequent itemsets to dictionary
		L, F = frequent_candidates(transactions, C)
		freq.update(F)

	return dict((frozenset(f), freq[f]) for f in freq)


if __name__ == "__main__":

	data = csv_to_list('dataset.csv')
	support = count_support(data)
	items = support.keys()
	frequency = apriori(items, data, support)
	frequent_itemsets = [frozenset(f) for f in list(frequency.keys())]
	N = len(data)
	print("===== Frequent Itemsets ======")
	for f in frequent_itemsets:
		print("{0}  ({1})".format(tuple(f), int(N*frequency[f])))