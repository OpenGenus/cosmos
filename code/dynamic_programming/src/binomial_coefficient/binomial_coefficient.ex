defmodule BinomialCoefficient do
  def binn_coef(n, k) do
    cond do
      n <= 0 or k <= 0 ->
        {:error, :non_positive}

      n < k ->
        {:error, :k_greater}

      true ->
        p = n - k

        {rem_fact_n, div_fact} =
          if p > k do
            {
              n..(p + 1)
              |> Enum.reduce(1, &(&1 * &2)),
              2..k
              |> Enum.reduce(1, &(&1 * &2))
            }
          else
            {
              n..(k + 1)
              |> Enum.reduce(1, &(&1 * &2)),
              2..p
              |> Enum.reduce(1, &(&1 * &2))
            }
          end

        rem_fact_n / div_fact
    end
  end
end

# This code is contributed by ryguigas0
