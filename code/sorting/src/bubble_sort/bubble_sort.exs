"""
Part of Cosmos by OpenGenus Foundation 
"""
defmodule Sort do
  def bubble_sort(list) when length(list)<=1, do: list
  def bubble_sort(list) when is_list(list), do: bubble_sort(list, [])

  def bubble_sort([x], sorted), do: [x | sorted]
  def bubble_sort(list, sorted) do
    {rest, [max]} = Enum.split(bubble_move(list), -1)
    bubble_sort(rest, [max | sorted])
  end

  def bubble_move([x]), do: [x]
  def bubble_move([x, y | t]) when x > y, do: [y | bubble_move([x | t])]
  def bubble_move([x, y | t])           , do: [x | bubble_move([y | t])]

end

IO.inspect Sort.bubble_sort([3,2,1,4,5,2])
