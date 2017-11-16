greatest :: Integer -> Integer
greatest n
	| modOfTen == n = n
	| otherwise     = modOfTen `max` greatest quotOfTen
	where modOfTen  = mod n 10
	      quotOfTen = quot n 10