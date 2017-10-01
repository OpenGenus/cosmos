"""Bucket sort in python""" #docstring
import math

def get_bucket_list_size_and_min(arr, bucket_size=10):
    """Get no of buckets to be used and min value""" #docstring
    min = arr[0]
    max = arr[0]
    for num in arr:
        if num < min:
            min = num
        elif num > max:
            max = num
    return [math.floor((max - min)/bucket_size)+1, min]

def insertion_sort(arr):
    """Insertion sort, required for the Bucket Sort Algorithm. Returns sorted bucket""" #docstring
    if len(arr) <= 1: 
        return arr
    i = 1
    while i < len(arr):
        k = arr[i]
        j = i-1
        while j >= 0 and arr[j] > k:
            arr[j+1] = arr[j]
            arr[j] = k
            j = j-1
        i = i+1
    return arr

def bucket_sort(arr, bucket_size=10):
    """Bucket Sort arr and return sorted array""" #docstring
    bucket_list_size, minValue = get_bucket_list_size_and_min(arr,bucket_size)
    buckets = [[] for x in range(bucket_list_size)]
    for i in arr:
        buckets[math.floor((i - minValue) / bucket_size)].append(i)
    sorted_arr = []
    for b in buckets:
        sorted_arr += insertion_sort(b)
    return arr


