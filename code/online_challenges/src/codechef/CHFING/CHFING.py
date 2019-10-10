num = 1000000007

# For detailed explanation of the problem,
# refer: https://discuss.codechef.com/problems/CHFING

# The sum of elements of an arithmetic progression or AP
sum_ap = lambda a, n, d: ((n * (2 * a + (n - 1) * d)) // 2)

for t in range(int(input())):

    # input
    n, k = map(int, input().split())

    # possible number of terms in AP
    j = (k + n - 2) // (n - 1)

    # The number of terms in AP can either be j or j+1,
    # so select the maximum sum of the 2
    print(
        max(
            sum_ap(k - 1, j, 1 - n),
            sum_ap(k - 1, j + 1, 1 - n),
        )
        % num
    )
