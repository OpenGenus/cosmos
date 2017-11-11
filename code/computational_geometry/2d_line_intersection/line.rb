class LineInterserction
  def initialize(x1, y1, x2, y2, x3, y3, x4, y4)
    @x1 = x1
    @x2 = x2
    @x3 = x3
    @y1 = y1
    @y2 = y2
    @y3 = y3
    @x4 = x4
    @y4 = y4
    @denom = ((@x1 - @x2) * (@y3 - @y4)) - ((@y1 - @y2) * (@x3 - @x4))
  end

  def is_parallel
    @denom == 0
  end

  def intersection_point
    p1 = ((@x1 * @y2 - @y1 * @x2) * (@x3 - @x4) - (@x1 - @x2) * (@x3 * @y4 - @y3 * @x4)) / @denom
    p2 =  ((@x1 * @y2 - @y1 * @x2) * (@y3 - @y4) - (@y1 - @y2) * (@x3 * @y4 - @y3 * @x4)) / @denom
    "#{p1},#{p2}"
  end
end

obj = LineInterserction.new(10, 3, 20, 3, 10, 5, 20, 5) #=> Cordinate points (x1,y1,x2,y2,x3,y3,x4,y4)
if obj.is_parallel == false
  puts "Intersection Point: #{obj.intersection_point}"
else
  puts "Line Parallel : #{obj.is_parallel}"
end
