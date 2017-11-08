#!/usr/bin/env ruby
# Part of Cosmos by OpenGenus Foundation

class GameOfLife
  attr_accessor :board

  def initialize(board = [])
    self.board = board.empty? ? Array.new(rand(1..10)) { Array.new(rand(1..10), rand(0..1)) } : board
  end

  def play(turns = 1)
    for turn in 1..turns
      next_board = Array.new(board.size) { Array.new(board.first.size, 0) }
      next_board.each_index do |row|
        next_board[row].each_index { |col| next_board[row][col] = next_state(row, col) }
      end
      self.board = next_board
      pretty_print
    end
  end

  def pretty_print
    board.each do |row|
      puts row.join(' ')
    end
    puts '**' * board.size
  end

  private

  def next_state(row, col)
    alive = count_alive_neighbors(row, col)
    return 1 if (alive > 1) && (alive < 4) && (board[row][col] == 1)
    return 1 if (alive == 3) && (board[row][col] == 0)
    0
  end

  def count_alive_neighbors(row, col)
    neighbors = 0
    for i in -1..1
      for j in -1..1
        next if (i == 0) && (j == 0)
        neighbors += 1 if alive_neighbor?(row + i, col + j)
      end
    end
    neighbors
  end

  def alive_neighbor?(row, col)
    (row >= 0) && (row < board.size) && (col >= 0) && (col < board.first.size) && (board[row][col] == 1)
  end
end

board = [[0, 0, 0], [1, 1, 1], [0, 0, 0]]
game = GameOfLife.new(board)
game.pretty_print
game.play(3)
