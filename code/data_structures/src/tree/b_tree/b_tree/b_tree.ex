defmodule Cosmos.Code.DataStructures.Tree.BTree.BTree do

  def new(value) do
    %{value: value, left: :leaf, right: :leaf}
  end

  def insert(:leaf, node_value), do: new node_value
  def insert(%{value: value, left: left, right: right}, node_value) do
    if node_value < value do
      %{value: value, left: insert(left, node_value), right: right}
    else
      %{value: value, left: left, right: insert(right, node_value)}
    end
  end

  def delete_node(tree, node_value) do
    if exists?(tree, node_value) do
      delete tree, node_value
    else
      nil
    end
  end

  defp delete(tree, node_value) do
    cond do
    tree.value == node_value -> del(tree)
    tree.value <  node_value ->
    %{left: tree.left,
      value: tree.value,
      right: delete(tree.right, node_value)}
      tree.value > node_value ->
        %{left: delete(tree.left,node_value),
          value: tree.value,
          right: tree.right}
    end
  end

  defp del(%{left: :leaf,  value: _, right: right}), do: right
  defp del(%{left: left, value: _, right: :leaf}),   do: left
  defp del(%{left: left, value: _, right: right}) do
    %{left: left, value: min(right), right: delete(right, min(right))}
  end

  defp min(%{left: :leaf,  value: val, right: _}), do: val
  defp min(%{left: left, value: _,   right: _}), do: min left


  def find_node(:leaf, _), do: nil
  def find_node(node = %{value: node_value, left: _, right: _},
    node_value) do
    node
  end

  def find_node(node, node_value) do
    if node_value < node.value do
      find_node node.left, node_value
    else
      find_node node.right, node_value
    end
  end

  def find_parent(:leaf, _), do: nil
  def find_parent(node, node_value) do
    _ = if node.left != :leaf && node.left.value == node_value do
      node
    end
    if node.right != :leaf && node.right.value == node_value do
      node
    else
      if node_value < node.value do
        find_parent node.left, node_value
      else
        find_parent node.right, node_value
      end
    end
  end

  def node_depth(tree, node_value), do: nd tree, node_value, 0

  defp nd(:leaf, _, _), do: -1
  defp nd(%{value: node_value, left: _, right: _},
    node_value, depth), do: depth
  defp nd(tree_node, node_value, depth) do
    if node_value < tree_node.value do
      nd tree_node.left, node_value, depth + 1
    else
      nd tree_node.right, node_value, depth + 1
    end
  end


  def tree_height(tree) do
    tree
    |> th(0)
    |> Enum.group_by(fn {_, h} -> h end)
    |> Map.to_list
    |> List.last
    |> Tuple.to_list
    |> List.first
  end

  defp th(:leaf, _), do: []
  defp th(%{value: val, left: :leaf, right: :leaf}, h), do: [{val, h}]
  defp th(tree_node, h) do
    [{tree_node.value, h}] ++ th(tree_node.left, h + 1) ++ th(tree_node.right, h + 1)
  end


  def depth_first_search(tree, order) when order == :pre_order or
    order == :in_order  or
    order == :post_order do
    dfs tree, order
  end

  defp dfs(:leaf, _), do: []
  defp dfs(%{value: val, left: :leaf, right: :leaf}, _), do: [val]
  defp dfs(tree_node, order) do
    case order do
      :pre_order  ->
        [tree_node.value]          ++ dfs(tree_node.left, order)  ++ dfs(tree_node.right, order)
      :in_order   ->
        dfs(tree_node.left, order) ++ [tree_node.value]           ++ dfs(tree_node.right, order)
      :post_order ->
        dfs(tree_node.left, order) ++ dfs(tree_node.right, order) ++ [tree_node.value]
    end
  end


  defp children(list) do
    Enum.map(list, fn (x) -> case x do
        %{left: :leaf, value: _, right: :leaf} -> []
        %{left: left, value: _, right: :leaf} -> left
        %{left: :leaf, value: _, right: right} -> right
        %{left: left, value: _, right: right} -> [left, right]
        _ -> []
      end
    end)
    |> List.flatten
  end


  def breadth_first_search(tree) do
    bfs([tree]) |> Enum.map(fn (x) -> x.value end)
  end

  defp bfs([]), do: []
  defp bfs(list) do
    list ++ bfs(children(list))
  end


  def exists?(tree, node_value) do
    e tree, node_value
  end

  defp e(:leaf, _), do: false
  defp e(%{value: node_value, left: _, right: _}, node_value), do: true
  defp e(tree_node, node_value) do
    if node_value < tree_node.value do
      e tree_node.left, node_value
    else
      e tree_node.right, node_value
    end
  end

  def how_many?(tree, node_value) do
    d tree, node_value, 0
  end

  defp d(:leaf, _, count), do: count
  defp d(tree_node, node_value, count) do
    if node_value < tree_node.value do
      d tree_node.left, node_value, count
    else
      if node_value == tree_node.value do
        d tree_node.right, node_value, count + 1
      else
        d tree_node.right, node_value, count
      end
    end
  end
end
