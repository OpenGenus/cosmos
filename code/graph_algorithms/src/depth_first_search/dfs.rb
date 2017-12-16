#   This class represents a node in a graph.
#   It has a NAME and an ID and each node knows which nodes it is connected to.
class GraphNode
  require 'set'
  @@id = 0

  attr_reader :name, :id, :connections

  def initialize(name)
    @name = name
    @id = (@@id += 1)
    @connections = Set.new
  end

  def connect(node)
    return false unless node.is_a? GraphNode
    @connections << node
  end

  def equal?(other)
    return false unless other.is_a? GraphNode
    @name == other.name && @id == other.id
  end

  def to_s
    "<GraphNode:#{name}>"
  end

  def to_str
    to_s
  end
end

#   A simple function as a default function performed for each node in dfs()
def goalNode?(node)
  node.name == 'Goal'
end

#   Given a start node and a function or code block this performs a depth first search and will exit upon function or code block returning true, or returns :goal_node_not_found when it has visited the whole graph.
#
#   visited is a set containing all nodes that has been checked.
#   frontier is a queue were new nodes are prepended in reverse order, making this a depth first search.
def dfs(start, goal = :goalNode?)
  require 'set'
  visited = Set.new
  frontier = []
  frontier << start

  until frontier.empty?
    current = frontier.shift

    next if visited.include? current
    visited << current

    found = false
    found = if block_given?
              yield(current)
            else
              send(goal, current)
            end

    if !found
      current.connections.reverse_each do |node|
        frontier.unshift node
      end
    else
      return current
    end
  end
  :goal_node_not_found
end

#   A small test that will use dfs() for root node First, then for the Second node.
#   The dfs accepts a code block, and here we just print each visited node and will never find the goal-node.
#
#   The tests output:
#   Building Graph for tests...
#   Testing from root node 'First'
#     <GraphNode:First>
#     <GraphNode:Second>
#     <GraphNode:Fourth>
#     <GraphNode:Fifth>
#     <GraphNode:Third>
#     <GraphNode:Goal>
#     <GraphNode:Sixth>
#   goal_node_not_found
#   Testing from second node 'Second'
#     <GraphNode:Second>
#     <GraphNode:First>
#     <GraphNode:Third>
#     <GraphNode:Goal>
#     <GraphNode:Sixth>
#     <GraphNode:Fourth>
#     <GraphNode:Fifth>
#   goal_node_not_found
def test
  puts 'Building Graph for tests...'
  #         Simple graph
  #
  #            First
  #           /     \
  #       second    third
  #      /     |    |    \
  #   fourth fifth  goal sixth
  #
  # Construct graph
  first = GraphNode.new 'First'
  second = GraphNode.new 'Second'
  third = GraphNode.new 'Third'
  fourth = GraphNode.new 'Fourth'
  fifth = GraphNode.new 'Fifth'
  sixth = GraphNode.new 'Sixth'
  goal = GraphNode.new 'Goal'

  first.connect second
  first.connect third

  second.connect first
  second.connect fourth
  second.connect fifth

  third.connect first
  third.connect goal
  third.connect sixth

  fourth.connect second
  fifth.connect second

  goal.connect third
  sixth.connect third

  # Perform tests
  puts "Testing from root node 'First'"
  puts(dfs(first) { |node| puts '  ' + node })

  puts "Testing from second node 'Second'"
  puts(dfs(second) { |node| puts '  ' + node })
end

test if $PROGRAM_NAME == __FILE__
