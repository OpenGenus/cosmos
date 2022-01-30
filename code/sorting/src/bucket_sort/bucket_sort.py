# Part of Cosmos by OpenGenus Foundation
def bucket_sort(A):
    buckets = [[] for x in range(10)]
    for i, x in enumerate(A):
        buckets[int(x * len(buckets))].append(x)
        out = []
        for buck in buckets:
            out += isort(buck)
        return out


def isort(A):
    if len(A) <= 1:
        return A
    i = 1
    while i < len(A):
        k = A[i]
        j = i - 1
        while j >= 0 and A[j] > k:
            A[j + 1] = A[j]
            A[j] = k
            j -= 1
        i += 1
    return A
