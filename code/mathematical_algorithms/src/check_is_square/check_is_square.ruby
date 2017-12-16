# let isPerfectSquare = num => Math.sqrt(num) === Math.floor(Math.sqrt(num))

# console.log(isPerfectSquare(0)) // should output true
# console.log(isPerfectSquare(1)) // should output true
# console.log(isPerfectSquare(2)) // should output false
# console.log(isPerfectSquare(4)) // should output true
# console.log(isPerfectSquare(8)) // should output false
# console.log(isPerfectSquare(16)) // should output true
# console.log(isPerfectSquare(32)) // should output false
# console.log(isPerfectSquare(64)) // should output true

def perfect_square?(num)
  Math.sqrt(num) % 1 == 0
end

puts perfect_square?(0)    # should output true
puts perfect_square?(1)    # should output true
puts perfect_square?(2)    # should output false
puts perfect_square?(4)    # should output true
puts perfect_square?(8)    # should output false
puts perfect_square?(16)   # should output true
puts perfect_square?(32)   # should output false
puts perfect_square?(64)   # should output true
