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
	attr_accessor :head

	def initialize
		@head = nil
	end

	# Return the number of elements in the linked list
	def size
		current_node = @head
		length = 0
		until current_node.nil? do
			length += 1
			current_node = current_node.next
		end
		return length
	end

	# Insert a new node at end of linked list
	def insert!(data)
		if @head.nil? then
			@head = Node.new(data)
		else
			curr_node = @head
			until curr_node.next.nil? do
				curr_node = curr_node.next
			end
			curr_node.next = Node.new(data)
		end
		return nil
	end

	# Get node at index
	def get(index)
		curr_ind = 0
		current_node = @head
		until current_node.nil? do
			return current_node.data if index == curr_ind
			curr_ind += 1
			current_node = current_node.next
		end
		return nil
	end

	# Return node at index
	def remove!(index)
		curr_ind = 0
		current_node = @head
		prev_node = nil
		until current_node.nil? do
			if index == curr_ind then
				if current_node == @head then
					@head = current_node.next
				else
					prev_node.next = current_node.next
				end
				# We probably don't want to have the next node when returning the deleted node
				current_node.next = nil
				return current_node
			end
			curr_ind += 1
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
