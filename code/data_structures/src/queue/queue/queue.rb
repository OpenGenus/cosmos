# Part of Cosmos by OpenGenus Foundation
class Queue
  attr_accessor :items

  def initialize
    @items = []
  end

  def enqueue(element)
    @items.push(element)
  end

  def dequeue
    @items.delete_at(0)
  end

  def empty?
    @items.empty?
  end

  def front
    @items.first
  end

  def back
    @items.last
  end
end
