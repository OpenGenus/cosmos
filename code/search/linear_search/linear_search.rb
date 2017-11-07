# Part of Cosmos by OpenGenus Foundation

items = [5, 10, 34, 18, 6, 7, 45, 67]
target = 7

##
# Returns a boolean that indicates whether the target item is contained within
# the given list.
def linear_search(list, target)
  # Iterate over each item in the list
  list.each do |item|
    return true if item == target
  end

  false
end

found = linear_search(items, target)

if found
  puts "Found '#{target}'!"
else
  puts "'#{target}' was not found."
end
