defmodule Fibonacci do
  def fib(terms) do
    if terms <= 0 do
      {:error, :non_positive}
    else
      {fib_list, _} =
        Enum.map_reduce(1..terms, {0, 1}, fn
          1, _acc -> {1, {1, 1}}
          _t, {n1, n2} -> {n1 + n2, {n1 + n2, n1}}
        end)

      Enum.each(fib_list, fn f -> IO.puts("#{f}") end)
    end
  end
end
