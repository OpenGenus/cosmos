% Part of Cosmos by OpenGenus Foundation
-module(palindrome).
-export([is_palindrome/1).
 
is_palindrome(String) -> String =:= lists:reverse(String).