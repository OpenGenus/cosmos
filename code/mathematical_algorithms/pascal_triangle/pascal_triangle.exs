defmodule PascalTriangle do
  def draw(1), do: (IO.puts("1"); [1])
  def draw(current_level) do
    list = draw(current_level - 1)
    new_list = [1] ++ for(x <- 0..length(list)-1, do: Enum.at(list, x) + Enum.at(list, x+1, 0))
    Enum.join(new_list, " ") |> IO.puts
    new_list
  end
end

PascalTriangle.draw(7)
