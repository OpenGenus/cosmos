class Array

	def in_order?
		self.each_cons(2).all?{ |i,j| i <= j }
	end
	
	def bogosort
		self.shuffle! until self.in_order?
		self
	end

end

p [5, 2, 3, 4, 1].bogosort
