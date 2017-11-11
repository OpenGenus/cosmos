defmodule Fib do 
  def fib(0), do: 0
  def fib(1), do: 1
  def fib(n), do: fib(n-1) + fib(n-2)
end

arg = String.to_integer(List.first(System.argv))
IO.puts Fib.fib(arg)