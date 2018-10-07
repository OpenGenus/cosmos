defmodule Cosmos.Search.BinarySearch do
  def binary_search(array, key) do
    bs array, key, 0, length(array)
  end

  defp bs([], _, _, _), do: nil
  defp bs([_], _, _, _), do: 0
  defp bs(_, _, min, max) when max < min, do: nil
  defp bs(array, key, min, max) do
    mid      = div min + max, 2
    {_, val} = Enum.fetch array, mid

    cond do
      val > key -> bs array, key, min, mid - 1
      val < key -> bs array, key, min + 1, max
      true      -> mid
    end
  end

end
