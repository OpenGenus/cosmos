## Part of Cosmos by OpenGenus Foundation
## Find of average of numbers in an array
## Contributed by: Michele Riva (micheleriva)

defmodule Average do
  def get(numbers) do 
  	Enum.sum(numbers) / length(numbers) 
  end
end

# Test
n = [10, 20, 30, 40]
IO.puts Average.get(n) #=> 25
