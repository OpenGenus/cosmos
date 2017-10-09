defmodule Math do
    def sum_of_digits(n) do
        Enum.reduce(Integer.digits(n), fn(x, acc) -> x + acc end)
    end
end

IO.puts Math.sum_of_digits(12345)
