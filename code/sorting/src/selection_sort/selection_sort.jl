# Part of Cosmos by OpenGenus Foundation

function selection_sort(array)
    for i in 1:length(array)
        minimum_index = i
        for j = i+1 : size(array)[1]
            if array[j] < array[minimum_index]
                minimum_index = j
            end
        end
        array[minimum_index], array[i] = array[i], array[minimum_index]
    end
    return array
end

testarray = [11,3,4,1,2,5,6,10]
selection_sort(testarray)