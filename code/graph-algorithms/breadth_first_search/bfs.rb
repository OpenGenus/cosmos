
class GraphNode
  require 'set'
  @@id = 0

  attr_reader :name, :id, :parent, :children
  attr_writer :parent

  def initialize name, parent=nil
    @name = name
    @id = (@@id += 1)
    @parent = parent
    @children = Set.new
  end

  def addChild node
    return false unless node.kind_of? GraphNode
    @children << node
  end

  def equal? other
    return false unless other.kind_of? GraphNode
    return @name == other.name && @id == other.id
  end

end

class Graph

  require 'set'

  def self.getPath node
    path = [node]
    current = node
    while not current.parent.nil?
      path << current.parent
      current = current.parent
    end
    return path
  end

end

def goalNode? node
  return node.name == "Goal"
end


def bfs start, goal=:goalNode?
  require 'set'
  visited = Set.new
  frontier = Array.new
  frontier << start

  while not frontier.empty?
    current = frontier.shift

    if not visited === current
      visited << current
      found = false
      if block_given?
        found = yield(current)
      else
        found = send(goal, current)
      end

      if not found
        current.children.each do |node|
          frontier << node
        end
      else
        return Graph.getPath(current)
      end
    end
  end

end

#            First
#           /     \
#       second    third
#      /     |    |    \
#   fourth fifth  goal sixth
first = GraphNode.new "First"
second = GraphNode.new "Second"
third = GraphNode.new "Third"
fourth = GraphNode.new "Fourth"
fifth = GraphNode.new "Third"
sixth = GraphNode.new "Fourth"
goal = GraphNode.new "Goal"

first.addChild second
first.addChild third

second.parent = first
second.addChild fourth
second.addChild fifth

third.parent = first
third.addChild goal
third.addChild sixth

fourth.parent = second
fifth.addChild second

goal.parent = third
sixth.addChild third

puts(bfs first)
