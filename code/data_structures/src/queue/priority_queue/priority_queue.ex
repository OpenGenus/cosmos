defmodule Cosmos.Code.DataStructures.Queue.PriorityQueue do

  def new(), do: []

  def insert_with_priority(queue, {_item, _prio} = elem) do
    queue ++ [elem]
  end


  def get_frontmost_element(queue) do
    gfe queue
  end


  def delete([]), do: []
  def delete([_head | tail]), do: tail


  def empty?(queue), do: Enum.empty? queue


  def front([]), do: nil
  def front(queue) do
    {result, _} = gfe queue
    result
  end

  defp gfe([]), do: nil
  defp gfe(queue) do
    {_, front_elem} = queue
                      |> Enum.group_by(fn {_, prio} -> prio end)
                      |> Map.to_list
                      |> Enum.sort(fn ({prio, _}, {prio_compare, _}) ->  prio >= prio_compare end)
                      |> List.first

    {List.first(front_elem), queue -- [List.first(front_elem)]}
  end


  def member?(queue, elem), do: Enum.member? queue, elem


  def position_by_order(queue, elem) do
    get_pos queue, elem, 1
  end

  defp get_pos([], _, _), do: -1
  defp get_pos([head | tail], elem, count) do
    if head == elem do
      count
    else
      get_pos tail, elem, count + 1
    end
  end


  def position_by_priority([]), do: -1
  def position_by_priority(queue, elem) do
    find_elem_by_priority queue, elem, 1
  end

  defp find_elem_by_priority([], _, _), do: -1
  defp find_elem_by_priority([_head | tail] = queue, elem, count) do
    if elem == front(queue) do
      count
    else
      find_elem_by_priority tail, elem, count + 1
    end
  end


  def more_than_once(queue, elem), do: mto queue, elem

  defp mto([], _), do: false
  defp mto([head | tail], elem) do
    if head == elem do
      if position_by_order(tail, elem) >= 1 do
        true
      else
        false
      end
    else
      mto tail, elem
    end
  end


  def size(queue), do: length queue


  def increase_element_priority([], _, _), do: []
  def increase_element_priority(queue, {item, prio} = elem, new_prio)
    when new_prio >= prio do
      pos        = position_by_order queue, elem
      first_half = (queue |> Enum.take(pos)) -- [elem]
      sec_half   = queue  |> Enum.slice(pos, length(queue))

      first_half ++ [{item, new_prio}] ++ sec_half
  end
end
