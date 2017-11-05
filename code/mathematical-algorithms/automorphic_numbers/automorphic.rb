def is_automorphic(x)
  x2 = (x**2).to_s;   x = x.to_s
  x2_len = x2.length; x_len = x.length
  x == x2[x2.length - x.length..x2.length]
end

## tests
# automorphic
[5, 6, 76, 376, 890_625].each do |num|
  num_squared = num**2
  puts "#{num}^2 = #{num_squared} -> Automorphic: #{is_automorphic(num)}"
end

# not automorphic
[2, 8, 75, 377, 890_620].each do |num|
  num_squared = num**2
  puts "#{num}^2 = #{num_squared} -> Automorphic: #{is_automorphic(num)}"
end
