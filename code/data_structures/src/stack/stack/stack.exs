defmodule Cosmos.DataStructures.Stack.Stack do
  @moduledoc """
  An implementation of the Stack data structure with lists.
  """

  defstruct size: 0, stack: []

  @opaque t(a) :: %__MODULE__{size: non_neg_integer, stack: list(a)}
  @opaque t :: t(any)

  @doc """
  Returns a new empty stack.

  ## Example

      iex> new()
      #Stack<[]>
  """
  @spec new() :: t

  def new, do: %__MODULE__{}

  @doc """
  Returns a stack created from a given list. It does assume, that the item at
  the front of the list is the youngest.

  ## Parameter

  * `list`: The list that shall get converted into the stack.

  ## Example

      iex> new() === from_list([])
      true

      iex> from_list([1,2,3])
      #Stack<[1, 2, 3]>
  """

  @spec from_list(list(a)) :: t(a) when a: var

  def from_list(list), do: %__MODULE__{size: length(list), stack: list}

  @doc """
  Return the stack with the given element pushed into it.

  ## Parameter

  * `stack`: The stack to push onto.
  * `element`: The element you want to push.

  ## Example

      iex> a = new() |> push(0)
      #Stack<[0]>
      iex> a |> push(1)
      #Stack<[1, 0]>

      iex> from_list([4,3,2,1]) |> push(0)
      #Stack<[0, 4, 3, 2, 1]>
  """
  @spec push(t(a), a) :: t(a) when a: var

  def push(stack, element)
  def push(stack = %__MODULE__{size: s, stack: list}, e) do
    %{stack | size: s + 1, stack: [e|list]}
  end

  @doc """
  Pops the top element from the stack returning a tuple with the format
  `{popped_element, new_stack}

  ## Parameter

  * `stack`: The stack to pop from.

  ## Example

      iex> new() |> pop
      nil

      iex> new() |> push(1) |> pop |> inspect
      "{1, #Stack<[]>}"
  """
  @spec pop(t(a)) :: {a, t(a)} | nil when a: var

  def pop(%__MODULE__{size: 0, stack: []}), do: nil
  def pop(stack = %__MODULE__{size: s, stack: [head | tail]}) do
    {head, %{stack | size: s - 1, stack: tail}}
  end

  @doc """
  Deletes the top element from the stack.

  ## Parameter

  * `stack`: The stack you want to delete the top-element from.

  ## Example

      iex> new() |> delete
      nil

      iex> [1,2,3] |> from_list |> delete
      #Stack<[2, 3]>
  """
  @spec delete(t(a)) :: t(a) | nil when a: var

  def delete(stack = %__MODULE__{}) do
    case pop(stack) do
      {_, result} -> result
      nil         -> nil
    end
  end

  @doc """
  Returns true if the stack is empty or false otherwise.

  ## Parameter

  * `stack`: The stack you want to check emptyness.

  ## Example

      iex> new() |> push(1) |> empty?
      false

      iex> new() |> empty?
      true

      iex> new() |> push(1) |> delete |> empty?
      true
  """
  @spec empty?(t) :: boolean

  def empty?(%__MODULE__{size: 0, stack: []}), do: true
  def empty?(%__MODULE__{}), do: false

  @doc """
  Returns the top element from the stack without removing it. If the stack
  is empty returns nil.

  ## Parameter

  * `stack`: The stack you want to inspect.

  ## Example

      iex> new() |> top
      nil

      iex> new() |> push(1) |> top
      1
  """
  @spec top(t(a)) :: a | nil when a: var

  def top(stack = %__MODULE__{}) do
    case pop(stack) do
      {result, _} -> result
      nil         -> nil
    end
  end

  @doc """
  Returns the maximum element in the stack using Elixir's built-in hierarchy.
  """
  @spec max(t(a)) :: a | nil when a: var

  def max(%__MODULE__{stack: list}), do: minmax(list, &Enum.max/1)

  @doc """
  Returns the minimum element in the stack using Elixir's built-in hierarchy.
  """
  @spec min(t(a)) :: a | nil when a: var

  def min(%__MODULE__{stack: list}), do: minmax(list, &Enum.min/1)

  defp minmax([], _fun), do: nil
  defp minmax(list, fun), do: fun.(list)

  @doc """
  Given a stack and an element, returns true if the element is a member
  of the stack or false otherwise. Compares the elements using a match.

  ## Parameter

  * `stack`: The actual stack that shall be inspected.
  * `needle`: The thing you want to find inside the `stack`.

  ## Example

      iex> member?(new(), 0)
      false

      iex> member?(from_list([1,2,3]), 2.0)
      false

      iex> member?(from_list([?a, ?b, ?c]), ?b)
      true
  """
  @spec member?(t(a), a) :: boolean when a: var

  def member?(stack, needle)
  def member?(%__MODULE__{stack: list}, e) do
    Enum.member? list, e
  end

  @doc """
  Returns the position in the stack of a given element. Returns `nil` if the
  element is not present. If the element appears more than once, then the
  first occurrence is considered. Compares the elements using a match.

  ## Parameter

  * `stack`: The actual stack that shall be inspected.
  * `needle`: The thing you want to find inside the `stack`

  ## Example

      iex> position(new(), 0)
      nil

      iex> position(from_list([1,2,3]), 2.0)
      nil

      iex> position(from_list([?a, ?b, ?c]), ?b)
      1
  """
  @spec position(t(a), a) :: non_neg_integer | nil when a: var

  def position(stack, needle)
  def position(%__MODULE__{stack: list}, e) do
    list |> Enum.find_index(&(&1 === e))
  end

  @doc """
  Given a stack and an element returns true if element appears more than
  once in the stack or false otherwise. Compares the elements using a match!

  ## Parameter

  * `stack`: The actual stack that shall be inspected.
  * `needle`: The thing you want to find inside the `stack`.

  ## Example

      iex> more_than_once(new(), 0)
      false

      iex> more_than_once(from_list([1,2,3,1]), 1)
      true

      iex> more_than_once(from_list([1, 1.0]), 1.0)
      false
  """
  @spec more_than_once(t(a), a) :: boolean when a: var

  def more_than_once(stack, needle)
  def more_than_once(%__MODULE__{stack: stack}, needle), do: mto stack, needle, 0

  defp mto([], _, _), do: false
  defp mto([elem|_tail], elem, 1), do: true
  defp mto([elem|tail], elem, 0), do: mto(tail, elem, 1)
  defp mto([_head|tail], elem, c), do: mto(tail, elem, c)

  @doc """
  Returns the size of the stack.
  """
  @spec size(t) :: non_neg_integer()

  def size(%__MODULE__{size: s}), do: s
end

defimpl Inspect, for: Exads.DataStructures.Stack do
  import Inspect.Algebra

  alias Exads.DataStructures.Stack

  def inspect(%Stack{stack: stack}, opts) do
    concat ["#Stack<", to_doc(stack, opts), ">"]
  end
end
