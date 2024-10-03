"""
Following is the implementation of bin sort algorithm.
It will sort the input array with time complexity 0(N + K)
N being the size of array, K being the number of buckets.
Space complexity is at worst O(NK).
"""


def insertion_sort(a):
    """
    :param a: list
        List of objects with an order
    :return: list
        Sorted list with insertion sort algorithm
    """

    for i in range(1, len(a)):
        current_value = a[i]
        position = i

        while position > 0 and a[position - 1] > current_value:
            a[position] = a[position - 1]
            position -= 1
            a[position] = current_value

    return a


def get_buckets(a, bucket_size):
    """
    :param a: list
        List of objects with an order
    :param bucket_size: int
        Size of buckets to fill
    :return: list
        List of buckets to sort array with
    """

    min_v, max_v = min(a), max(a)  # min and max values in array
    bucket_count = (max_v - min_v) // bucket_size + 1
    buckets = [[] for _ in range(int(bucket_count))]   # initialize buckets
    for x in a:  # distribute values into buckets
        buckets[int((x - min_v) // bucket_size)].append(x)
    return buckets


def bin_sort(a, bucket_size=16):
    """
    :param a: list
        List of objects with an order
    :param bucket_size: int
        Size of buckets to fill
    :return: list
        Sorted list with bin sort algorithm
    """

    if len(a) == 0:  # trivial case
        return a

    buckets = get_buckets(a, bucket_size)  # get buckets
    a = []
    for bucket in buckets:  # sort each bucket ...
        a += insertion_sort(bucket)  # ... and place back into array
    return a


def main():
    """
    Sorts sample list with bin sort algorithm,
    then prints sorted list
    """

    unsorted_list = [
        4372.30, 851821, 184.681, 173673, 133.06, 768361, 431.982, 9567.00,
        5566.81, 1982.08, 983511, 170.469, 313978, 552536, 3348.18, 527289,
        95.9491, 303675, 532988, 65143
    ]

    sorted_list = bin_sort(unsorted_list)
    print(sorted_list)


if __name__ == '__main__':
    main()
