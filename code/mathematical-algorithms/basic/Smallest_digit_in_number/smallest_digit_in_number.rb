def smallest_digit_in_number(input)
  if !is_a_number? input
    puts "Wrong input. Try again and insert a integer next time"
    return false
  end

  input_array = input.to_s.split("")
  smaller_number = input_array.sort.first

  puts "The smallest input is: #{smaller_number}"
end

def is_a_number?(input)
  is_a_fixnum = input.is_a? Fixnum
  return false if not is_a_fixnum
  true
end

smallest_digit_in_number 92345678
