# Part of Cosmos by OpenGenus Foundation
class Stack
  attr_accessor :items

  def initialize
    @items = []
  end

  def push(element)
    @items.push(element)
  end

  def pop
    @items.pop
  end

  def empty?
    @items.empty?
  end

  def peek
    @items.last
  end
end
