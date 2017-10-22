def is_pandigital(num)
    digits = (1 << 10) - 1
    while num > 0 do
        dgt = num % 10
        dgt_map = ((1 << 10) - 1) - (1 << dgt)
        digits = digits & dgt_map
        num /= 10
    end
    digits == 0
end

def is_zeroless_pandigital(num)
    digits = (1 << 9) - 1
    while num > 0 do
        dgt = num % 10
        return false if dgt == 0
        dgt_map = ((1 << 9) - 1) - (1 << (dgt - 1))
        digits = digits & dgt_map
        num /= 10
    end
    digits == 0
end

puts is_pandigital(185239)
puts is_pandigital(9483271065)
puts is_pandigital(1223334444555556666667777777888888889999999990)

puts is_zeroless_pandigital(185239)
puts is_zeroless_pandigital(9483271065)
puts is_zeroless_pandigital(948327165)