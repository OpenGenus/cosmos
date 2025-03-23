defmodule Cosmos.Code.DataStructures.Queue.Queue do

  @spec new() :: []

  def new, do: []


  def enqueue(queue, elem) do
    queue ++ [elem]
  end


  def dequeue([]), do: {nil, []}
  def dequeue([head | tail]) do
    {head, tail}
  end


  def delete([]), do: []
  def delete([_head | tail]), do: tail


  def empty?(queue), do: Enum.empty? queue


  def first([]), do: nil
  def first([head | _tail]), do: head


  def max(queue), do: queue |> Enum.sort |> List.last


  def member?(queue, elem), do: Enum.member? queue, elem


  def position(queue, elem) do
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


  def more_than_once(queue, elem), do: mto queue, elem

  defp mto([], _), do: false
  defp mto([head | tail], elem) do
    if head == elem do
      if position(tail, elem) >= 1 do
        true
      else
        false
      end
    else
      mto tail, elem
    end
  end


  def size(queue), do: length(queue)

end
