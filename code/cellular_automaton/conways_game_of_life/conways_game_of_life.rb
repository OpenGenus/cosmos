# Part of Cosmos by OpenGenus Foundation
class GameOfLife
  attr_accessor :matrix, :rows, :columns

  def initialize(rows, columns)
    @rows = rows
    @columns = columns
    @matrix = []
    rows.times do |row|
      @matrix[row] ||= []
      columns.times do |column|
        @matrix[row][column] = false
      end
    end
  end

  def next_tick
    new_matrix = []
    rows.times do |row|
      new_matrix[row] ||= []
      columns.times do |column|
        alive_neighbours_count = neighbours(row, column).count(true)
        if !matrix[row][column] && alive_neighbours_count == 3
          new_matrix[row][column] = true
        elsif matrix[row][column] && alive_neighbours_count != 2 && alive_neighbours_count != 3
          new_matrix[row][column] = false
        else
          new_matrix[row][column] = matrix[row][column]
        end
      end
    end
    self.matrix = new_matrix
  end

  def print_cells
    rows.times do |row|
      columns.times do |column|
        matrix[row][column] ? print('O') : print('-')
      end
      print "\n"
    end
    print "\n"
  end

  def neighbours(row, column)
    neighbours = []
    rows_limit = matrix.count - 1
    columns_limit = matrix[0].count - 1
    ([0, row - 1].max..[rows_limit, row + 1].min).to_a.each do |row_index|
      ([0, column - 1].max..[columns_limit, column + 1].min).to_a.each do |column_index|
        neighbours << matrix[row_index][column_index] unless row_index == row && column_index == column
      end
    end
    neighbours
  end
end

game = GameOfLife.new(100, 100)

game.matrix[0][0] = true
game.matrix[0][1] = true
game.matrix[1][0] = true
game.matrix[1][2] = true
game.matrix[2][1] = true
game.matrix[2][2] = true

game.print_cells

5.times do
  game.next_tick
  game.print_cells
end
