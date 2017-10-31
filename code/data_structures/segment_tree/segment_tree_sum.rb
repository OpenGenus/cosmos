# Part of Cosmos by OpenGenus Foundation

class SegTree
  def initialize(arr)
    @arr = arr
    @end = arr.length - 1
    @tree = Array.new(arr.length * 4, 0)
    start(0, 0, @end)
  end

  def start(root, left, right)
    if left == right
      @tree[root] = @arr[left]
      return 0
    end
    mid = (left + right) / 2
    node_left = 2 * root + 1
    node_right = node_left + 1

    start(node_left, left, mid)
    start(node_right, mid + 1, right)

    @tree[root] = @tree[node_right] + @tree[node_left]
  end

  def query_helper(root, q_left, q_right, left, right)
    if (q_left > right) || (q_right < left)
      # range represented by a node is completely outside the given range
      return 0
    end

    if (q_left <= left) && (q_right >= right)
      # range represented by a node is completely inside the given range
      return @tree[root]
    end

    mid = (left + right) / 2
    left_node = 2 * root + 1
    right_node = left_node + 1

    left_sum = query_helper(left_node, q_left, q_right, left, mid)
    right_sum = query_helper(right_node, q_left, q_right, mid + 1, right)

    left_sum + right_sum
  end

  # wrapper to queryHelper
  def query(query_left, query_right)
    query_helper(0, query_left, query_right, 0, @end)
  end

  def update_helper(root, pos, value, left, right)
    return if (pos < left) || (pos > right)

    if left == right
      @tree[root] = value
      return
    end

    mid = (left + right) / 2
    left_node = 2 * root + 1
    right_node = left_node + 1

    update_helper(left_node, pos, value, left, mid)
    update_helper(right_node, pos, value, mid + 1, right)

    # recursive update
    @tree[root] = @tree[left_node] + @tree[right_node]

    nil
  end

  # update wrapper
  def update(pos, value)
    update_helper(0, pos, value, 0, @end)
  end

  private :start, :query_helper, :update_helper
end

arr = [1, 2, -1, 4, 5]
seg_tree = SegTree.new arr
seg_tree.update 2, 3 # arr[2] = 5
p seg_tree.query 0, 4
