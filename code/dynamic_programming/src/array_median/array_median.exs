defmodule ArrayMedian do
  def get_median(array) when is_list(array) do
    list_nums = Enum.sort(array)
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

# Test data from array_median.php
test_data = [
  [[-1], -1],
  [[0], 0],
  [[1], 1],
  [[-1, 0, 1], 0],
  [[1, 2, 3], 2],
  [[-1, -2, -3], -2],
  [[1, 2.5, 3], 2.5],
  [[-1, -2.5, -3], -2.5],
  [[1, 2, 2, 4], 2],
  [[1, 2, 3, 4], 2.5],
  [[2, 2, 1, 4], 2],
  [[3, 2, 1, 4], 2.5],
  [[-1, -2, -2, -4], -2],
  [[-1, -2, -3, -4], -2.5]
]

Enum.each(
  test_data,
  fn data = [arr, expected] ->
    result = ArrayMedian.get_median(arr)

    if result == expected do
      IO.puts("Success!!")
    else
      IO.puts("Failure")
      IO.inspect(data, label: "Problem here")
      IO.inspect(result, label: "wrong")
    end
  end
)
