# Part of Cosmos by OpenGenus Foundation
class Node
	attr_accessor :data
	attr_accessor :next

	def initialize(data)
		@data = data
		@next = nil
	end
end

class LinkedList
	attr_reader :size

	def initialize
		@head = nil
		@size = 0
	end

	# Add a new node at end of linked list
	def add!(data)
		if @head.nil? then
			@head = Node.new(data)
		else
			current_node = @head
			until current_node.next.nil? do
				current_node = current_node.next
			end
			current_node.next = Node.new(data)
		end
		@size += 1
		return nil
	end

	# Insert a new node at index
	def insert!(index, data)
		# If index is not in list yet, just assume add at end
		if index >= @size then
			return self.add!(data)
		end
		current_node = @head
		prev_node = nil
		current_index = 0
		until current_node.nil? do
			if index == current_index then
				new_node = Node.new(data)
				new_node.next = current_node
				if current_node == @head then
					@head = new_node
				else
					prev_node.next = new_node
				end
			end
			current_index += 1
			prev_node = current_node
			current_node = current_node.next
		end
		@size += 1
		return nil
	end

	# Get node at index
	def get(index)
		current_index = 0
		current_node = @head
		until current_node.nil? do
			return current_node.data if index == current_index
			current_index += 1
			current_node = current_node.next
		end
		return nil
	end

	# Return node at index
	def remove!(index)
		current_index = 0
		current_node = @head
		prev_node = nil
		until current_node.nil? do
			if index == current_index then
				if current_node == @head then
					@head = current_node.next
				else
					prev_node.next = current_node.next
				end
				# We probably don't want to have the next node when returning the deleted node
				current_node.next = nil
				return current_node
			end
			current_index += 1
			prev_node = current_node
			current_node = current_node.next
		end
		return nil
	end

	# Return list as a string
	def to_s
		current_node = @head
		as_str = ""
		until current_node.nil? do
			unless current_node == @head then
				as_str << " -> "
			end
			as_str << current_node.data.to_s
			current_node = current_node.next
		end
		return as_str
	end
end
