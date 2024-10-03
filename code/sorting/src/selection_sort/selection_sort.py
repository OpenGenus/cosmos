# Part of Cosmos by OpenGenus Foundation

#Python program for selection sort
def selection_sort(array): 
    
    #Traversing one by one through the elements in array
    for i in range(len(array) - 1):
        
        #Finding the minimum element in the unsorted array 
        minimumValue = i
        for j in range(i + 1, len(array)):
            if array[j] < array[minimumValue]:
                minimumValue = j
                
        #Swapping the minimum value with the first element of the array
        temp = array[minimumValue]
        array[minimumValue] = array[i]
        array[i] = temp
    return array
