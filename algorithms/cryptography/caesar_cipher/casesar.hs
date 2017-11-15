import Data.Char (ord, chr, isUpper, isAlpha)
 
caesar, uncaesar :: Int -> String -> String
caesar = (<$>) . tr
 
uncaesar = caesar . negate
 
tr :: Int -> Char -> Char
tr offset c
  | isAlpha c = chr $ intAlpha + mod ((ord c - intAlpha) + offset) 26
  | otherwise = c
  where
    intAlpha =
      ord
        (if isUpper c
           then 'A'
           else 'a')
 
main :: IO ()
main = mapM_ print [encoded, decoded]
  where
    encoded = caesar (-114) "Veni, vidi, vici"
    decoded = uncaesar (-114) encoded