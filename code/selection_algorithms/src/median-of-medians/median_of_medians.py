def select(A, i):
    if len(A) <= 5:
        return sorted(A)[i]
    chunks = [A[i : i + 5] for i in range(0, len(A), 5)]
    medians = [select(chunk, len(chunk) // 2) for chunk in chunks]
    medianOfMedians = select(medians, len(medians) // 2)
    lowerPartition, upperPartition = (
        [a for a in A if a < medianOfMedians],
        [a for a in A if a > medianOfMedians],
    )
    if i == len(lowerPartition):
        return medianOfMedians
    elif i > len(lowerPartition):
        return select(upperPartition, i - len(lowerPartition) - 1)
    else:
        return select(lowerPartition, i)
