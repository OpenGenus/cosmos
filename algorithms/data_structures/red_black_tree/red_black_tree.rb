class Node
  attr_accessor :data, :color, :left, :right, :parent

  def initialize(data)
    @data = data
    @color = 'red'
    @left = nil
    @right = nil
    @parent = nil
  end

  def isSingle
    @left.nil? && @right.nil?
  end

  def addChildLeft(node)
    @left = node
    node.parent = self
  end

  def addChildRight(node)
    @right = node
    node.parent = self
  end

  def grandparent
    return nil if @parent.nil?
    @parent.parent
  end

  def sibling
    if @parent.nil?
      nil
    elsif @parent.left == self
      @parent.right
    else
      @parent.left
    end
  end

  def uncle
    if @parent.nil? || @parent.parent.nil?
      nil
    else
      @parent.sibling
    end
  end

  def rotateLeft
    tmp = right
    self.right = tmp.left
    tmp.left = self
    tmp.parent = parent
    if parent.left == self
      parent.left = tmp
    else
      parent.right = tmp
    end
    self.parent = tmp
  end

  def rotateRight
    tmp = left
    self.left = tmp.right
    tmp.right = self
    tmp.parent = parent
    if parent.left == self
      parent.left = tmp
    else
      parent.right = tmp
    end
    self.parent = tmp
  end
end

class RedBlackTree
  attr_accessor :head
  def initialize
    @head = nil
  end

  def insert(value)
    tmp = Node.new(value)

    if @head.nil?
      @head = tmp
    else
      current = @head
      until current.nil?
        if value < current.data
          if !current.left.nil?
            current = current.left
          else
            current.left = tmp
            break
          end
        elsif value > current.data
          if !current.right.nil?
            current = current.right
          else
            current.right = tmp
            break
          end
        else
          puts "Value #{value} already in tree"
          return
        end
      end
    end
    insert_repair(tmp)
  end

  def insert_repair(node)
    uncle = node.uncle()
    grandparent = node.grandparent()

    if node.parent.nil?
      node.color = 'black'
    elsif node.parent.color == 'black'
      return
    elsif !uncle.nil? && (uncle.color == 'red')
      node.parent.parent.color = 'red'
      node.parent.color = 'black'
      uncle.color = 'black'
      insert_repair(node.parent.parent)
    elsif uncle.nil? || (uncle.color == 'black')
      if node == grandparent.left.right
        rotateLeft(node.parent)
        node = node.left
      elsif node == grandparent.right.left
        rotateRight(node.parent)
        node = node.right
      end

      if node.parent.left == node
        rotateRight(grandparent)
      else
        rotateLeft(grandparent)
      end
      node.parent.color = 'black'
      node.grandparent.color = 'red'
    end
  end

  def search(value)
    current = head
    until current.nil?
      if value < current.data
        current = current.left
      elsif value > current.data
        current = current.right
      else
        puts "Element #{value} Found"
        return
      end
    end
    puts "Element #{value} not Found"
  end
end
