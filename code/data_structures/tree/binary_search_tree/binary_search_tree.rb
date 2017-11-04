# Part of Cosmos by OpenGenus Foundation

##
# Represents a single node within a binary search tree.
class Node
  attr_accessor :data, :left, :right

  ##
  # Initializes a new node with given +data+.
  #
  # Params:
  # +data+:: Data to store within this node.
  def initialize(data)
    @data = data
    @left  = nil
    @right = nil
  end

  def to_s
    @data
  end
end

##
# A binary search tree made from generic nodes.
class BinarySearchTree
  ##
  # Initializes a new binary search tree.
  def initialize
    @root = nil
  end

  ##
  # Searchs this binary search tree for the provided +data+.
  #
  # Params:
  # +data+:: Data to search for
  def search(data)
    # Start at the root node
    current = @root
    puts 'Visiting all nodes...'

    # Iterate through all nodes
    while current.data != data

      puts "Current node: #{current}"

      # Determine whether to move left or right in tree
      current = if data < current.data
                  current.left
                else
                  current.right
                end

      # Occurs when the end of the tree is reached.
      if current.nil?
        puts "Not found: #{data}"
        return false
      end

    end

    true
  end

  ##
  # Inserts the given +data+ into the binary search tree.
  #
  # Params:
  # +data+:: Data to insert into BST.
  def insert(data)
    # Create new node
    node = Node.new(data)

    # Check if tree is empty
    if @root.nil?
      @root = node
      return
    end

    current = @root
    parent = nil

    # Traverse BST
    loop do
      parent = current

      # Determine whether to place left or right in the tree
      if data < parent.data
        current = current.left

        # Update left node
        if current.nil?
          parent.left = node
          return
        end
      else
        current = current.right

        # Update right node
        if current.nil?
          parent.right = node
          return
        end
      end
    end
  end
end

tree = BinarySearchTree.new
tree.insert(15)
tree.insert(5)
tree.insert(30)
tree.insert(25)
puts tree.search(5)
puts tree.search(10)
