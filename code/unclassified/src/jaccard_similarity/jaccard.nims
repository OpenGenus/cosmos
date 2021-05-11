## Calculates Jaccard Similarity
proc jaccardSimilarity[T](setA: set[T], setB: set[T]): float =
    card(setA * setB) / card(setA + setB)

jaccardSimilarity({0, 1, 2, 5, 6}, {0, 2, 3, 5, 7, 9}).echo
