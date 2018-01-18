defmodule Factorial do
  def factorial(0), do: 1
  def factorial(1), do: 1
  def factorial(num) do
    num * factorial(num - 1)
  end
end