# Part of Cosmos by OpenGenus Foundation
class Node
  attr_accessor :data
  attr_accessor :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

class LinkedList
  attr_reader :size

  def initialize
    @head = nil
    @size = 0
  end

  # Add a new node at end of linked list
  def add!(data)
    if @head.nil?
      @head = Node.new(data)
    else
      current_node = @head
      current_node = current_node.next until current_node.next.nil?
      current_node.next = Node.new(data)
    end
    @size += 1
    nil
  end

  # Insert a new node at index
  def insert!(index, data)
    # If index is not in list yet, just assume add at end
    return add!(data) if index >= @size
    current_node = @head
    prev_node = nil
    current_index = 0
    until current_node.nil?
      if index == current_index
        new_node = Node.new(data)
        new_node.next = current_node
        if current_node == @head
          @head = new_node
        else
          prev_node.next = new_node
        end
      end
      current_index += 1
      prev_node = current_node
      current_node = current_node.next
    end
    @size += 1
    nil
  end

  # Get node at index
  def get(index)
    current_index = 0
    current_node = @head
    until current_node.nil?
      return current_node.data if index == current_index
      current_index += 1
      current_node = current_node.next
    end
    nil
  end

  # Return node at index
  def remove!(index)
    current_index = 0
    current_node = @head
    prev_node = nil
    until current_node.nil?
      if index == current_index
        if current_node == @head
          @head = current_node.next
        else
          prev_node.next = current_node.next
        end
        # We probably don't want to have the next node when returning the deleted node
        current_node.next = nil
        return current_node
      end
      current_index += 1
      prev_node = current_node
      current_node = current_node.next
    end
    nil
  end

  # Return list as a string
  def to_s
    current_node = @head
    as_str = ''
    until current_node.nil?
      as_str << ' -> ' unless current_node == @head
      as_str << current_node.data.to_s
      current_node = current_node.next
    end
    as_str
  end
end
