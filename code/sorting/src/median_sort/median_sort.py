# Part of Cosmos by OpenGenus Foundation
def median_sort(list):
    data = sorted(list)
    n = len(data)
    if n == 0:
        return None
    if n % 2 == 1:
        return data[n // 2]
    else:
        i = n // 2
        return (data[i - 1] + data[i]) / 2


# list = [0,2,3,4,5,6,7,8,9]
# print calculateMedian(list)

# uncomment the above to see how does python median sort works
