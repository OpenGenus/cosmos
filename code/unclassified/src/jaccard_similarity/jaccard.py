#!/usr/bin/env python


def jaccard_similarity(x, y):

    intersection_cardinality = len(set.intersection(*[set(x), set(y)]))
    union_cardinality = len(set.union(*[set(x), set(y)]))
    return intersection_cardinality / float(union_cardinality)


print(jaccard_similarity([0, 1, 2, 5, 6], [0, 2, 3, 5, 7, 9]))
