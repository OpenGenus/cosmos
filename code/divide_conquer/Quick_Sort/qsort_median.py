# Part of Cosmos by OpenGenus Foundation

import statistics
arr = [int(x) for x in input().split()]

def median_pivot(array,l,r):
    if (r-l+1) %2 == 0:
        m = l+int((r-l+1)/2)-1
    else:
        m = int((r+l)/2)
    l = [array[l],array[m],array[r]]
    l.sort()
    return array.index(l[1])

def partition(array,l,r):
    ind = median_pivot(array,l,r)
    array[l],array[ind] = array[ind],array[l] #If we want to choose other
    #element as pivot then just swap that with first
    p = array[l]
    i = l+1
    for j in range(l+1,r+1):
        if array[j]<p:
            array[j],array[i] = array[i],array[j]
            i+=1
    array[l],array[i-1]=array[i-1],array[l]
    return i-1

def q_sort(array,l,h):
    if l<h:
        p = partition(array,l,h)
        q_sort(array,l,p-1)
        q_sort(array,p+1,h)


q_sort(arr,0,len(arr)-1)
print(arr)
