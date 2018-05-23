# Part of Cosmos by OpenGenus Foundation

class MinHeap
  attr_reader :heap

  def initialize
    @heap = []
  end

  def push(value)
    @heap.push(value)
    index = @heap.size - 1

    up_heap(index)
  end

  def pop
    min = @heap.first
    last = @heap.pop
    @heap[0] = last

    heapify(0)
    min
  end

  def empty?
    heap.empty?
  end

  def min
    @heap.first
  end

  private

  def up_heap(index)
    parent_index = index / 2

    if @heap[parent_index] > @heap[index]
      parent = @heap[parent_index]
      @heap[parent_index] = @heap[index]
      @heap[index] = parent

      up_heap(parent_index)
    end
  end

  def heapify(index)
    left = index * 2
    right = left + 1
    min = index

    min = left if left < @heap.size && @heap[left] < @heap[min]
    min = right if right < @heap.size && @heap[right] < @heap[min]

    if min != index
      min_value = @heap[min]
      @heap[min] = @heap[index]
      @heap[index] = min_value
      heapify(min)
    end
  end
end

h = MinHeap.new
h.push(4)
h.push(10)
h.push(2)
p h.min
h.push(5)
p h.pop
p h.min
h.push(9)
h.push(1)
p h.min
