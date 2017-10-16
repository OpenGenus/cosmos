# Part of Cosmos by OpenGenus Foundation

# Pattern matching
# new_element = head
# items = tail

defmodule Stack do
  def new, do: [] 
  
  def push(new_element, items), do: [new_element | items]
  
  def pop([new_element | items]), do: {new_element, items}
  
  def empty?([]), do: true
  def empty?(_), do: false
  
  def top([head | _]), do: head
end