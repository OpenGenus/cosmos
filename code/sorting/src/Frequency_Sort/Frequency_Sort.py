from collections import defaultdict
 
# Sort by Frequency
 
 
def sortByFreq(arr, n):
    # arr -> Array to be sorted
    # n   -> Length of Array
 
    # d is a hashmap(referred as dictionary in python)
    d = defaultdict(lambda: 0)
    for i in range(n):
        d[arr[i]] += 1
        
    # Sorting the array 'arr' where key
    # is the function based on which
    # the array is sorted
    # While sorting we want to give
    # first priority to Frequency
    # Then to value of item
    arr.sort(key=lambda x: (-d[x], x))
    # arr = sorted(arr, key = lambda x: (-d[x],x))
    return (arr)
 
 
# Driver Function
if __name__ == "__main__":
    arr = [2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8]
    n = len(arr)
    solution = sortByFreq(arr, n)
    print(*solution)