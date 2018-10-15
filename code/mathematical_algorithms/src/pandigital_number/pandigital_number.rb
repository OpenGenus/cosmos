def is_pandigital(num)
  digits = (1 << 10) - 1
  while num > 0
    dgt = num % 10
    dgt_map = ((1 << 10) - 1) - (1 << dgt)
    digits &= dgt_map
    num /= 10
  end
  digits == 0
end

def is_zeroless_pandigital(num)
  digits = (1 << 9) - 1
  while num > 0
    dgt = num % 10
    return false if dgt == 0
    dgt_map = ((1 << 9) - 1) - (1 << (dgt - 1))
    digits &= dgt_map
    num /= 10
  end
  digits == 0
end

puts is_pandigital(185_239)
puts is_pandigital(9_483_271_065)
puts is_pandigital(1_223_334_444_555_556_666_667_777_777_888_888_889_999_999_990)

puts is_zeroless_pandigital(185_239)
puts is_zeroless_pandigital(9_483_271_065)
puts is_zeroless_pandigital(948_327_165)
