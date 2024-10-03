# Part of Cosmos by OpenGenus Foundation

def average_stream_number(input_array)
  avg = 0
  resultant_array = []
  input_array.each_with_index do |element, i|
    avg = average(element, avg, (i + 1))
    puts avg
    resultant_array << avg
  end
  resultant_array
end

def average(new_element, prev_avg, index)
  ((prev_avg * (index - 1) + new_element).to_f / index)
end

# Dynamic array input
puts 'Enter the size of array'
size_of_array = gets.chomp.to_i
input_array = []
size_of_array.times.each do
  input_array << gets.chomp.to_i
end

average_stream_number(input_array)
