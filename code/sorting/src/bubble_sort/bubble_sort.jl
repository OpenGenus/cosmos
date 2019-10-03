### /* Part of Cosmos by OpenGenus Foundation */
### Julia 0.6 Implementation of bubble sorting algorithm

function bubblesort(arr)
    n = length(arr)
 
    for i=1:n, j=1:n-i
        if (arr[j] > arr[j+1])
            arr[j], arr[j+1] = arr[j+1], arr[j]
        end
    end
end

v = [144 89 4 9 95 12 86 25]
print("unbubble sorted array = ",v)

bubblesort(v)

print("\nbubble sorted array = ",v)


