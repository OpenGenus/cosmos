# Part of Cosmos by OpenGenus Foundation
class Array
  def heap_sort
    self.heapify
    the_end = self.length - 1

    while the_end > 0
      self[the_end], self[0] = self[0], self[the_end]
      the_end -= 1
      self.sift_down(0, the_end)
    end

    self
  end

  def heapify
    # the_start is the last parent node
    the_start = (self.length - 2) / 2

    while the_start >= 0
      self.sift_down(the_start, self.length - 1)
      the_start -= 1
    end

    self
  end

  def sift_down(the_start, the_end)
    root = the_start

    while root * 2 + 1 <= the_end
      child = root * 2 + 1
      swap = root

      if self[swap] < self[child]
        swap = child
      end

      if child + 1 <= the_end && self[swap] < self[child + 1]
        swap = child + 1
      end

      if swap != root
        self[root], self[swap] = self[swap], self[root]
        root = swap
      else
        return
      end
    end
  end
end

random_names = File.readlines("randomnames.txt")
puts random_names.heap_sort
