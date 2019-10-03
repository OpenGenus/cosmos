defmodule Queue do
  def init, do: loop([])
  def loop(queue) do
    receive do
      {:enqueue, {sender_pid, item}} ->
        queue = enqueue(queue, item)
        send sender_pid, {:ok, item}
        loop(queue)
      {:queue_next, {sender_pid}} ->
        {queue, next} = queue_next(queue)
        send sender_pid, {:ok, next}
        loop(queue)
      {:is_empty, {sender_pid}} ->
        is_empty = is_empty(queue)
        send sender_pid, {:ok, is_empty}
        loop(queue)
      {:size, {sender_pid}} ->
        size = size(queue)
        send sender_pid, {:ok, size}
        loop(queue)
      {:first_item, {sender_pid}} ->
        first_item = first_item(queue)
        send sender_pid, {:ok, first_item}
        loop(queue)
      {:last_item, {sender_pid}} ->
        last_item = last_item(queue)
        send sender_pid, {:ok, last_item}
        loop(queue)
      _ -> 
        IO.puts "Invalid message"
    end
  end

  def enqueue(queue, item) do
    queue = queue ++ [item]
    queue
  end

  def queue_next([head | tail]) do
    {tail, head}
  end

  def is_empty(queue) do
    if queue |> length === 0 do true end
    false
  end

  def size(queue) do
    queue |> length
  end
  
  def first_item([head | _]) do
    head
  end

  def last_item(queue) do
    queue |> List.last
  end
end

defmodule RunQueue do
  def initialize_queue do
    queue = spawn(Queue, :init, [])
    send queue, {:enqueue, {self(), "hello"}}
    send queue, {:size, {self()}}
    send queue, {:enqueue, {self(), "message"}}
    send queue, {:queue_next, {self()}}
    send queue, {:enqueue, {self(), "another"}}
    send queue, {:is_empty, {self()}}
    send queue, {:first_item, {self()}}
    send queue, {:last_item, {self()}}
    manage()
  end

  def manage do
    receive do
      {:ok, message} ->
        IO.puts message
      _ ->
        IO.puts "Invalid message"
    end
    manage()
  end
end

RunQueue.initialize_queue