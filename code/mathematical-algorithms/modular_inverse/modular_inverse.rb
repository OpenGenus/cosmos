# Part of Cosmos by OpenGenus Foundation
def extended_gcd(a, b)
  last_remainder = a.abs
  remainder = b.abs
  x = 0
  last_x = 1
  y = 1
  last_y = 0
  while remainder != 0
    (quotient, remainder) = last_remainder.divmod(remainder)
    last_remainder = remainder
    x, last_x = last_x - quotient * x, x
    y, last_y = last_y - quotient * y, y
  end

  [last_remainder, last_x * (a < 0 ? -1 : 1)]
end

def invmod(e, et)
  g, x = extended_gcd(e, et)
  raise 'The maths are broken!' if g != 1
  x % et
end
