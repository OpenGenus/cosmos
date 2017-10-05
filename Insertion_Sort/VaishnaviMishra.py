def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j] :
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = key
 
 
def main():
    n=int(input("Enter number of elements in array."))
    arr=[None]*n
    for i in range(n):
        arr[i]=int(input("Enter element"))
    insertionSort(arr)
    print ("Sorted array is:")
    for i in range(len(arr)):
        print ("%d" %arr[i])


if __name__=='__main__':
    main()