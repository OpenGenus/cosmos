defmodule Factorial do 
  def factorial(0), do: 1
  def factorial(n), do: n * factorial(n-1)
end

arg = String.to_integer(List.first(System.argv))
IO.puts Factorial.factorial(arg)