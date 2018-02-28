class Node
  attr_accessor :key
  attr_accessor :value
  attr_accessor :forward
 
  def initialize(k, v = nil)
    @key = k 
    @value = v.nil? ? k : v 
    @forward = []
  end
end
 
class SkipList
  attr_accessor :level
  attr_accessor :header
   
  def initialize
   @header = Node.new(1) 
   @level = 0
   @max_level = 3
   @p = 0.5
   @node_nil = Node.new(1000000)
   @header.forward[0] = @node_nil
  end
   
  def search(search_key)
    x = @header
    @level.downto(0) do |i|
      while x.forward[i].key < search_key do
        x = x.forward[i]
      end
    end   
    x = x.forward[0]
    if x.key == search_key
      return x.value
    else
      return nil
    end
  end
 
  def random_level
    v = 0
    while rand < @p && v < @max_level
      v += 1
    end
    v
  end
 
  def insert(search_key, new_value = nil)
    new_value = search_key if new_value.nil? 
    update = []
    x = @header
    @level.downto(0) do |i|
      while x.forward[i].key < search_key do
        x = x.forward[i]
      end
      update[i] = x
    end   
    x = x.forward[0]
    if x.key == search_key
      x.value = new_value
    else
      v = random_level
      if v > @level
        (@level + 1).upto(v) do |i|
          update[i] = @header
          @header.forward[i] = @node_nil
        end
        @level = v
      end
      x = Node.new(search_key, new_value) 
      0.upto(v) do |i|
        x.forward[i] = update[i].forward[i]
        update[i].forward[i] = x
      end
    end
  end
end
