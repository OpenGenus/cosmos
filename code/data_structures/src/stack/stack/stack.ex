# Part of Cosmos by OpenGenus Foundation

# Pattern matching
# new_element = head
# items = tail
defmodule Stack do
  def new, do: [] 
  
  def push(new_element, items), do: [new_element | items]
  
  def pop([element | items]), do: {element, items}
  
  def empty?([]), do: true
  def empty?(_), do: false
  
  def peek([head | _]), do: head
end