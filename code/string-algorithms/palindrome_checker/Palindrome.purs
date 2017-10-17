module Palindrome where
import Control.Monad.Aff (Aff)
import Control.Monad.Aff.Console (CONSOLE,log)
import Data.String (toLower)
import Data.String.Yarn (reverse)
import Prelude (Unit,bind, pure,unit,(==))
palindromeChecker::String->Aff(console::CONSOLE)Unit
palindromeChecker string = do
                   _<- if string == toLower (reverse string) then do
                      log "Palindrome Matching"
                     else do
                       log "Palindrome Not Matching"
                   pure unit
main::Aff(console::CONSOLE)Unit
main= do
        _<- palindromeChecker "Tharun"
        _<- palindromeChecker "MalaYaLam"
        pure unit
