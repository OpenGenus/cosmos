"""

divide conquer | inversion count | Python
part of Cosmos by OpenGenus Foundation

"""


def merge(left, right):
    merged_arr = []
    i = 0
    j = 0
    inv_cnt = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged_arr.append(left[i])
            i += 1
        else:
            merged_arr.append(right[j])
            j += 1
            inv_cnt += len(left) - i

    merged_arr += left[i:]
    merged_arr += right[j:]

    return merged_arr, inv_cnt


def merge_sort(
    arr
):  # this function will return a tuple as (sorted_array, inversion_count)
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        left, left_inv_cnt = merge_sort(left)
        right, right_inv_cnt = merge_sort(right)
        merged, merged_inv_cnt = merge(left, right)
        return merged, (left_inv_cnt + right_inv_cnt + merged_inv_cnt)
    else:
        return arr, 0


arr = [1, 8, 3, 4, 9, 3]
sorted_array, inversion_count = merge_sort(arr)

print("Sorted array:", sorted_array, " and Inversion count = %s" % inversion_count)
