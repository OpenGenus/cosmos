module Main where

import Data.Char (toLower)

palindrome s = lowered == reverse lowered where lowered = map toLower s

main = do
  if palindrome "Tacocat" then
    putStrLn "tacocat is a palindrome"
  else
    putStrLn "tacocat is not a palindrome"
  if palindrome "HelLo" then
    putStrLn "hello is a palindrome"
  else
    putStrLn "hello is not a palindrome"

