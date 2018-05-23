smallest :: Integer -> Integer
smallest n
	 | modOfTen == n = n
	 | otherwise     = modOfTen `min` greatest quotOfTen
	 where modOfTen  = mod n 10
	      quotOfTen = quot n 10
