defmodule ArrayMedian do
  def get_median(list_nums) when is_list(list_nums) do
    half = length(list_nums) |> div(2)

    if length(list_nums) |> rem(2) != 0 do
      # odd length -> middle number
      mid = half + 1

      Enum.reduce_while(list_nums, 1, fn
        el, ^mid ->
          {:halt, el}

        _el, acc ->
          {:cont, acc + 1}
      end)
    else
      # even length -> mean of the 2 middle numbers
      {n1, n2} =
        Enum.reduce_while(list_nums, 1, fn
          el, {n1} ->
            {:halt, {n1, el}}

          el, ^half ->
            {:cont, {el}}

          _el, acc ->
            {:cont, acc + 1}
        end)

      (n1 + n2) / 2
    end
  end
end

# This code is contributed by ryguigas0
