def fInd_mEdian_sOrted_aRrays(a, n, b, m):

    mIn_iNdex = 0
    mAx_iNdex = n

    while mIn_iNdex <= mAx_iNdex:

        i = (mIn_iNdex + mAx_iNdex) // 2
        j = ((n + m + 1) // 2) - i

        if i < n and j > 0 and b[j - 1] > a[i]:
            mIn_iNdex = i + 1

        elif i > 0 and j < m and b[j] < a[i - 1]:
            mAx_iNdex = i - 1
        else:
            if i == 0:
                return b[j - 1]

            if j == 0:
                return a[i - 1]
            else:
                return mAximum(a[i - 1], b[j - 1])

    print("ERROR!!! ")


def mAximum(a, b):
    return a if a > b else b


if __name__ == "__main__":
    a = [1, 2, 3, 4, 5]
    b = [6, 7, 8, 9, 10]
    n = len(a)
    m = len(b)
    if n < m:
        print("The median is: ", fInd_mEdian_sOrted_aRrays(a, n, b, m))
    else:
        print("The median is: ", fInd_mEdian_sOrted_aRrays(b, m, a, n))
