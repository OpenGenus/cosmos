# PROBLEM STATEMENT-> You are given an array A of size N and Q queries.(All indexes are 1 based).
# Each query can be of two types
#       1->   1 i  - add 1 to the ith element of the array A
#       2->   2 K  - print the Kth odd number of the array A if it exists, else print -1

def precalculate(n, array):
    buckets = int(math.ceil(math.sqrt(n)))
    total_odds = [0 for i in range(buckets)]

    bucket_size = int(math.ceil(n / buckets))
    for bucket in range(buckets):
        start = bucket * bucket_size
        end = min(n, start + bucket_size)
        for index in range(start, end):
            if array[index] % 2 != 0:
                total_odds[bucket] += 1
    return total_odds,bucket_size


def query_sol(typ, k,total_odds,bucket_size):
    if typ == 1:
        k -= 1
        array[k] += 1

        bucket = k // bucket_size
        if array[k] % 2 != 0:
            total_odds[bucket] += 1
        else:
            total_odds[bucket] += -1

    else:
        cnt = 0
        found_at = -1
        for index, count in enumerate(total_odds):
            cnt += count
            if cnt >= k:

                bucket = index
                start = bucket * bucket_size
                end = min(n, start + bucket_size)

                cnt -= count
                for j in range(start, end):
                    if array[j] % 2 != 0:
                        cnt += 1
                        if cnt == k:
                            found_at = j + 1

                            break
                break
        return found_at

if __name__ == "__main__":
    import math

    n, q = list(map(int, input().strip().split(" ")))
    array = list(map(int, input().strip().split(" ")))

    total_odds,bucket_size = precalculate(n, array)

    for i in range(q):
        typ, k = list(map(int, input().strip().split(" ")))
        if typ==1:
            query_sol(typ, k,total_odds,bucket_size)
        else:
            print(query_sol(typ, k,total_odds,bucket_size))
