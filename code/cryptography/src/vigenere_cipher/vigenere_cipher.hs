--Vigenere cipher
module Vigenere where

import Data.Char

chrRg :: Int
chrRg = length ['A'..'Z']

encode :: Char -> Int
encode = subtract (ord 'A') . ord . toUpper

decode :: Int -> Char
decode = chr . (ord 'A' +)

shiftr :: Char -> Char -> Char
shiftr c k = decode $ mod (encode c + encode k) chrRg

shiftl :: Char -> Char -> Char
shiftl c k = decode $ mod (encode c - encode k) chrRg

vigenere :: String -> String -> String
vigenere = vigProc shiftr 

unVigenere :: String -> String -> String
unVigenere = vigProc shiftl  

vigProc :: (Char -> Char -> Char) -> (String -> String -> String)
vigProc s cs = vigProc' s cs . cycle

vigProc' :: (Char -> Char -> Char) -> (String -> String -> String)
vigProc' _ [] _ = []
vigProc' s (c:cs) (k:ks)
  | isLetter c = s c k : vigProc' s cs ks
  | otherwise =  c : vigProc' s cs (k:ks)

encrypt :: IO ()
encrypt = do
  putStrLn "Enter message to be encrypted: "
  mes <- getLine
  putStrLn "Enter key: "
  key <- getLine
  putStrLn "Encrypted message: "
  putStrLn $ vigenere mes key
{- Ex.
  encrypt
  Enter message to be encrypted:
  "Hello, World!"
  Enter key:
  "World"
  Encrypted message:
  "CAZCZ, ZJMHR!" -} 

decrypt :: IO ()
decrypt = do
  putStrLn "Enter message to be decrypted: "
  mes <- getLine
  putStrLn "Enter key: "
  key <- getLine
  putStrLn "Decrypted message: "
  putStrLn $ unVigenere mes key
{- Ex.
  decrypt
  Enter message to be decrypted:
  "CAZCZ, ZJMHR!"
  Enter key:
  "World"
  Decrypted message:
  "HELLO, WORLD!" -}
  