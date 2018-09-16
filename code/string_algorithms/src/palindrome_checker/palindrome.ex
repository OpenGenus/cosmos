# Part of Cosmos by OpenGenus Foundation
defmodule Palindrome do
  def is_palindrome(str), do: str == String.reverse(str)
end

IO.puts Palindrome.is_palindrome("hahah")
IO.puts Palindrome.is_palindrome("hello")