defmodule Factorial do
  def factorial(0), do: 1
  def factorial(1), do: 1
  def factorial(num) when num > 1 do
    num * factorial(num - 1)
  end
end
