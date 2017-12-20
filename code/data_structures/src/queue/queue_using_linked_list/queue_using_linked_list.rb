# Part of Cosmos by OpenGenus Foundation

class LinkedQueue
  attr_reader :size

  def initialize
    @head = nil
    @tail = nil
    @size = 0
  end

  def enqueue(element)
    new_node = Node.new(element)
    @size += 1
    if @head
      @tail.next = new_node
      @tail = new_node
    else
      @head = new_node
      @tail = new_node
    end
  end

  def dequeue
    return nil unless @head
    removed = @head
    @head = @head.next
    @size -= 1
    removed.element
  end

  def empty?
    @size == 0
  end

  def front
    @head.element
  end
end

class Node
  attr_accessor :element
  attr_accessor :next

  def initialize(element)
    @element = element
    @next = nil
  end
end

queue = LinkedQueue.new
puts queue.empty?
queue.enqueue(1)
puts queue.front
queue.enqueue(3)
queue.enqueue(4)
queue.enqueue(2)
queue.enqueue(0)
puts queue.dequeue
puts queue.dequeue
puts queue.front
puts format('Size: %d', queue.size)
