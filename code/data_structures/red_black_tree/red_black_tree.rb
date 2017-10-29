class Node
	attr_accessor :data, :color, :left, :right, :parent

	def initialize(data)
		@data = data
		@color = "red"
		@left = nil
		@right = nil
		@parent = nil
	end

	def isSingle()
		return @left == nil && @right == nil
	end

	def addChildLeft(node)
		@left = node
		node.parent = self
	end

	def addChildRight(node)
		@right = node
		node.parent = self
	end

	def grandparent()
		if @parent == nil
			return nil
		end
		return @parent.parent
	end

	def sibling()
		if @parent == nil
			return nil
		elsif @parent.left == self
			return @parent.right
		else
			return @parent.left
		end
	end

	def uncle()
		if @parent == nil or @parent.parent == nil
			return nil
		else
			return @parent.sibling()
		end
	end

	def rotateLeft()
		tmp = self.right
		self.right = tmp.left
		tmp.left = self
		tmp.parent = self.parent
		if self.parent.left == self
			self.parent.left = tmp
		else
			self.parent.right = tmp
		end
		self.parent = tmp
	end

	def rotateRight()
		tmp = self.left
		self.left = tmp.right
		tmp.right = self
		tmp.parent = self.parent
		if self.parent.left == self
			self.parent.left = tmp
		else
			self.parent.right = tmp
		end
		self.parent = tmp
	end
end

class RedBlackTree
	attr_accessor :head
	def initialize()
		@head = nil
	end

	def insert(value)
		tmp = Node.new(value)

		if @head == nil
			@head = tmp
		else
			current = @head
			while current != nil
				if value < current.data
					if current.left != nil
						current = current.left
					else
						current.left = tmp
						break
					end
				elsif value > current.data
					if current.right != nil
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
		self.insert_repair(tmp)
	end

	def insert_repair(node)
		uncle = node.uncle()
		grandparent = node.grandparent()

		if node.parent == nil
			node.color = "black"
		elsif node.parent.color == "black"
			return
		elsif uncle != nil and uncle.color == "red"
			node.parent.parent.color = "red"
			node.parent.color = "black"
			uncle.color = "black"
			self.insert_repair(node.parent.parent)
		elsif uncle == nil or uncle.color == "black"
			if node == grandparent.left.right
				self.rotateLeft(node.parent)
				node = node.left
			elsif node == grandparent.right.left
				self.rotateRight(node.parent)
				node = node.right
			end

			if node.parent.left == node
				self.rotateRight(grandparent)
			else
				self.rotateLeft(grandparent)
			end
			node.parent.color = "black"
			node.grandparent().color = "red"
		end
	end

	def search(value)
		current = self.head
		while current != nil
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
