=begin
	Part of Cosmos by OpenGenus Foundation
=end

def BinarySearch(arr, l, r, x)

    if x.nil?
        return -1
    end

    if r >= l
        mid = (l + r)/2
        if arr[mid] == x
            mid
        elsif arr[mid] > x
            BinarySearch(arr, l, mid-1, x)
        else
            BinarySearch(arr, mid+1, r, x)
        end
    end
end

arr = [3,5,12,56,92,123,156,190,201,222]

number = 12

puts "Position of #{number} is #{BinarySearch(arr, 0, arr.length-1, number)}"
