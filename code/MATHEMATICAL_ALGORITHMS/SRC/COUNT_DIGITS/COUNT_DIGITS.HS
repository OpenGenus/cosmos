countDigits :: Integer -> Integer
countDigits 0 = 0
countDigits n = succ $ countDigits $ quot n 10

